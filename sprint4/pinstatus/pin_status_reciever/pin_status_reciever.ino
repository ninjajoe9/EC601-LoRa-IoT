#include "heltec.h"
#define BAND    915E6  //you can set band here directly,e.g. 868E6,915E6

int counter = 0;
int sensor1 = 0;
int value1 = 0;
String s1string = String();
String v1string = String();

String inNode = String();

void setup() {
  
  //WIFI Kit series V1 not support Vext control
  Heltec.begin(true /*DisplayEnable Enable*/, true /*Heltec.LoRa Disable*/, true /*Serial Enable*/, true /*PABOOST Enable*/, BAND /*long BAND*/);

  
}

void loop() {
    // try to parse packet
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

  if (value1 == HIGH){
    Serial.print(inNode);
    Serial.print(" Pin ");
    Serial.print(sensor1);
    Serial.println(":ON");
    digitalWrite(25, HIGH);
    delay(1000);                       // wait for a second
    digitalWrite(25, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);                       // wait for a second
  }
    
    
  
  if(digitalRead(2) == HIGH){
    Serial.print("Sending packet: ");
    Serial.println(counter);
  // send packet
    LoRa.beginPacket();
/*
* LoRa.setTxPower(txPower,RFOUT_pin);
* txPower -- 0 ~ 20
* RFOUT_pin could be RF_PACONFIG_PASELECT_PABOOST or RF_PACONFIG_PASELECT_RFO
*   - RF_PACONFIG_PASELECT_PABOOST -- LoRa single output via PABOOST, maximum output 20dBm
*   - RF_PACONFIG_PASELECT_RFO     -- LoRa single output via RFO_HF / RFO_LF, maximum output 14dBm
*/
    LoRa.setTxPower(14,RF_PACONFIG_PASELECT_PABOOST);
    LoRa.print("hello  hello ");
    LoRa.print(counter);
    LoRa.endPacket();
  
    counter++;
    digitalWrite(25, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for a second
    digitalWrite(25, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);                       // wait for a second
  }
}
