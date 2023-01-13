// Created by MeisterQ 13.01.2023
// V00.01.01

// Victron MPPT 150 / 35
// Smart Solar charge controller


// Message format <Newline><Field-Label><Tab><Field-Value>

// V (mV)   Main Battery Voltage
// VPV (mV) Panel voltage
// PPV (W)  Panel power
// I (mA)   Battery current
// RELAY    Relay state
// H19      (0.01 kWh) Yield total
// H20      (0.01 kWh) Yield today
// H21      (W) Maximum power today
// H22      (0.01 kWh) Yield yesterday
// H23      (W) Maximum power yesterday
// ERR      Error code
// CS       State of operation
// FW       Firmware version
// PID      Product ID
// Ser#     Serial number
// HSDS     Day sequence number (0...364)

// State of operations
// 0 OFF
// 2 FAULT
// 3 BULK
// 4 Absorption
// 5 Float

// Errorlist
// 0    No error
// 2    Battery voltage too high
// 17   Charger temperature too high
// 18   Charger over current
// 19   Charger current reversed
// 20   Bulk time limit exceeded
// 21   Current sensor issue
// 26   Terminals overheated
// 33   Input voltage too high (solar panel)
// 34   Input current too high (solar panel)
// 38   Input shutdown (due to excessive battery voltage)
// 116  Factory calibration data lost
// 117  Invalid / incompatible firmware
// 119  User settings invalid


#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
#include <ArduinoOTA.h>
#include <PubSubClient.h>
#include <SoftwareSerial.h>
#include <credentials.h>
#include <ArduinoJson.h>

SoftwareSerial swSer(D6, D7);


/*
  ------------------------ Mosquitto --------------------------
*/

const char* mqtt_server = mqttServer;

WiFiClient espClient;
PubSubClient client(espClient);

/* topics */
#define ACT_DATA_TOPIC            "Solar/Victron/act/data"
#define STATE_DEBUG_TOPIC         "Solar/Victron/debug/debug"
#define STATE_WATCHDOG_TOPIC      "Solar/Victron/state/watchdog"



/*
  ---------------------- Wifi settings ------------------
*/

const char* ssid = wifiName;
const char* password = wifiPass;

IPAddress ip(192, 168, 1, 1);       // Change IP if you use fixed IP!!
IPAddress gateway(192, 168, 1, 1);  // Change IP if you use fixed IP!!
IPAddress subnet(192, 168, 1, 1);   // Change IP if you use fixed IP!!
IPAddress dns(192, 168, 1, 1);      // Change IP if you use fixed IP!!

/*
  ---------------------- Variables ----------------------
*/

byte cs;

int vpv;
int batteryV;
int current;
int ppv;
int H19;
int H20;
int H21;
int H22;
int H23;

String data;
String valueVPV;
String valuePID;
String valueV;
String valueI;
String valuePPV;
String valueCS;
String valueH19;
String valueH20;
String valueH21;
String valueH22;
String valueH23;

String mqttUser = "mqttUser"; // Enter MQTT User
String mqttPass = "mqttPass"; // Enter MQTT Password

unsigned long previousMillisWatchdog = 0;
long watchdogTime = 0;
unsigned long previousMillis = 0;
const long interval = 5000;

void setup()
{
  Serial.begin(115200);
  swSer.begin(19200);
  wifiSettings();
  mqttSettings();
  OTAsettings();
  mqttconnect();

  client.publish(STATE_DEBUG_TOPIC, "Setup Done");
}

void loop()
{
  ArduinoOTA.handle();
  mqttHandle();
  getData();
  sendMQTT();
  watchdog(5000);
}
