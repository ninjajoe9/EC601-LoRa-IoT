# LoRaPins
An Arduino/Python Library for controlling the GPIO pins of multiple microcontroller devices over LoRa communication protocol

## Why LoRa?

![LoRa Logo](https://github.com/ninjajoe9/EC601-LoRa-IoT/blob/main/resources/LoRa-logo.png)

LoRa (short for long range) is a spread spectrum modulation technique derived from chirp spread spectrum (CSS) technology. LoRa is a long range, low power wireless platform that enable users to construct a robust wireless platform of Internet of Things.
The main benefits of LoRa are long-range, low-power and low-cost connectivity. Compared to other protocol such as Cellular protocols or the WiFi protocol, LoRa’s range and power consumption advantage has give LoRa capability to construct a larger, cheaper IoT network.

## What LoRaPins does for you

LoRaPins is a library that abstracts away the details of the LoRa protocol so you only need to worry about the inputs and outputs of the sensors and actuators on the various devices in your network. After implementing LoRaPins, you can treat the pins on a node multiple kilometers away as if they are on the same device directly in front of you. While we absolutely endorse you learn more about the LoRa protocol, you wont have to get bogged down in the details of how LoRa works, or how to format the packets to get your devices to communicate. 

### What LoRaPins is Not - Understanding the limitations of LoRa

As mentioned above, LoRa is different from Bluetooth and WiFi in that you can communicate at much longer distances and significantly reduced power but at the cost of bandwidth. Do not expect LoRa to allow full video or voice communication, or large amounts of data retrieval. LoRa is ideal for IoT devices where one node needs to know the status of a particular sensor on another node, or send a short message between two users who both have a LoRa Device.

Currently LoRa Pins is only implemented on the [Heltec32 LoRa 32](https://heltec.org/project/wifi-lora-32/) development board, and only for local mesh networks (i.e. not over the internet via LoRaWAN). While we intend to expand development to additional board types (starting with the [Adafruit RaspberryPi Zero Bonnet](https://www.adafruit.com/product/4074?gclid=CjwKCAiAtdGNBhAmEiwAWxGcUozS6muD0NSz0A3r0Cih3FSe6jchsEw7G5WLAznO3jkp0htGQKD3PxoCMYoQAvD_BwE)) and additional code formats (python libraries) as well as implementing LoRaWAN protocols to enable Mesh to Mesh communication over the internet, we have not done so yet. This project primarily served as a proof of concept for a graduate engineering class at Boston University so future development will likely be slow. (Please see contact information below if you're interested in developing additional packages or assisting in this project!)   



## Quick setup guide
(jack will probably work on this)

## Future plans/implementation goals
- Adding the functionalities to implement communication through the LoRaWAN Gateway from the local mesh network to another mesh network.
- Creating a simple User Interface that takes in details of the number of GPIO pins required for an application and converts it into a JSON format which can be used by the software package to assign GPIO pins accordingly.
- Make the package more robust such that 'n' number of GPIO pins can be implemented.


## Design Process
Convenient links for those associated with Boston University EC601 Product Design, or those grading the design sprints (Looking at you Prof. Alshaykh)

[Sprint 1](https://github.com/ninjajoe9/EC601-LoRa-IoT/blob/main/Design_sprints/sprint1/sprint1.md) - initial project intent, research, and design overview. (includes MVP and User stories) (NOTE: Project has changed drastically from original Vision)

[Sprint 2](https://github.com/ninjajoe9/EC601-LoRa-IoT/blob/main/Design_sprints/sprint2/sprint2.md) - testing of physical systems and implementation of LoRa protocols on the devices we purchased for the project. 

[Sprint 3](https://github.com/ninjajoe9/EC601-LoRa-IoT/blob/main/Design_sprints/sprint3/sprint3.md) - testing of Heltech hardware to implement a rudamentary pager system as a precoursor to our library. 

[Sprint 4](https://github.com/ninjajoe9/EC601-LoRa-IoT/blob/main/Design_sprints/sprint4/sprint4.md) - packaging of the functions into a .h and .cpp file and finalizing our poster for presentation

[Poster](https://github.com/ninjajoe9/EC601-LoRa-IoT/blob/main/Design_sprints/poster/lora_36_56.pdf) - Poster presented at presentation day

## Questions/comments?

Please feel free to leave an issue or contact [Jack Locke](mailto:lockej@bu.edu)
