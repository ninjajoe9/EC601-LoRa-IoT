#include <SPI.h>
#include <LoRa.h>

#define LORA_SS 18
#define LORA_RST 14
#define LORA_DIO0 26

int counter = 0;

void setup() {
  //pinMode(LORA_SS, OUTPUT);
  //digitalWrite(LORA_SS, HIGH);
  
  Serial.begin(9600);
  while (!Serial);
  Serial.println("LoRa Receiver");

  LoRa.setPins(LORA_SS, LORA_RST, LORA_DIO0);
  LoRa.setSPIFrequency(10E6);

  while (!LoRa.begin(915E6)) {
    Serial.println(".");
    delay(500);
  }
  LoRa.setSyncWord(0xF3);
  Serial.println("LoRa Initializing OK!");
}

void loop() {
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received packet '");
    //digitalWrite(25, HIGH);   // turn the LED on (HIGH is the voltage level)
    //delay(200);                       // wait for a second
    //digitalWrite(25, LOW);    // turn the LED off by making the voltage LOW
    //delay(200);                       // wait for a second

    // read packet
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }

    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
  }
}
