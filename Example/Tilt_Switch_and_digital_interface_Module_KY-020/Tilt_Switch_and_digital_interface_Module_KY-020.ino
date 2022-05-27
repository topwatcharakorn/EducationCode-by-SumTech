//Example Code EP 12: Tilt Switch and digital interface Module KY-020
// Summation Technology 
int Led = 13;
int buttonpin = 3;
int val;

void setup() 
{
pinMode(Led,OUTPUT);
pinMode(buttonpin,INPUT);

}
 
void loop() 
{
Val = digitalRead(buttonpin);
if(val==HIGH)
{
  digitalWrite(Led,HIGH);
}
  other
{
digitalWrite(Led,LOW);
}

}
