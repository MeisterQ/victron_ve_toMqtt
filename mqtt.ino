void mqttconnect()
{
  while (!client.connected())
  {
    Serial.print("MQTT connecting ...");
    String clientId = "Victron";

    //if (client.connect(clientId.c_str(), mqttUser, mqttPass)) // Uncomment to use user and pass
    if (client.connect(clientId.c_str())) // Uncomment to use without user and pass
    {
      Serial.println("connected");
    }
  }
}
