//Example Code EP 21:TEST INPUT RELAY
// Summation Technology 



#define ON HIGH
#define OFF LOW

void setup() {
  
  pinMode(36, INPUT);                      // กำหนดพิน 0-3 เป็น INPUT (X1-X4) 
  pinMode(13, OUTPUT);                    // กำหนดพิน 8-11 (รีเลย์ 1-4) เป็น OUTPUT
  digitalWrite(13, HIGH);                  // สั่งค่าเริ่มต้น OUTPUT 8-11 (รีเลย์ 1-4) ให้มีสถานะเป็น HIGH (OFF)

 pinMode(35, INPUT);                      // กำหนดพิน 0-3 เป็น INPUT (X1-X4) 
  pinMode(15, OUTPUT);                   // กำหนดพิน 8-11 (รีเลย์ 1-4) เป็น OUTPUT
  digitalWrite(15, HIGH);                  // สั่งค่าเริ่มต้น OUTPUT 8-11 (รีเลย์ 1-4) ให้มีสถานะเป็น HIGH (OFF)
}

void loop() {
  IN_OUT_CONTROL();                           // เรียกใช้งานฟังก์ชั่น IN_OUT_CONTROL
}


void IN_OUT_CONTROL() {
  if (digitalRead(36) == LOW) {            // หากมี INPUT X1 (LOW: เอาขั้ว INPUT ลงกราวด์ GND) เข้ามา
    digitalWrite(13, ON);                  // จะสั่งให้รีเลย์ตัวที่ 1 (RELAY1) ON
    Serial.println("X1 Active");
  } else {
    digitalWrite(13, OFF);                  // จะสั่งให้รีเลย์ตัวที่ 1 (RELAY1) OFF
    Serial.println("X1 NOT Active");
  }
   if (digitalRead(35) == LOW) {            // หากมี INPUT X1 (LOW: เอาขั้ว INPUT ลงกราวด์ GND) เข้ามา
    digitalWrite(15, ON);                 // จะสั่งให้รีเลย์ตัวที่ 1 (RELAY1) ON
    Serial.println("X1 Active");
  } else {
    digitalWrite(15, OFF);                  // จะสั่งให้รีเลย์ตัวที่ 1 (RELAY1) OFF
    Serial.println("X1 NOT Active");
  }
  

}
