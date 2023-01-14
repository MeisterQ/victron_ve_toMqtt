void mqttconnect()
{
  while (!client.connected())
  {
    Serial.print("MQTT connecting ...");
    //String clientId = "Victron";

#ifdef mqttSecure
    if (client.connect(ClientID, MQTTUser, MQTTPass)) // Use this line to communicate with user and password
#else
    if (client.connect(ClientID))           // Use this line to communicate without user and password
#endif
    {
      Serial.println("connected");
    }
  }
}
