//Example Code EP 18: Control Relay Module
// Summation Technology 

int Relay1 = 27; 
void setup()
{
pinMode(Relay1, OUTPUT);
digitalWrite(Relay1, HIGH);
}
void loop()
{
digitalWrite(Relay1, LOW); 
delay(1000); 
digitalWrite(Relay1, HIGH); 
delay(1000); 
}
