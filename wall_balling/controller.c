#include "CONTROLLER.h"
#define T1S 1000
#define T100MS 100

static char timer_TimeRem;
static char state;
static char ctouch;

void initController(void){
    TRISA = 0;
    TRISB = 1;
    OSCCON = 104;
    OSCTUNE = 0;
    timer_TimeRem = TiGetTimer();
	state = 0;
}

void CoSensorTouched(char touch){
    ctouch = touch;
}

void motorController(void) {
         
	switch(state) {
		case 0:
            TiResetTics(timer_TimeRem);
            state = 1;
		break;
        case 1:
            if(TiGetTics(timer_TimeRem) >= T1S){
                LATAbits.LATA3 = 1;
                state = 2;
            }
		break;
        case 2:
            if(ctouch){
                LATAbits.LATA3 = 1;
                state = 0;
            }
		break;
        
	}
    
}