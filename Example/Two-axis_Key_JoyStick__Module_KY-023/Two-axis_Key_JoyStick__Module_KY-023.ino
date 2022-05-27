//Example Code EP 13: Two-axis Key JoyStick  Module KY-023
// Summation Technology 

int JoyStick_x=0;
int JoyStick_y=1;
int JoyStick_z=3;

void setup() 
{
pinMode(JoyStick_x,INPUT);

pinMode(JoyStick_y,INPUT);

pinMode(JoyStick_z,INPUT);
Serial.begin(9600);
y=analogRead(JoyStick_y);
z=analogRead(JoyStick_z);

}
 
void loop() 
{
int x,y,z;
Serial.print(x,DEC);
Serial.print(y,DEC);
Serial.print(z,DEC);
}
