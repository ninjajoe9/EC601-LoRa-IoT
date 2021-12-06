CENSE file in the project root for full license information.

#include "Arduino.h"
#include "LoRaPins.h"
#include "heltec.h"

String self = String();

//Recieve variables



//Send variabless
int counter;


LoRaPins::LoRaPins(String Node)
{
  self = Node;
}

int LoRaPins::recievePins(){
    String inNode = String();
    String s1string = String();
    String v1string = String();
    int sensor1;
    int value;
    int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received packet ");
    // read packet
    while (LoRa.available()) {
      lr.inNode = LoRa.readStringUntil(':');
      lr.s1string = LoRa.readStringUntil(',');
      lr.v1string = LoRa.readStringUntil('|');
      lr.sensor1 = s1string.toInt();
      lr.value = v1string.toInt();
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
