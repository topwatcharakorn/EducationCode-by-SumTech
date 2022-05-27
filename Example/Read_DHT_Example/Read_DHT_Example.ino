//Example Code EP 2: READ DHT 11/22
// Summation Technology 

#include <dht.h>  // INCLUDE Library ของตัว DHT.H


#define dht_apin A0 // กำหนด ขา Analog ของ SENSOR DHT
 
dht DHT;
 
void setup(){
 
  Serial.begin(9600);
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
} 
void loop(){
    DHT.read11(dht_apin);
 
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  "); 
    delay(5000);
}
