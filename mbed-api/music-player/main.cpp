#include "mbed.h"

#define SPEAKER p21
#define RED_LED p22
#define YELLOW_LED p23
#define BLUE_LED p24
#define AIN1 p15
#define AIN2 p16

// define the frequency for the basic music notes
# define Do     0.5
# define Re     0.45
# define Mi     0.4
# define Fa     0.36
# define So     0.33
# define La     0.31
# define Si     0.3
# define No     0

// define the beat length as a portion of the note
# define b1     0.5
# define b2     0.25
# define b3     0.125
# define b4     0.075

// hardcode the music piece
float note[] = {Mi,No,Mi,No,Mi,No, Mi,No,Mi,No,Mi,No, 
		Mi,No,So,No,Do,No,Re,No,Mi,No, Fa,No,Fa,No,Fa,No,Fa,No, 
		Fa,No,Mi,No,Mi,No,Mi,No,Mi,No, Mi,No,Mi,No,Re,No,Mi,No,Mi, 
		Re,No,So,No};
float beat[] = {b3,b3,b3,b3,b2,b2, b3,b3,b3,b3,b2,b2, 
		b3,b3,b3,b3,b3,b3,b3,b3,b2,b1, b3,b3,b3,b3,b3,b3,b3,b3, 
		b3,b3,b3,b3,b3,b3,b4,b4,b4,b4, b4,b4,b4,b4,b4,b4,b2,b4,b1, 
		b1,b3,b2,b1};

// analog inputs
AnalogIn volume(AIN1);
AnalogIn speed(AIN2);

// pwm outputs
PwmOut speaker(SPEAKER);
PwmOut red(RED_LED);
PwmOut yellow(YELLOW_LED);
PwmOut blue(BLUE_LED);

// time ticker for periodic interrupts
Ticker timer;

// static variables
static int k;
static float vol;
static float sp;

// ticker ISR
void timer_ISR() {
	// check if melody is finished
	if (k < (sizeof(note)/sizeof(int))) {

		// check if the note is a silence
		if (note[k] == No) {
			speaker = 0; // silence
		}
		else {
			// play the note
			speaker.period(0.01 * note[k]);
			speaker = vol;
		}

		k++;
		// set new timer configuration
		timer.attach(&timer_ISR, ((beat[k]/2) + (sp/2)));

		// set the LEDs
		red = note[k] // represents the note being played
		yellow = speaker; // represents the volume
		blue = sp; // represents the speed
	}
	else {
		// reset the melody
		k = 0;
		speaker = 0;
	}
}


int main() {
	timer.attach(&timer_ISR, 0.1); // set timer to interrupt every 0.1s
	k = 0; // initialize the note index
	while(1) {
		vol = volume.read(); // read the volume
		sp = speed.read(); // read the speed
		wait(0.1); // wait for 0.1s
	}
}
