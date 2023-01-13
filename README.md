# Instructions

Reads data from SmartSolar chargers over SoftwareSerial and sent it to MQTT

Copy all files into one folder and open any .ino file. 

Arduino IDE will open and show all files in Tabs.

Edit your Wifi and MQTT credentials.

If you want to use fixed IP, comment WiFi.config line in wifi.ino and set IPs in the main program.

Choose Wemos D1 mini (or any ESP8266 board) and compile and upload.

It will now read serial data from Victron VE.direct Solar chargecontrollers and send it to the topics.

You also need to connect D6 (RX) and D7 (TX) to TX and RX (crosswise) and GND to GND. 