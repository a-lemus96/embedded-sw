# Simple music player

## Description
A simple music player using an mbed microcontroller. It plays a hardcoded melody with different notes and beats, controlled by analog inputs for volume and speed. The melody is played through a speaker, and the volume and speed are indicated by LEDs.

## Components
- mbed microcontroller
- Speaker
- Red, yellow, and blue LEDs
- Potentiometers for volume and speed control

## Pin Configuration
- `SPEAKER`: Output pin for the speaker
- `RED_LED`, `YELLOW_LED`, `BLUE_LED`: Output pins for the red, yellow, and blue LEDs respectively
- `AIN1`: Analog input pin for volume control
- `AIN2`: Analog input pin for speed control

## Music Notes and Beats
- `Do`, `Re`, `Mi`, `Fa`, `So`, `La`, `Si`: Music notes with corresponding frequencies
- `b1`, `b2`, `b3`, `b4`: Beat lengths as a portion of the note duration

## Functionality
- The program plays a hardcoded melody defined by the `note` and `beat` arrays.
- The melody is interrupted by periodic interrupts controlled by the `timer_ISR` function.
- The volume and speed of the melody are controlled by potentiometers connected to analog inputs.
- LEDs indicate the currently played note, volume level, and speed.

## How to Use
1. Connect the components as per the pin configuration.
2. Upload the code to the mbed microcontroller.
3. Adjust the potentiometers to control volume and speed.
4. The melody will start playing automatically, and LEDs will indicate the current state.

## Notes
- Ensure proper connections and component compatibility.
- Adjust the melody, notes, and beats as needed for different tunes.
- Fine-tune the timer interrupt frequency for smoother playback.
