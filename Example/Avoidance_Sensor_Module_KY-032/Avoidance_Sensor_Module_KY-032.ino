//Example Code EP 16:Avoidance Sensor Module KY-032
// Summation Technology 

int Led=13;
int buttonpin=3;
int val;

void setup{
  pinMode(Led,OUTPUT);
  pinMode(buttonpin,INPUT);
}
void loop{

  val = digitalRead(buttonpin);
  if(val==HIGH){
    digitalWrite(Led,LOW);
  }
  else
  {
      digitalWrite(Led,HIGH);
  }
}
