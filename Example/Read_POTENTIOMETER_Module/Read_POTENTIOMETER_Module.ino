//Example Code EP 20:Read POTENTIOMETER Module
// Summation Technology 

#define POTENTIOMETER_PIN A0
void setup() 
{
  Serial.begin(9600);
}
void loop()
{
  int data = analogRead(POTENTIOMETER_PIN);
  int percentage = map(data, 0, 1023, 0, 100);
  Serial.print("Potentiometer at ");
  Serial.print(percentage);
  Serial.println("%");
  delay(100);
}
