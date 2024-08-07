# Solar Grid Monitor

This project monitors the energy meter readings of a grid-connected solar power plant and displays the data wirelessly in real-time. The project uses an ESP32 microcontroller to host a web server and display the readings from the energy meters.

## Components Used
- ESP32
- Energy Meters
- LDR sensors
- WiFi module
- Resistors
- Breadboard and connecting wires

## Features
- Monitors KSEB and Solar energy meter readings.
- Displays the readings in real-time on a web page.
- Calculates the energy consumption and cost.
- Provides a user-friendly web interface to view the data.

## Setup Instructions

### Hardware Setup
1. Connect the LDR sensors to the ESP32 as follows:
    - KSEB Meter Pin: GPIO 22
    - Solar Meter Pin: GPIO 23
2. Set up the resistors and LDRs on the breadboard.
3. Connect the ESP32 to your computer using a USB cable.

### Software Setup
1. Download and install the [Arduino IDE](https://www.arduino.cc/en/software).
2. Install the necessary libraries:
    - WiFi.h
    - WebServer.h

3. Clone this repository to your local machine:
    ```bash
    git clone https://github.com/your-username/SolarPowerMonitor.git
    ```

4. Open the `code.ino` file in the Arduino IDE.
5. Update the `ssid` and `password` variables with your WiFi credentials.
6. Upload the code to the ESP32.

### Accessing the Web Interface
1. After uploading the code, the ESP32 will start an access point with the SSID "test" and password "123456789".
2. Connect your computer or mobile device to this network.
3. Open a web browser and enter the IP address `192.168.4.1` to access the web interface.

### Web Interface
The web interface consists of four tabs:
- **Pulse**: Displays the KSEB and Solar pulse counts.
- **KWh**: Displays the energy consumption in KWh.
- **Wh**: Displays the energy consumption in Wh.
- **Price**: Displays the cost of energy consumption.

The data on the web interface updates every second to provide real-time readings.
