#include "mbed.h"

#define THRESH 0.75 // threshold for tank level

// sensor inputs
AnalogIn level(p15);
AnalogIn temp(p16);

// audiovisual outputs
PwmOut buzz(p21);
DigitalOut led(LED1);

float hival, loval, i, tempval;

int main() {
        buzz = 0.5; // set duty cycle
	while(1) {
		// loop while tank level is low
		while (level.read() < THRESH) {
			led = !led; // toggle LED
			// emit one cycle of warble tone using 20 steps
			for (i = 0; i < 1; i += 0.05) {
				// sweep from 100 Hz to 500 Hz
				buzz.period(0.010 - (0.008*i));
				wait_ms(50);
			}
		}
		// tank level is OK
		led = 0;
		tempval = temp.read();
		if (tempval < 0.33) {
			hival = 0.005; // set 200 Hz as tone
			loval = 1; // set to inaudible tone 1 Hz
		}
		if (tempval > 0.66) {
			hival = 0.001; // set 1 kHz as tone
			loval = 0.005; // set 200 Hz as tone
		}
		if (tempval > 0.33 && tempval < 0.66){
			hival = 0.002; // set 500 Hz as tone
			loval = 0.002; // set 500 Hz as tone
		}
		// emit tones
		speaker.period(hival);
		wait_ms(500);
		speaker.period(loval);
		wait_ms(500);
}
