// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include "heltec.h"
//#include <LoRaPins.h>
using namespace std;

#define BAND    915E6  //you can set band here directly,e.g. 868E6,915E6

//const int nodes = 2;

//constant sensors = 1;

//int pinArray[nodes][pins] = {{0},{0}}

String self = String("Node2");
//LoRaPins LP(self);


//Recieve variables
String inNode = String();
String s1string = String();
String v1string = String();
int sensor1 = 0;
int value1 = 0;



//Send variabless
int counter = 0;
int curVal1 = 0;
#define sense1 2


void setup() {
  Heltec.begin(true /*DisplayEnable Enable*/, true /*Heltec.LoRa Disable*/, true /*Serial Enable*/, true /*PABOOST Enable*/, BAND /*long BAND*/);

}

void loop() {
  recievePins();
  //LP.recievePins();

  if (value1 == HIGH){
    digitalWrite(25, HIGH);
  }else 
    digitalWrite(25, LOW);

  
  if(curVal1 != digitalRead(sense1)){
    curVal1 = digitalRead(sense1);
    sendPins();
    //LP.sendPins();
  }
/*
* LoRa.setTxPower(txPower,RFOUT_pin);
* txPower -- 0 ~ 20
* RFOUT_pin could be RF_PACONFIG_PASELECT_PABOOST or RF_PACONFIG_PASELECT_RFO
*   - RF_PACONFIG_PASELECT_PABOOST -- LoRa single output via PABOOST, maximum output 20dBm
*   - RF_PACONFIG_PASELECT_RFO     -- LoRa single output via RFO_HF / RFO_LF, maximum output 14dBm
*/
}

void recievePins(){
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

void sendPins(){
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
