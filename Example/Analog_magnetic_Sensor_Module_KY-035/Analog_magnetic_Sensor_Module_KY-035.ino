//Example Code EP 17:Analog magnetic Sensor Module KY-035
// Summation Technology 

int sensorPin=A5;
int ledPin=13;
int sensorValue=0;

void setup{
  pinMode(Led,OUTPUT);
 Serial.begin(9600);
}
void loop{

  sensorValue = analogRead(sensorPin);
    digitalWrite(ledPin,HIGH);
    delay(sensorValue);
    digitalWrite(ledPin,LOW);
    delay(sensorValue);
    Serial.println(sensorValue,DEC);
  
}
