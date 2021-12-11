#include "heltec.h"
#define BAND    915E6  //you can set band here directly,e.g. 868E6,915E6

int counter = 0;
int curVal1 = 0; 

#define sensor1 2

void setup() {
  Heltec.begin(true /*DisplayEnable Enable*/, true /*Heltec.LoRa Disable*/, true /*Serial Enable*/, true /*PABOOST Enable*/, BAND /*long BAND*/);

}

void loop() {
  char self[6] = "Node2";
    // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received packet '");
    digitalWrite(25, HIGH);
    delay(1000);                       // wait for a second
    digitalWrite(25, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);                       // wait for a second

    // read packet
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }
    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
  }
  if(curVal1 != digitalRead(sensor1)){
    curVal1 = digitalRead(sensor1);
    Serial.print("Sending sensor status ");
    Serial.println(counter);

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

  

/*  
  if(digitalRead(2) == HIGH){
    Serial.print("Sending packet: ");
    Serial.println(counter);
  // send packet
    LoRa.beginPacket();
*/
/*
* LoRa.setTxPower(txPower,RFOUT_pin);
* txPower -- 0 ~ 20
* RFOUT_pin could be RF_PACONFIG_PASELECT_PABOOST or RF_PACONFIG_PASELECT_RFO
*   - RF_PACONFIG_PASELECT_PABOOST -- LoRa single output via PABOOST, maximum output 20dBm
*   - RF_PACONFIG_PASELECT_RFO     -- LoRa single output via RFO_HF / RFO_LF, maximum output 14dBm
*/
/*
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
*/
}
