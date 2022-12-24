//#include <p18f4321.h>
#include <xc.h>
#include "CONTROLLER.h"
#include "TTimer.h"
#include "TSIO.h"
#include "LcTLCD.h"


#pragma config OSC = INTIO2 // EXTERNAL OSCILLATOR OF 10Mhz.
#pragma config PBADEN = DIG
#pragma config MCLRE = OFF
#pragma config DEBUG = OFF
#pragma config PWRT = OFF
#pragma config BOR = OFF
#pragma config WDT = OFF
#pragma config LVP = OFF


void __interrupt() RSI_High(void){
 _TiRSITimer();
}

void main(void){
    TiInitTimer();
    initController();
    initSIO();
        while(1){     
    	motorController();
    }
    return;
}