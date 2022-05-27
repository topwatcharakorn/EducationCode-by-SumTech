//Example Code EP 14:Magic Light Cup Module KY-027
// Summation Technology 

int LedPinA = 5;
int LedPinB = 6;
int ButtonPinA = 7;
int ButtonPinB = 4;
int ButtonStateA = 0;
int ButtonStateB= 0 ; 
int brightness = 0 ;

void setup{
  pinMode(LedPinA,OUTPUT);
  pinMode(LedPinB,OUTPUT);
  pinMode(ButtonPinA,INPUT);
  pinMode(ButtonPinB,INPUT; 
  
}
void loop{
  ButtonStateA = digitalRead(ButtonPinA);
  if(buttonStateA==HIGH&&brightness!=255)
  {
    brightness--;
  }
  analogWrite(LedPinA,brightness);ll A Yuanyuan,ii analogWrite(LedPinB,255-brightness);ll Yuanyuan; 
  delay(200);
  }
