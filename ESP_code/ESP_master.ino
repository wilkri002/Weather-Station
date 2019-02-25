#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADS1015.h>
#include <Adafruit_BME280.h>

//WiFi name and password
#define WLAN_SSID   "SSID"
#define WLAN_PASS   "PWD"

Adafruit_ADS1115 ads1115; //initiate ADC
Adafruit_BME280 bme;      //initiate temperature/humidity sensor
WiFiClient client;        //start wifi

// ThingSpeak Settings
const int channelID = 0000000;            //ThingSpeak Channel to send data to
const char * APIKey = "API-key";          //API key for ThingSpeak Channel
const int postingInterval = 3600 * 1000;  // post data every hour

float lightVal;   
int tempVal;
int pressureVal;

void(* resetFunc) (void) = 0;     //resets the ESP

void setup() {
  connectToWifi();   //connect to Wifi
  Wire.begin(0, 2);  //setup i2c for ESP
  ads1115.begin();   //start ASDC
  bme.begin();       //start temperature/pressure sensor
  
  ThingSpeak.begin(client); //Start ThinkSpeak connection
}

void loop() {

  lightVal = readADC(0);            //read light data
  tempVal = bme.readTemperature();  //read temperature data
  pressureVal = bme.readPressure(); //read pressure data

    ThingSpeak.setField(0, lightVal);     //set light data to field 0
    ThingSpeak.setField(1, tempVal);      //set light data to field 1
    ThingSpeak.setField(2, pressureVal);  //set light data to field 2

    ThingSpeak.writeFields(channelID, APIKey); //send data to ThingSpeak

    delay(postingInterval); //wait an hour and record new data

}
