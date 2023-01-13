void mqttHandle()
{
  if (!client.connected())
  {
    mqttconnect();
  }
  client.loop();
}

void receivedCallback(char* topic, byte * payload, unsigned int length) {

  Serial.print("Message received: ");
  Serial.println(topic);

  Serial.print("payload: ");

  for (int i = 0; i < length; i++) {

    Serial.print((char)payload[i]);

  }

  Serial.println();

  /*
    // Power On / Off
    if (strcmp((char*)topic, CTRL_SWITCH_TOPIC) == 0)
    {
      ergebnis = 0;
      for (int i = 0; i < length; i++) ergebnis = (ergebnis * 10) + (payload[i] - '0');
      // ergebnis = atoi((const char*)payload);
      setPow = ergebnis;
      node.writeSingleRegister(9, setPow); //set power on !
      Serial.println(ergebnis);
      Serial.println();
    }
  */

}
