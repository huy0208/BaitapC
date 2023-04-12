/*
 * File: SlaveSPI
 * Author: Huynh Huy
 * Date: 11/4/2023
 * Description: Mô phỏng quá trình truyền nhận dữ liệu của slave
 */
#include<Arduino.h>
#include<SPI.h>


#define inputbutton 2 // chân I/O
#define outputLED 4  // hien thi du lieu


volatile boolean received;
volatile byte Slavereceived,Slavesend;

int buttonvalue;
int x;

void setup()
{

  Serial.begin(115200); // tốc độ baus
  
  pinMode(inputbutton,INPUT); // Đặt inputbutton làm input

  pinMode(outputLED,OUTPUT);  // Đặt outputLED làm output

  pinMode(MISO,OUTPUT);  // Đặt miso làm output             

  SPCR |= _BV(SPE);// Thiết bị đã được đặt ở chế độ slave       
  received = false;

  SPI.attachInterrupt();  //Kích hoạt ngắt SPI                
  
}

// Quy trình ngắt SPI
ISR (SPI_STC_vect)  //Tiến trình con xử lý ngắt (Interrupt Service Routine - ISR)                      
{
  Slavereceived = SPDR; // Lấy dữ liệu nhận được từ thanh ghi SPDR        
  received = true;                        
}
// Gửi và nhận lệnh
void loop()
{  
  
  if(received)                           
  {
    if (Slavereceived == 1) 
    {
      digitalWrite(outputLED,HIGH);       
    }
    else
    {
      digitalWrite(outputLED,LOW);          
    }
      
    buttonvalue = digitalRead(inputbutton);  
      
    if (buttonvalue == HIGH)           
    {
      x=1;
       
    }
    else
    {
      x=0;
    }
  Slavesend=x;                

  SPDR = Slavesend;          
               
  delay(500);
  }
}
