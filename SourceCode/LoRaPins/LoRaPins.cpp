// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include "Arduino.h"
#include "LoRaPins.h"
#include "heltec.h"

String self = String();

//Recieve variables
String inNode = String();
String s1string = String();
String v1string = String();
int sensor1;
int value;

//Send variabless
int counter;


LoRaPins::LoRaPins(String Node)
{
  self = Node;
}

int LoRaPins::recievePins(){
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
      value = v1string.toInt();
      }
    // print RSSI of packet
    Serial.print("with RSSI ");
    Serial.println(LoRa.packetRssi());
    return value;
  }
}

void LoRaPins::sendPins(int pin, int pinVal){
    Serial.print("Sending sensor status ");
    Serial.println(counter);
    counter += 1;
    LoRa.beginPacket();
    LoRa.setTxPower(14,RF_PACONFIG_PASELECT_PABOOST);
    LoRa.print(self);
    LoRa.print(":");
    LoRa.print(pin);
    LoRa.print(",");
    LoRa.print(pinVal);
    LoRa.print("|");
    LoRa.endPacket();
}
