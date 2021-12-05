// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include "Arduino.h"
#include "LoRaPins.h"

LoRaPins::LoRaPins()
{
}

void LoRaPins::recievePins(){
    int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received packet ");
    // read packet
    while (LoRa.available()) {
      inNode = LoRa.readStringUntil(':');
      s1string = LoRa.readStringUntil(',');
      v1string = LoRa.readStringUntil('|');
      sensor1 = s1string.toInt();
      value1 = v1string.toInt();
      }
    // print RSSI of packet
    Serial.print("with RSSI ");
    Serial.println(LoRa.packetRssi());
  }
}

void LoRaPins::sendPins(){
    Serial.print("Sending sensor status ");
    Serial.println(counter);
    counter += 1;
    LoRa.beginPacket();
    LoRa.setTxPower(14,RF_PACONFIG_PASELECT_PABOOST);
    LoRa.print(self);
    LoRa.print(":");
    LoRa.print(sensor1);
    LoRa.print(",");
    LoRa.print(curVal1);
    LoRa.print("|");
    LoRa.endPacket();
}
