void mqttconnect()
{
  while (!client.connected())
  {
    Serial.print("MQTT connecting ...");
    String clientId = "ESP8266_Victron";

    if (client.connect(clientId.c_str()))
    {
      Serial.println("connected");
/*
      client.subscribe(CTRL_SWITCH_TOPIC);
      client.subscribe(CTRL_VOLTAGE_TOPIC);
      client.subscribe(CTRL_CURRENT_TOPIC);
      client.subscribe(CTRL_SYNC_MODE_TOPIC);*/
    }
  }
}
