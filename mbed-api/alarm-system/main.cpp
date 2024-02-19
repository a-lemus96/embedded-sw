#include "mbed.h"


#define PERIOD 0.01 // period of pwm signal in seconds

#define LFREQ 200 // low frequency of warble tone in Hz
#define HFREQ 1000 // high frequency of warble tone in Hz
#define WSTEPS 20 // number of steps for warble tone

#define UP_THRESH 0.9 // upper threshold for tank level
#define LOW_THRESH 0.1 // lower threshold for tank level

#define DELAY 2 // delay between sensor readings in seconds

// sensor inputs
AnalogIn tank_sens(p15);
AnalogIn temp_sens(p16);

// audiovisual outputs
PwmOut buzz(p21);
DigitalOut led(LED1);

// global variables
float level, temp;

int main() {
	// pwm configuration
        buzz.period(PERIOD);
        buzz = 0;

	while(1) {
		// read measurements
		level = tank_sens.read();
		temp = temp_sens.read();

		// check if tank is full
		if (level > UP_THRESH) {
			led = 0; // clear LED
			switch (temp) {
				case 0 ... 1/3:
					// trigger beeping tone
					break;
				case 1/3 ... 2/3:
					// continuous steady tone
					break;
				case 2/3 ... 1:
					// dual tone
					break;
				default:
					// do nothing
					break;
			}
        	// check if tank level is too low
		else if (level < LOW_THRESH) {
			// warble tone and flash LED
	    	}
        	else {
			// tank level is OK, reset outputs
			wait(DELAY);
        	}
}
