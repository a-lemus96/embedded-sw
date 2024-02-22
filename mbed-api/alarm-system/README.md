# Heating Tank Monitoring and Alert System

## Description
This project is designed to monitor the level of a tank and provide audiovisual alerts based on the tank level and temperature readings. It utilizes an mbed microcontroller along with sensor inputs for tank level and temperature, and audiovisual outputs for alerts.

## Components
- mbed microcontroller
- Tank level sensor (AnalogIn)
- Temperature sensor (AnalogIn)
- Buzzer (PwmOut)
- LED (DigitalOut)

## Threshold
- `THRESH`: Threshold value for the tank level, set at 0.75 for this project.

## Functionality
- Continuously monitors the tank level and temperature.
- When the tank level is below the threshold, it triggers an audiovisual alert indicating low level.
- The alert consists of a warble tone that sweeps from 100 Hz to 500 Hz using 20 steps, along with blinking LED.
- When the tank level is normal, it checks the temperature and emits different tones based on temperature ranges:
  - If temperature is below 0.33, emits a single beeping tone at 200 Hz.
  - If temperature is above 0.66, emits a dual tone alert at 200 Hz and 1 kHz.
  - If temperature is between 0.33 and 0.66, emits a continuous steady tone at 500 Hz.
- Alerts are accompanied by LED status changes for visual indication.

## Usage
1. Connect the components as per the pin configuration.
2. Upload the code to the mbed microcontroller.
3. Ensure proper threshold value and sensor calibration.
4. Monitor the tank level and temperature readings along with the audiovisual alerts.

## Notes
- Ensure proper sensor calibration and threshold setting for accurate alerts.
- Adjust the code as needed for different threshold values or alert conditions.
- Test the functionality thoroughly to ensure reliable operation.

## Flow Diagram
This diagram presents a high-level design approach to help understand the underlying logic of the code in `main.cpp`. However, it is essential to note that specific implementation details may vary from what is depicted in the diagram.
  
![tank_monitor](https://github.com/a-lemus96/embedded-sw/assets/95151624/54d246b9-b8d7-4fef-bf01-f1453a38f067)
