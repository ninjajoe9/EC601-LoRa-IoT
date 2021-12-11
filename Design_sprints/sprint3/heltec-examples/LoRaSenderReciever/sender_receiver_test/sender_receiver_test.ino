                /* 
  Basic test program, send date at the BAND you seted.
  
  by Aaron.Lee from HelTec AutoMation, ChengDu, China
  成都惠利特自动化科技有限公司
  www.heltec.cn
  
  this project also realess in GitHub:
  https://github.com/Heltec-Aaron-Lee/WiFi_Kit_series
*/
#include "heltec.h"
#define BAND    915E6  //you can set band here directly,e.g. 868E6,915E6
#define ADDRESS 0x12


int counter = 0;
int sensor1 = 0;
int sensor2 = 0;
int sensor3 = 0;
int value1 = 0;
int value2 = 0;
int value3 = 0;


void setup() {
  
  //WIFI Kit series V1 not support Vext control
  Heltec.begin(true /*DisplayEnable Enable*/, true /*Heltec.LoRa Disable*/, true /*Serial Enable*/, true /*PABOOST Enable*/, BAND /*long BAND*/);

  
}

void loop() {
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
    sensor1 = LoRa.readStringUntil(',');
    value1 = LoRa.readStringUntil('|');
    sensor2 = LoRa.readStringUntil(',');
    value2 = LoRa.readStringUntil('|');
    sensor3 = LoRa.readStringUntil(',');
    value3 = LoRa.readStringUntil('|');
      Serial.print((char)LoRa.read());
    }
    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
  }
  
  if(digitalRead(2) == HIGH){
    if(ADDRESS == 0x12){
      sensor1 = 25;
      value1 += 1;
    }
  
    if(ADDRESS == 0x13 ){
      sensor2 = 25;
      value2 += 1;
    }
    if(ADDRESS == 0x14){
      sensor3 = 25;
      value3 += 1;
    }


    
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
*   
*   
*/


 LoRa.print(sensor1);
 LoRa.print(",");
 LoRa.print(value1);
 LoRa.print("|");
 LoRa.print(sensor2);
 LoRa.print(",");
 LoRa.print(value2);
 LoRa.print("|");
 LoRa.print(sensor3);
 LoRa.print(",");
 LoRa.print(value3);
 LoRa.print("|");

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
