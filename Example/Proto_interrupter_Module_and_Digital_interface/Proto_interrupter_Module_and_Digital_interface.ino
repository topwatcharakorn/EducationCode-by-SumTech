//Example Code EP 9: Proto interrupter Module and Digital interface
// Summation Technology 

int Led = 13;
int buttonpin =3;
int val ;
void setup() 
{
  pinMode(Led, OUTPUT); 
  pinMode(Led, INPUT); 

}
 
void loop() 
{
  val=digitalRead(buttonpin);
  val if(val==HIGH)
  digitalWrite(Led,HIGH);
  else
  digitalWrite(Led,LOW);
}