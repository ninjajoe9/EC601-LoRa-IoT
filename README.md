# EC601-LoRa-IoT
An Arduino/Python Library for controling the GPIO pins of multiple microcontroler devices over LoRa communiccation protocol

## Why LoRa?
(for Mani or JueHao, whoever gets to it first. poossibly just copy pate from the poster.

## What LoRaPins does for you

LoRaPins is a library that abstracts away the details of the LoRa protocol so you only need to worry about the inputs and outputs of the sensors and actuators on the various devices in your network. After implementing LoRaPins, you can treat the pins on a node multiple kilometers away as if they are on the same device directly in front of you. While we absolutely endorse you learn more about the LoRa protocol, you wont have to get bogged down in the details of how LoRa works, or how to format the packets to get your devicces to ccommunicate. 

### What LoRa Pins is Not - Understanding the limitations of LoRa

As mentioned above, LoRa is different from Bluetooth and WiFi in that you can communicate at much longer distances and significantly reduced power but at the cost of bandwidth. Do not expect LoRa to allow full video or voice communication, or large amounts of data retrieval. LoRa is ideal for IoT devices where one node needs to know the status of a paticular sensor on another node, or send a short message between two users who both have a LoRa Device.

Currently LoRa Pins is only implemented on the Heltec32 LoRa 32 development board, and only for local mesh networks (i.e. not over the internet via LoRaWAN). While we intend to expand developmet to additional board types (starting with the Adafruit RaspberryPi Zero Hat) and additional code formats (python libraries) as well as implementing LoRaWAN protocols to enable Mesh to Mesh communication over the internet, we have not done so yet. This project primariy served as a proof of concept for a graduate engineering class at Boston Univeristy so future development will likely be slow. (Please see contact information below if you're interested in developing additional packeges or assisting in this project!)   



## Quick setup guide
(jack will probably work on this)

## Future plans/implementation goals
(whoever gets to this)

## Design Process
Convienient links for those associated with Boston University EC601 Product Design, or those grading the design sprints (Looking at you Prof. Alshaykh)

::intert links here::

## Questions/comments?

Please feel free to leave an issue or contact Jack Locke at lockej@bu.edu
