// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#ifndef LORA_PINS
#define LORA_PINS

#include "Arduino.h"

class LoRaPins
{
  public:
    LoRaPins(String Node);
    int recievePins();
    void sendPins(int pin, int pinVal);
};

#endif
