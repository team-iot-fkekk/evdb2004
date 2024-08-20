# EV UTeM Dashboard using Favoriot Platform

This repository contains the source code for an Electric Vehicle (EV) dashboard project developed at Universiti Teknikal Malaysia Melaka (UTeM) using the Favoriot IoT platform.

## Project Overview

- **Target Board**: Arduino Uno R4 WiFi
- **Development Environment**: Arduino IDE and PlatformIO
- **IoT Platform**: Favoriot
- **Dashboard URL**: [EV UTeM Dashboard](https://platform.favoriot.com/public/QTt51mKlLJzuD6nyV1qffSbNNaR03Qhp)

## Features

- Collects and transmits 13 different signals from an EV
- Sends data to Favoriot platform for real-time monitoring
- Visualizes data on a public dashboard

## Repository Contents

- Arduino source code
- PlatformIO project files
- Configuration files for connecting to Favoriot platform

## Getting Started

1. Clone this repository
2. Open the project in Arduino IDE or PlatformIO
3. Create a new header file "arduino_secrets.h". Insert the following code with the credentials.
   
```cpp
#define SECRET_SSID ""
#define SECRET_PASS ""
#define SECRET_APIKEY ""
```
4. Configure your WiFi credentials and Favoriot API key
5. Upload the code to your Arduino Uno R4 WiFi board
6. View your data on the Favoriot dashboard

