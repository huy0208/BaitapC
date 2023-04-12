
/*
 * File: MasterSPI.ino
 * Author: Huynh Huy
 * Date: 11/4/2023
 * Description: Mô phỏng quá trình truyền nhận dữ liệu của Master
 */

#include <Arduino.h>
#include <SPI.h>

#define push 2

#define LED 4

#define SCK_PIN 13 // chân sck

#define MISO_PIN 12 // chân miso

#define MOSI_PIN 11 // chân mosi

#define SS_PIN 10 // chân ss

int x;

int value;

void setup() {

  Serial.begin(115200);// tốc độ baus

  pinMode(push, INPUT);// chân push khai báo là chân đầu vào

  pinMode(LED, OUTPUT);// chân led khai báo là chân đầu ra

  SPI.begin();

  SPI.setClockDivider(SPI_CLOCK_DIV8);
  
  digitalWrite(SS_PIN, HIGH); // Đặt mức cao để dừng giao tiếp nếu đã thực hiện

}
// Gửi và nhận lệnh
void loop() {
  
  byte m_send;
  byte m_receive;

  value = digitalRead(push);

  if(value == HIGH){

    x = 1;
    
  }
  else{

    x = 0;

  }

  digitalWrite(SS_PIN, LOW);

  m_send = x;

  m_receive = SPI.transfer(m_send);

  if (m_receive == 1){

    digitalWrite(LED,HIGH);

  }
  else{

    digitalWrite(LED,LOW);

  }
  delay(500);
}
