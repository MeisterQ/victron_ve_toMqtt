// Created by MeisterQ 13.01.2023
// V0.1

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
#include <ArduinoOTA.h>             // OTA Library
#include <PubSubClient.h>           // MQTT Library
#include <SoftwareSerial.h>
#include <credentials.h>

SoftwareSerial swSer(D6, D7);


/*
  ------------------------ Mosquitto --------------------------
*/

const char* mqtt_server = mqttServer;                        // MQTT Server IP

WiFiClient espClient;                                             // WiFi client
PubSubClient client(espClient);                                   // Client für MQTT

/* topics */
#define ACT_VPV_TOPIC             "Solar/Victron/act/vpv"
#define ACT_PID_TOPIC             "Solar/Victron/act/pid"
#define ACT_V_TOPIC               "Solar/Victron/act/v"
#define ACT_I_TOPIC               "Solar/Victron/act/i"
#define ACT_PPV_TOPIC             "Solar/Victron/act/ppv"
#define ACT_CS_TOPIC              "Solar/Victron/act/cs"
#define ACT_H19_TOPIC             "Solar/Victron/act/h19"
#define ACT_H20_TOPIC             "Solar/Victron/act/h20"
#define ACT_H21_TOPIC             "Solar/Victron/act/h21"
#define ACT_H22_TOPIC             "Solar/Victron/act/h22"
#define ACT_H23_TOPIC             "Solar/Victron/act/h23"
#define STATE_DEBUG_TOPIC         "Solar/Victron/debug/debug"



/*
  ---------------------- WLan Einstellungen ------------------
*/

const char* ssid = wifiName;                    // WLan Name
const char* password = wifiPass;            // WLan Passwort

IPAddress ip(192, 168, 10, 106);                   // IP mit der sich der ESP in das Netzwerk verbinden soll
IPAddress gateway(192, 168, 10, 1);                // Gateway des Netzwerks
IPAddress subnet(255, 255, 255, 0);               // Subnetmask
IPAddress dns(192, 168, 10, 1);

/*
  ---------------------- Variablen ----------------------
*/

String data;
int vpv;
int batteryV;
int current;
int ppv;
byte cs;
int H19;
int H20;
int H21;
int H22;
int H23;

char vpvMSG[10];
char pidMSG[10];
char vMSG[10];
char iMSG[10];
char ppvMSG[10];
char csMSG[10];
char h19MSG[10];
char h20MSG[10];
char h21MSG[10];
char h22MSG[10];
char h23MSG[10];

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


unsigned long previousMillis = 0;
const long interval = 5000;

void setup()
{
  Serial.begin(115200);
  swSer.begin(19200);
  wifiSettings();
  mqttSettings();                 // MQTT Konfigurieren
  OTAsettings();                  // OTA Konfigurieren
  mqttconnect();                  // MQTT-Verbindung aufbauen

  client.publish(STATE_DEBUG_TOPIC, "Setup Done");    // Nachricht an MQTT-Server schicken
}

void loop()
{
  ArduinoOTA.handle();            // OTA Handle
  mqttHandle();                   // Sende Daten an MQTT Server
  getData();
  sendMQTT();
}
