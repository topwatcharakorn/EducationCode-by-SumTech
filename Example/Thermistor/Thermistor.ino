//Example Code EP 10: Thermistor KY-013
// Summation Technology 

double Thermister(int RawADC)
double Temp;
Temp =log(((10240000/RamADC)-10000));
Temp =1/(0.001129148+(0.000234125+(0.0000000876741*Temp*Temp))*Temp);
Temp =Temp-273.15;
return Temp;
void setup() 
{
  Serial.begin(9600);

}
 
void loop() 
{
Serial.print(Thermister(analogRead(0)));
Serial.print("C");
delay(1000);
}
