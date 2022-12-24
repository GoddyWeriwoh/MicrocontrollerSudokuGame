#include "CONTROLLER.h"
#define T1S 1000
char state;
char sentence[16]= "I AM LEGEND /0";
char counter_sent;
char received_char;
static char timer_16ms;

void initController(){
    OSCCON = 104;
    OSCTUNE = 0;
    timer_16ms = TiGetTimer();
    TRISA = 0;
    TRISCbits.TRISC6 = 1;
 state = 0;
 counter_sent = 0;
 received_char = 0;
}

void motorController(void) {
	switch(state) {
        case 0:         
            /*TiResetTics(timer_16ms);
            if(TiGetTics(timer_16ms) >= 10000){
                if(received_char == 'K'){
                  LATAbits.LATA3 = 1;
              }
              if(counter_sent < 15 /*|| received_char != 'K'*///){
                  /*if(SiIsAvailable()){
                  SiSendChar(sentence[counter_sent]);
                  counter_sent++;
                  state  = 1;
                  }
              }   
            }*/
            state  = 1;
        break;
        
        case 1:
            state = 0;
            if(SiHasReceived()){
                received_char = SiGetChar();
                if(SiIsAvailable()){
                  SiSendChar(received_char);
                 
                  }
                state = 0;
            }
        break;
        
	}
}