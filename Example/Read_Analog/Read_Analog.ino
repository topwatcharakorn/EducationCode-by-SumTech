//Example Code EP 4: Analog Read Potentiometer
// Summation Technology 

int analogPin = ; // กำหนดขา GPIO (Analog) 
                  
int VR = 0;  // กำหนดค่าตัวแปร VR=0

void setup() {
  Serial.begin(9600);           //  setup serial
}

void loop() {
  VR = analogRead(analogPin);  // read the input pin
  Serial.println(VR);          // debug value Potentiometer
}
