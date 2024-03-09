# NTP Time Synchronization with ESP32

![ESP32](./NTP.png)

## Overview
This project demonstrates how to synchronize time using Network Time Protocol (NTP) on ESP32 microcontrollers. By synchronizing with an NTP server, the ESP32 device can maintain accurate timekeeping, which is essential for various applications such as data logging, scheduling, and event handling.

## Getting Started
To use this code, you need the following hardware:
- ESP32 development board (e.g., ESP32 DevKitC)

## Installation
1. Clone or download this repository to your local machine.
2. Configure the `ssid` and `password` variables in the code with your WiFi network credentials.
3. Compile and upload the code to your ESP32 board. Alternatively, you can use the Wokwi platform for simulation.

## Code Explanation
The `main.cpp` code consists of :

### `setup()`
- Connects the ESP32 to the WiFi network.
- Sets up the NTP client and synchronizes time with the NTP server.

### `loop()`
- Checks if the NTP client has updated the time.
- If the time is updated, it prints various time-related information to the serial monitor, including epoch time, formatted time, seconds, minutes, hours, and the day of the week.

## Author
This project was developed by PAT.