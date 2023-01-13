void wifiSettings()
{
  //  WiFi.persistent(false);
  WiFi.mode(WIFI_STA);
  // WiFi.config(ip, gateway, subnet, dns); // Uncomment for fixed IP
  WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
      Serial.print(".");
      delay(500);
  }
}
