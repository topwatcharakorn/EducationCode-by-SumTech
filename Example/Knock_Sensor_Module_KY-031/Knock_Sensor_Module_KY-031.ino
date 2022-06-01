//Example Code EP 15:Knock Sensor Module KY-031
// Summation Technology 

int Led=13;
int Shock=3;
int val;
void setup{
  pinMode(Led,OUTPUT);
  pinMode(Led,INPUT);
}
void loop{

  val = digitalRead(Shock);
  if(val==HIGH){
    digitalWrite(Led,LOW);
  }
  else
  {
      digitalWrite(Led,HIGH);
  }
}
