// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include "heltec.h"
#include <LoRaPins.h>
using namespace std;

#define BAND    915E6  //you can set band here directly,e.g. 868E6,915E6

//const int nodes = 2;

//constant sensors = 1;

//int pinArray[nodes][pins] = {{0},{0}}

String thisNode = String("Node2");
LoRaPins LP(thisNode);

int value1;
int curVal1;
#define sense1 2
z


void setup() {
  Heltec.begin(true /*DisplayEnable Enable*/, true /*Heltec.LoRa Disable*/, true /*Serial Enable*/, true /*PABOOST Enable*/, BAND /*long BAND*/);

}

void loop() {
  value1 = LP.recievePins();

  if (value1 == HIGH){
    digitalWrite(25, HIGH);
  }else 
    digitalWrite(25, LOW);

  
  if(curVal1 != digitalRead(sense1)){
    curVal1 = digitalRead(sense1);
    LP.sendPins(sense1, curVal1);
  }

}
