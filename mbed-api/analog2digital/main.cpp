#include "mbed.h"

#define DELAY 2 // delay between sensor readings in seconds
#define WSTEPS 20 // number of steps in the warble tone
#define LFREQ 200 // low frequency of warble tone in Hz
#define HFREQ 1000 // high frequency of warble tone in Hz

// define inputs
AnalogIn tank_sens(p15);
AnalogIn temp_sens(p16);

// define outputs
PwmOut buzz(p21);
DigitalOut led(LED1);

// define variables
float level, temp;

int main() {
        // set up PWM parameters
        buzz.period(0.01);
        buzz = 0;

	while(1) {
		// read inputs
		level = tank_sens.read();
		temp = temp_sens.read();

		// check if tank is full
		if (level > 0.9) {
                led = 0;  // clear LED
                buzz = 0;  // clear buzzer
		}
        // check if tank level is too low
		else if (level < 0.1) {
                // create warble tone
                // transition from lower freq to high freq tone in 1s
                // CHECK THIS FOR LOOP INCREMENT
                for (float i = 1/LFREQ; i > 1/HFREQ; i -= DELAY/2*WSTEPS) {
                        buzz.period(i);
                        wait(DELAY)
                }
                led = !led;  // toggle LED
                // transition from high freq to low freq tone in 1s
                for (float i = 1/HFREQ; i < 1/LFREQ; i += DELAY/2*WSTEPS) {
                        buzz.period(i);
                        wait(0.05);
                }
                led = !led;  // toggle LED
	    }
        else {
                led = 0;  // clear LED
                buzz = 0;  // clear buzzer
                wait(DELAY);
        }
}
