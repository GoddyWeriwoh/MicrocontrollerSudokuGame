#include "SPEAKER.h"

#define T1MS 1
#define T1MIN 60000
#define T5S 100
#define T1S 1000
#define T10S 10000



static char timer_1min;
static char timer_5secs;
static char timer_1ms;
static char state;
static char counter;


void SpInitSpeaker(void){
    timer_1min = TiGetTimer();
    timer_5secs = TiGetTimer();
    timer_1ms = TiGetTimer();
    TiResetTics(timer_1min);
    state = 0;
    counter = 0;
    LATAbits.LATA5 = 0;
}

void motorSpeaker(void) {
	switch(state) {
		case 0:
            if(CoInGame()){
            TiResetTics(timer_1min);
            counter = 0;
                state = 1;
            }
                
        break;
        
        case 1:
            if(timer_1min == T1S){
                TiResetTics(timer_1min);
                counter++;
                if(counter == 10){
                 TiResetTics(timer_5secs);
                TiResetTics(timer_1ms);
                TiResetTics(timer_1min);
                state = 2;
                }   
            }
            
        break;
 
		case 2:
            if(TiGetTics(timer_5secs) == T5S){
                TiResetTics(timer_5secs);
                TiResetTics(timer_1ms);
                state = 0;
            }
			if(TiGetTics(timer_1ms) == T1MS){
            TiResetTics(timer_1ms);
                    state = 3;
                    LATAbits.LATA5 = 1;
                }
		break;
        
        case 3:
		if(TiGetTics(timer_1ms) == T1MS){
            TiResetTics(timer_1ms);
                    state = 2;
                    LATAbits.LATA5 = 0;
                }
		break;
	}
}