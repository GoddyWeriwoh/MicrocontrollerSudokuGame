
#include "INPUT.h"

#define T16MS 16
static char timer_16ms;
static char state;

void initInput1(void){
timer_16ms = TiGetTimer();
TRISB = 1;
state = 0;
}

char InbuttonPressed(void){
	if(PORTB.RB0 == 1 || PORTB.RB1 == 1 || PORTB.RB2 == 1){
		return 1;
	}
	return 0;
}

void input_generated(void) {
	switch(state) {
		case 0:
			if (InbuttonPressed() == 1;) {
				TiResetTimer(Timer);
				state = 1;
			}
		break;
		case 1:
			if ((TiGetTics(timer_16ms) >= T16MS) && (InbuttonPressed() == 1)) {
				CoKeyReceived(1);
				CoUpdateKey(PORTB);
				state = 2;
			}
			else if ((TiGetTics(timer_16ms) >= T16MS) && !(InbuttonPressed() == 1)) {
				state = 0;
			}
		break;
		case 2:
			if (InbuttonPressed() == 0) {
				TiResetTimer(timer_16ms);
				state = 3;
			}
		break;
		case 3:
			if (TiGetTics(timer_16ms) >= T16MS) {
				state = 4;
			}
		break;
		case 4:
			state = 0;
		break;
	}
}