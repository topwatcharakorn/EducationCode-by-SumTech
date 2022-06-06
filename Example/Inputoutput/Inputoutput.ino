//Example Code EP 5: Input Switch&Output LED
// Summation Technology

#define led1 = 27;
#define led2 = 10;
#define led3 = 11;

int buttonPin = 25;
int buttonState = 0;
void setup()
{

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(buttonPin, INPUT);
  digitalWrite(led1, HIGH);

}
void loop()
{
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
    digitalWrite(led1, LOW);
  }
  else {
    digitalWrite(led1, HIGH);
  }
}

void led() {
  for (int x = 9; x < 11; x++) {
    digitalWrite(x, LOW);
    delay(100);
  }
  for (int x = 9; x < 11; x++) {
    digitalWrite(x, LOW);
    delay(100);
  }

}
