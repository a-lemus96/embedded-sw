# Heating Tank Monitoring and Alert System
This system is designed to effectively monitor and manage heating tanks in industrial environments. It utilizes Analog to Digital Conversion (ADC) and Pulse-Width Modulation (PWM) modules for accurate data collection and timely alerts. There are two sensors in the tank, one for temperature and the other for level. 

## Key Features
* **Dual Sensor Integration**: Temperature and level sensors provide data for monitoring tank conditions.
* **Alert System**: Different audible tones indicate specific tank states:
   1) High temperature in a full tank triggers a dual-tone alert.
   2) Optimal temperature in a full tank results in a continuous steady tone.
   3) Low temperature in a full tank triggers a single beeping tone.
   4) Low tank level prompts a warble tone with flashing LED for visibility.
* **Periodic Monitoring**: Sensors update every two seconds.

## Flow Diagram
This diagram presents a high-level design approach to help understand the underlying logic of the code in `main.cpp`. However, it is essential to note that specific implementation details may vary from what is depicted in the diagram.
  
![tank_monitor](https://github.com/a-lemus96/embedded-sw/assets/95151624/54d246b9-b8d7-4fef-bf01-f1453a38f067)
