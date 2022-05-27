//Example Code EP 1: Read DHT22 Show Display O'LED 0.96'
// Summation Technology 


#include <Arduino.h>
#include <U8g2lib.h>
#include "DHT.h"

#define DHTPIN 2     
#define DHTTYPE DHT22   
DHT dht(DHTPIN, DHTTYPE);

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif


  U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void draw(void) {

  float h = dht.readHumidity();

  float t = dht.readTemperature();

  float f = dht.readTemperature(true);

  u8g2.setFont(u8g2_font_helvB10_tf);
  u8g2.setCursor(0, 16);
  u8g2.print("Temp & Humidity");
  u8g2.setFont(u8g2_font_helvB18_tf);
  u8g2.setCursor(0, 42);
  u8g2.print("T= "); u8g2.print(t); u8g2.print(" *C");
  u8g2.setCursor(0, 64);
  u8g2.print("H= "); u8g2.print(h); u8g2.print(" %");
}

void setup(void) {
  
  dht.begin();

  u8g2.begin();  
}

void loop(void) {


  delay(2000);


  float h = dht.readHumidity();

  float t = dht.readTemperature();
  
  u8g2.firstPage();
  do {
    draw();
  } while ( u8g2.nextPage() );
  delay(1000);
}
