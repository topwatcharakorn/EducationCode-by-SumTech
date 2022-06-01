//Example Code EP 19: Control buzzer Module
// Summation Technology 


const int buzzer = 9; 

void setup(){
  pinMode(buzzer, OUTPUT); 
}

void loop(){
  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(1000);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(1000);        // ...for 1sec
}
