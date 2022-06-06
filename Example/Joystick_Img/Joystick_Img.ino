#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

const uint8_t PROGMEM batman[] = {
B10000000,B00000000,
B11000000,B00000000,
B11100000,B00000000,
B11110000,B00000000,
B11111000,B00000000,
B11111100,B00000000,
B11111110,B00000000,
B11111111,B00000000,
B11111111,B10000000,
B11111111,B11000000,
B11111111,B11100000,
B11111111,B11110000,
B11111111,B11111000,
B11111111,B11111100,
B11111111,B11111110,
B11111111,B11111111,
B11111110,B00000000,
B11111100,B00000000,
B11111000,B00000000,
B11110000,B00000000,
B11100000,B00000000,
B11000000,B00000000,
B10000000,B00000000,
};

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library.
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define X 33
int XValue = 0;
#define Y 34
int YValue = 0;
#define SW 23
int SWValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(SW, INPUT_PULLUP);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  display.clearDisplay();
}
boolean SW_F = 0;
void loop() {
  display.clearDisplay();
  XValue = map(analogRead(X), 0, 4095, 0, 127);
  YValue = map(analogRead(Y), 0, 4095, 0, 63);
  //SWValue = analogRead(SW);
//  Serial.print("XValue: ");
//  Serial.print(XValue);
//  Serial.print("\t");
//  Serial.print("YValue: ");
//  Serial.print(YValue);
//  Serial.print("\t");
//  Serial.print("SWValue: ");
//  Serial.println(SWValue);
  get_sw();
  //display.drawPixel(XValue, YValue, SSD1306_WHITE);
  //display.fillCircle(XValue, YValue, 2, 2);
  display.drawBitmap(XValue, YValue, batman, 16, 23, WHITE);
  //delay(50);
  display.display();
}

void get_sw() {
  if (digitalRead(SW) == LOW) {
    display.clearDisplay();
  }
  //Serial.println(digitalRead(SW));
}
