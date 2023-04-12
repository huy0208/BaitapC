#include <SPI.h>

const int slaveSelectPin = 10; // Chân SS của board Master

void setup() {
  Serial.begin(9600); // Khởi tạo Serial để ghi lại các sự kiện
  SPI.begin(); // Khởi tạo giao thức SPI
  pinMode(slaveSelectPin, OUTPUT); // Chỉ định chân SS là đầu ra
  digitalWrite(slaveSelectPin, HIGH); // Chọn Slave
}

void loop() {
  // Chọn Slave
  digitalWrite(slaveSelectPin, LOW);

  // Gửi dữ liệu đến Slave
  byte data = 0x55;
  SPI.transfer(data);

  // Ngừng giao tiếp với Slave
  digitalWrite(slaveSelectPin, HIGH);

  // Chờ một chút trước khi gửi lệnh tiếp theo
  delay(1000);
}
