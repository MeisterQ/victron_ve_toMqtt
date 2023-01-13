void sendMQTT()
{
  snprintf (vpvMSG, 10, "%ld", vpv);
  //  snprintf (pidMSG, 10, "%ld", valuePID);
  snprintf (vMSG, 10, "%ld", batteryV);
  snprintf (iMSG, 10, "%ld", current);
  snprintf (ppvMSG, 10, "%ld", ppv);
  snprintf (csMSG, 10, "%ld", cs);
  snprintf (h19MSG, 10, "%ld", H19);
  snprintf (h20MSG, 10, "%ld", H20);
  snprintf (h21MSG, 10, "%ld", H21);
  snprintf (h22MSG, 10, "%ld", H22);
  snprintf (h23MSG, 10, "%ld", H23);

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;

    client.publish(ACT_VPV_TOPIC, vpvMSG);
    client.publish(ACT_V_TOPIC, vMSG);
    client.publish(ACT_I_TOPIC, iMSG);
    client.publish(ACT_PPV_TOPIC, ppvMSG);
    client.publish(ACT_CS_TOPIC, csMSG);
    client.publish(ACT_H19_TOPIC, h19MSG);
    client.publish(ACT_H20_TOPIC, h20MSG);
    client.publish(ACT_H21_TOPIC, h21MSG);
    client.publish(ACT_H22_TOPIC, h22MSG);
    client.publish(ACT_H23_TOPIC, h23MSG);

    //client.publish(STATE_DEBUG_TOPIC, vpvMSG);

  }
}
