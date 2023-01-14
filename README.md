# Instructions

Reads data from SmartSolar chargers over SoftwareSerial and sent it to MQTT

Copy all files into one folder and open victron_ve_toMqtt.ino. If you get asked to create a new folder with the same name, say yes.

Arduino IDE will open and show all files in Tabs.

Comment line "#include <credentials.h>", otherwise you will get compiling errors

----------------------------------------------

Edit your Wifi credentials here in victron_ve_toMqtt.ino

const char* ssid = "wifiName";
const char* password = "wifiPass";

If you want to use fixed IP, uncomment #define fixedIP in Wifi settings section

----------------------------------------------


If you want to use MQTT with User and Password, uncomment line #define mqttSecure in Mosquitto section

Edit MQTT Settings below like Port, Client, User and Password


-----------------------------------------------

Choose Wemos D1 mini (or any ESP8266 board) and compile and upload.

It will now read serial data from Victron VE.direct Solar chargecontrollers and send it to the topics.

Connect D6 (RX) and D7 (TX) to TX and RX (crosswise) and GND to GND.

-------------------------------------------

VE.direct connector pinout is from left to right with opening on top.

Victron 	ESP

1. GND	--->	GND 
2. RX	--->	D7
3. TX	--->	D6
4. V+	--->	Only connect with a DCDC Converter to 5V