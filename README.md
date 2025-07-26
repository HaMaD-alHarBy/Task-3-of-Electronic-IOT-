# Latching-Power-Switch-with-Auto-Off
## Latching Power Switch with Auto-Off with PIR Sensor 
## Project Overview
### This project demonstrates an energy-efficient circuit that automatically powers a microcontroller (Arduino UNO) ON only when necessary, using sensor activity. It uses a relay-based power control circuit triggered by a PIR motion sensor and a potentiometer (as an analog sensor). When no activity is detected, the system safely powers off, extending battery life.

## How It Works
### Power Initialization:

- Pressing the push button powers the circuit temporarily.

- A capacitor holds the voltage long enough for the microcontroller to initialize and take over.

### Sensor-Driven Activation:

- When the PIR sensor detects motion or analog input is active, Arduino keeps the relay ON via the NPN transistor.

### Auto Shutdown:

- If no activity is detected for a defined period, the Arduino stops the relay signal.

- Relay cuts power to the Arduino, saving battery.

### LED Indicators:

- Green LED: Active sensing or function is ongoing.

- Red LED: Idle state or preparing to shut down.

## Components List


<img width="1292" height="1278" alt="Screenshot 2025-07-26 233412" src="https://github.com/user-attachments/assets/df18f9b7-4b31-4a66-b7b5-0955d7c03894" />



## Circuit Wiring

## Power & Control Wiring
- 5V Power Supply
- Branches to:
- Pushbutton
- LU-5-R Relay
- 2N2222 Transistor
- Flyback Diode (1N4001)
- 100μF capacitor (+)
- PIR Sensor VCC
- Potentiometer (10kΩ resistor)
- Indicator LEDs

### Pushbutton
- One side → 5V
- Other side → LU-5-R Pin 1 (COIL+)
- Add 10kΩ pulldown resistor to GND

### LU-5-R Relay
- Pin 1 (COIL+) → Pushbutton output
- Pin 2 (COIL-) → 2N2222 Transistor Collector
- Pin 3 (COM) → Battery positive terminal
- Pin 4 (NO) → Arduino Vin pin
- Pin 5 (NC) → Leave unconnected

### 2N2222 Transistor
- Base → Arduino D8 via 1kΩ resistor
- Emitter → GND
- Collector → LU-5-R Pin 2 (COIL-)

### Flyback Diode (1N4001)
- Cathode (banded end) → LU-5-R Pin 1
- Anode → LU-5-R Pin 2

### 100μF Capacitor
- Positive leg → 5V rail
- Negative leg → GND

## Sensor Connections
### PIR Motion Sensor (HC-SR501)
- VCC → 5V
- GND → Arduino GND (Through 10kΩ)
- OUT → Arduino D2

### Potentiometer (10kΩ resistor)
- One leg → 5V
- Second leg → GND
- Third leg → Arduino A0

## Indicator LEDs
### Green LED (Power ON)
- Anode → Arduino D10
- Cathode → 1kΩ resistor → GND

### Red LED (Warning)
- Anode → Arduino D11
- Cathode → 1kΩ resistor → GND

## Arduino Code


<img width="1168" height="1050" alt="Screenshot 2025-07-26 234900" src="https://github.com/user-attachments/assets/01a0a21a-4f10-4a27-b2e3-e80f0ff5f63f" />


## Safety Tips for Your Circuit

- Double-check polarities on battery, capacitor, diode, and PIR sensor — reversing them may damage components.

- Always use a flyback diode across the relay coil to protect your transistor and Arduino from voltage spikes.

- Use resistors with LEDs and transistor base to prevent overcurrent.

- Avoid touching live wires while powered even low voltage can short components if mishandled.

- Secure all connections on the breadboard tightly loose wires can cause unexpected behavior.
