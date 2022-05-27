//Example Code EP 11: Mercury Switch Module KY-017
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
