void wifiSettings()
{
  //  WiFi.persistent(false);
  WiFi.mode(WIFI_STA);
#ifdef fixedIP
  WiFi.config(ip, gateway, subnet, dns); // Uncomment for fixed IP
#endif
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
}
