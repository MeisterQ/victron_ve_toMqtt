void getData()
{
  if (swSer.available() > 0)
  {
    data = swSer.readStringUntil('\n');

    // Product ID
    if (data.startsWith("PID"))
    {
      valuePID = data.substring(4);
      valuePID.trim();
      Serial.print("PID: ");
      Serial.println(valuePID);
    }

    // Voltage PV
    else if (data.startsWith("VPV"))
    {
      valueVPV = data.substring(4);
      valueVPV.trim();
      vpv = valueVPV.toInt();
      Serial.print("VPV: ");
      Serial.println(vpv);
    }

    // Voltage Battery
    else if (data.startsWith("V"))
    {
      valueV = data.substring(2);
      valueV.trim();
      batteryV = valueV.toInt();
      Serial.print("Battery Voltage: ");
      Serial.println(valueV);
    }

    // Current
    else if (data.startsWith("I"))
    {
      valueI = data.substring(2);
      valueI.trim();
      current = valueI.toInt();
      Serial.print("Current: ");
      Serial.println(current);
    }

    // Power PV
    else if (data.startsWith("PPV"))
    {
      valuePPV = data.substring(4);
      valuePPV.trim();
      ppv = valuePPV.toInt();
      Serial.print("PV Power: ");
      Serial.println(ppv);
    }

    // Operating State
    else if (data.startsWith("CS"))
    {
      valueCS = data.substring(3);
      valueCS.trim();
      cs = valueCS.toInt();
      Serial.print("Operating State: ");
      Serial.println(cs);
    }

    // Yield total
    else if (data.startsWith("H19"))
    {
      valueH19 = data.substring(4);
      valueH19.trim();
      H19 = valueH19.toInt();
      Serial.print("Yield total: ");
      Serial.println(H19);
    }

    // Yield today
    else if (data.startsWith("H20"))
    {
      valueH20 = data.substring(4);
      valueH20.trim();
      H20 = valueH20.toInt();
      Serial.print("Yield today: ");
      Serial.println(H20);
    }

    // Maximum power
    else if (data.startsWith("H21"))
    {
      valueH21 = data.substring(4);
      valueH21.trim();
      H21 = valueH21.toInt();
      Serial.print("Maximum Power: ");
      Serial.println(H21);
    }

    // Yield yesterday
    else if (data.startsWith("H22"))
    {
      valueH22 = data.substring(4);
      valueH22.trim();
      H22 = valueH22.toInt();
      Serial.print("Yield yesterday: ");
      Serial.println(H22);
    }

    // Maximum power
    else if (data.startsWith("H23"))
    {
      valueH23 = data.substring(4);
      valueH23.trim();
      H21 = valueH23.toInt();
      Serial.print("Maximum Power yesterday: ");
      Serial.println(H23);
    }
    // Error
    else if (data.startsWith("ERR"))
    {
      valueERR = data.substring(4);
      valueERR.trim();
      ERR = valueERR.toInt();
      Serial.print("Error-State: ");
      Serial.println(ERR);
    }
    // RELAY
    else if (data.startsWith("RELAY"))
    {
      valueRELAY = data.substring(6);
      valueRELAY.trim();
      RELAY = valueRELAY.toInt();
      Serial.print("Relay-State: ");
      Serial.println(RELAY);
    }

    yield();
  }
}
