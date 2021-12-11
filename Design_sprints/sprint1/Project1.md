# Project 1 - Wireless Protocols for Mesh Networks
### Jack Locke - EC601 - 20210919
## Research on LoRa radio/LoRaWAN, 2.4Ghz GFSK modulation, ISM band radio frequencies, and their applications to Mesh Networks and IoT communication


### Motivation / Problem Statement

Mobile communication in the western world is dominated by telephone service providers who have generally found a happy medium between costs and level of service for the customer. The big secret of wireless communication, however, is that 90% or more of the connection is generally wired. Whether your device is serviced by a WiFi router in your home or the cellular communication tower down the block, the connections between these gateways are connected by coaxial or fiber-optic cable and switched by the service provider to deliver the data from end to end. These networks do not cover every square kilometer of the globe and, with the exception of satellites, leave many places where communication is limited. Often the solution in these scenarios is handheld voice radios, but if the parties communicating are machines, or the nature of the communication is specifically digital, this solution isn't generally effective. Some other form of digital communication would be required to address these problems.

Many technologies exist to solve the 'remote connectivity' problem, but most fall into one or more additions problems.

1. Post and Telecom Authority (PTA) legal restrictions -
    Since the wireless spectrum is a finite resource, governments have sliced and diced them into various bands and made agreements with other PTAs to restrict the usage of much of the spectrum unless the user has a license to do so. Amateur Radio, for example has many packet radio protocols to send data via specific reserved radio bands. While many of these licenses are inexpensive or free, many countries have allocated some frequency ranges for open use as Industrial, Scientific and Medical (ISM) use and do not require a license.

2. Subscription Costs and setup fees -
   In the US, mobile service providers are for profit companies and (somewhat understandably) want to make money in return for the service provided. While, as mentioned above, these prices aren't always unreasonable they do not always extend into remote areas and certainly not without substantial up front equipment costs and even more expensive service packages. Emerging satellite internet service providers are beginning to bring this cost down but is not yet ubiquitous. Many

3. Privacy and security -
    Even if the previous two conditions are met, they very often come at the cost of prohibition of encryption or monitoring meta-data as a term of service or license condition. Whether you are an individual citizen of country with an oppressive government or a business owner who wishes to keep their trade secrets, the ability to implement device communication in confidence is limited. One of the best ways to overcome this problem is open-source implementation of some solution, such that a broad community can audit and improve the implementation in use.

### Applications

The intent of this project is to develop a license free, low cost, open-source device that can pair with a wide a variety of host devices (such as a mobile phone or laptop computer, but also IoT devices) to provide connectivity in off-grid scenarios. The variants of such events are numerous (weather emergencies, 'Burning-Man' type festival, zombie apocalypse, etc.) and specific applications are only limited by the imagination of the end user for implementation. However specific criteria need to be established during development to ensure the end product fulfills the intent of the end product. Many technologies exist that fill some or all of the broad requirements, but a comparison or combination of the technologies listed below will have to be assessed to determine the design.

Once completed, the end product of this project should allow for a somewhat tech-savvy user to read the details of the project, acquire the specified hardware for less than the commercial implementation, and legally implement an off-grid network communication for private communication.

### Literature and Technology Review

This section is far from comprehensive in investigating the numerous technologies that exist in this field but is a quick survey of some of the devices and projects I was able to identify to work on this problem.

**goTenna** [https://gotennamesh.com/]

This is a commercial and non-open-source product that is in the arena of what this project aims at but falls short in many ways. It is included to demonstrate some of the desirable features that should be included in an end product for this project.

The GoTenna Mesh system is sold in pairs or more to enable smart-phones to relay messages between users and creates ad-hoc mesh networks within goTenna user network to extend range. It uses the 915MHz ISM band (similar to LoRa) and GFSK Modulation (discussed later) combined with a proprietary mesh protocol (Aspen GroveTM) to achieve communications.

Advantages:
- commercially available with customer support
- broad user base internationally for increased mesh size

Disadvantages:
- Proprietary protocol, software and implementation
- Expensive (~$80/unit)
- Only connects to mobile phones

For the proprietary reasons alone, this solution defeats the purpose of this project, but the goTenna in general is a good model to emulate.  

**GFSK 2.4Ghz - nRF24L01+** [https://lastminuteengineers.com/nrf24l01-arduino-wireless-communication/]

Gaussian Frequency Shift Keying is a method of radio broadcast that preprocesses the signal to reduce the sideband power and therefore reduce the overall power consumption of transmission. The nRF24l01+ chip combines this with the 2.4Ghz frequency to implement a power efficient, low-cost solution for adding wireless communication to a project, with up to 6 simultaneous data channels. Because of the high transmission frequency, the maximum range is approximately a kilometer and only if implemented with a Power amplifier/Low Noise Amplifier chip (commonly sold together).

Advantages:
- Inexpensive
- Fast data rate
- Low Power
- Open Protocol
- License Free

Disadvantages:
-Limited range (depending on desired application)


**LoRa and LoRa WAN** [https://en.wikipedia.org/wiki/LoRa]

LoRa (Long Range) is a proprietary radio transmission protocol developed to specifically address the problem of long transmission range with low power. Using Chirp spread spectrum and GFSK LoRa transmits in the 915Mhz ISM band (in the US) and shifts the carrier frequency of the transmission up along the duration of the transmission to broadcast low power but in a way that receivers can filter the transmission from the noise floor. In addition, the LoRa Alliance, a consortium of many prominent tech companies have invested money into research and implementation to spread the use of the technology and developed LoRaWAN to provide gateways into the open internet, increasing range and allowing access to internet resources. Since the frequency used for transmission is comparatively low, data transmission rates are limited. This makes LoRa ideal for systems that need frequent but small control signals for operation or for small data transmission purposes.

Advantages:
- Long Range (as the name implies)
- Low Power
- Consortium support
- Internet connectivity

Disadvantages:
- Expensive (relative)
- Slow data rate
- Proprietary (but openly available)


**Summary**

| Technology | Cost | Range (ideal) | Bandwidth | Comments
|:-------------:|-------------:| :-----:|:---:|:---|
| LoRa | ~$25 | 5-15km | 0.3kbit/s - 27kbit/s | Expensive and slow, but far |
| GFSK | ~$5 | 1km | 250kbps - 2Mbps | Fast and cheap but short |

Both of these technologies have their drawbacks and useful properties. Perhaps a protocol that could create a mesh of meshes to allow fast transmission at short range and shorter messages at longer messages through a LoRa Gateway (or possibly both in the dame device?) could be implemented.

### Open-Source Research

nRF24L01+
-nRF24 [https://github.com/nRF24] - An open library that controls all of the functions of a nRF24L01+ transceiver in C and can easily be implemented on a variety of microcontrollers and includes OSI layer 2, 3, and 7 support for mesh networks.

LoRa:
- Meshtastic [https://github.com/meshtastic] - An open source project that aims to implement the same functionality of goTenna but for a variety of devices and hardware and includes security as a goal. If Implemented on a microcontroller with pin-out access can also be used to control I/O functions and send messages accordingly.  

- Disaster.Radio [https://github.com/sudomesh/disaster-radio] - in it's own words 'It is a work-in-progress long-range, low-bandwidth wireless disaster recovery mesh network powered by the sun.' It is currently not actively being developed.


### Duplicate Results

- Meshtastic - I was able to successfully flash and program two ESP32 based LoRa chips with meshtastic and install the meshtastic CLI to send simple messages to all (two) Nodes in the mesh network I had set up. I have not tested range of devices in a urban environment but they did successfully communicate over the 20m of my apartment.  

- RF24 - I was able to program three nRF24L01+ chips using the RF24 library with the Arduino IDE and send serial messages in both Rx and Tx mode at various times in sequence for all three devices. I was additionally able to control a servo motor on one device with a potentiometer on another device with RF transmissions. I again have not tested range restrictions on these devices but they were successful at short range.
