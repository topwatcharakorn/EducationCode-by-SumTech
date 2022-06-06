#include "SHT31.h"
#include <WiFi.h>
#include <Wire.h>
#include <FirebaseESP32.h>

#define WIFI_SSID "sumtech 2.4G"
#define WIFI_PASSWORD "123456aaff"
//#define WIFI_SSID "top'ip"
//#define WIFI_PASSWORD "0632288795"
#define DATABASE_URL "sht31-f73ef-default-rtdb.firebaseio.com"
#define SHT31_ADDRESS 0x44
#define battery_pin 32
#define LED_STATUS 13

#if CONFIG_FREERTOS_UNICORE
#define ARDUINO_RUNNING_CORE 0
#else
#define ARDUINO_RUNNING_CORE 1
#endif

FirebaseData firebaseData;
FirebaseAuth auth;
FirebaseConfig config;
uint32_t start;
uint32_t stop;
SHT31 sht;

void TaskBlink( void *pvParameters );

float t, h;
int batlevel;
void setup()
{

  Serial.begin(115200);
  pinMode(LED_STATUS, OUTPUT);
  Wire.begin();
  sht.begin(SHT31_ADDRESS);
  Wire.setClock(100000);
  uint16_t stat = sht.readStatus();
  Serial.print(stat, HEX);
  Serial.println();

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connect wifi ....");
  while (WiFi.status() != WL_CONNECTED)
  {
    digitalWrite(LED_STATUS, LOW);
    delay(150);
    digitalWrite(LED_STATUS, HIGH);
    delay(150);
    Serial.print(".");

    delay(1500);
  }
  Serial.print("Connect wifi ");
  delay(1500);
  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);
  Serial.println(__FILE__);
  config.database_url = DATABASE_URL;
  config.signer.tokens.legacy_token = "0YBxhXuwrdpX4hDSMWD3ZO3OI7gYO6wjNP7jMbRx";
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
  Firebase.setDoubleDigits(5);

  xTaskCreatePinnedToCore(
    TaskBlink
    ,  "TaskBlink"   // A name just for humans
    ,  1024  // This stack size can be checked & adjusted by reading the Stack Highwater
    ,  NULL
    ,  1  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
    ,  NULL 
    ,  ARDUINO_RUNNING_CORE);
    
}


void loop()
{
  get_Sht31();
  post_get_firebase();
  BatteryLevel();
  //running_status();
}

void get_Sht31()
{
  start = micros();
  sht.read();
  stop = micros();
  t = sht.getTemperature();
  h = sht.getHumidity();
  Serial.println(t);
  Serial.println(h);
}

void post_get_firebase()
{
  Firebase.setFloat(firebaseData, "/test/HUMI", h);
  Firebase.setFloat(firebaseData, "/test/TEM", t);
  Firebase.setFloat(firebaseData, "/test/Batterry", batlevel);
}
int bat = 0;
void BatteryLevel() {
  bat = analogRead(battery_pin);
  batlevel = map(bat, 3218, 4095, 0, 100);
  Serial.print("Raw bat = ");
  Serial.print(bat);
  Serial.print(", Battery = ");
  Serial.print(batlevel);
  Serial.println("%");
}

unsigned long count = 0;
#define time_led 100
void running_status() {
  if (millis() - count >= time_led) {
    digitalWrite(LED_STATUS, LOW);
    delay(50);
    digitalWrite(LED_STATUS, HIGH);
    count = millis();
  }
}
void TaskBlink(void *pvParameters)  // This is a task.
{
  (void) pvParameters;

  for (;;) // A Task shall never return or exit.
  {
    running_status();
    vTaskDelay(10);  // one tick delay (15ms) in between reads for stability
  }
}
