void sendMQTT()
{
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;
    json();
  }
}


void json()
{
  StaticJsonBuffer<350> JSONbuffer;
  JsonObject& JSONencoder = JSONbuffer.createObject();

  JSONencoder["VPV"] = vpv;
  JSONencoder["VBAT"] = batteryV;
  JSONencoder["CUR"] = current;
  JSONencoder["POWER"] = ppv;
  JSONencoder["CS"] = cs;
  JSONencoder["H19"] = H19;
  JSONencoder["H20"] = H20;
  JSONencoder["H21"] = H21;
  JSONencoder["H22"] = H22;
  JSONencoder["H23"] = H23;
  JSONEncoder["ERR"] = ERR;
  JSONEncoder["RELAY"] = RELAY;


  char JSONmessageBuffer[350];
  JSONencoder.printTo(JSONmessageBuffer, sizeof(JSONmessageBuffer));
  client.publish(ACT_DATA_TOPIC, JSONmessageBuffer);
}
