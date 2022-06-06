//Example Code EP 19: Control buzzer Module
// Summation Technology 

#define BUZZER_PIN 27

void setup() {
  pinMode(BUZZER_PIN,OUTPUT);
}

void loop() {
  digitalWrite(BUZZER_PIN,HIGH);   //ปิดเสียงเตือน
  delay(1000);
  digitalWrite(BUZZER_PIN,LOW);    //เปิดเสียงเตือน
  delay(1000);
}
