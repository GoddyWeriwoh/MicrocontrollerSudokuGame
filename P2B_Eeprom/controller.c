#include "CONTROLLER.h"
#define T1S 1000

char state;
char sentence[16]= "I AM LEGEND /0";
char counter_sent;
char received_char;
static char timer_16ms;

void initController(){
    TRISA = 0;
    OSCCON = 104;
    OSCTUNE = 0;
    timer_16ms = TiGetTimer();
    TRISA = 0;
    INTCON2bits.NOT_RBPU = 0;
 state = 0;
 counter_sent = 0;
 received_char = 0;
}

void motorController(void) {
	switch(state) {
        case 0:         
            if(!PORTBbits.RB0){
                state = 1;
            }
        break;
        
        case 1:
          
            EEADR = 0;
            EEDATA = 'G';

            EECON1bits.EEPGD = 0;
            EECON1bits.CFGS = 0;
            EECON1bits.WREN = 1;
            INTCONbits.GIE = 0;
            EECON2 = 0x55;
            EECON2 = 0x0AA;
            EECON1bits.WR = 1;
            INTCONbits.GIE = 1;
            EECON1bits.WREN = 0;

            state = 0;
        break;
        
	}
}