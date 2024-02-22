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
# define No     0.0

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


int main() {

	return 0;
}
