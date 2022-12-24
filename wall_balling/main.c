//#include <p18f4321.h>
#include <xc.h>
#include "CONTROLLER.h"
#include "TTimer.h"

#pragma config OSC = INTIO2 // EXTERNAL OSCILLATOR OF 10Mhz. or internal of 4MHz
#pragma config PBADEN = DIG
#pragma config MCLRE = OFF
#pragma config DEBUG = OFF
#pragma config PWRT = OFF
#pragma config BOR = OFF
#pragma config WDT = OFF
#pragma config LVP = OFF

char aux = 0;

void __interrupt() RSI_High(void){
    RSI_Timer0();
}

void main(void){
    TiInitTimer();
    initController();
    SpInitSpeaker();
    
        while(1){    
        motorController();
        motorSpeaker();
        motorSensor();
    }
    return;
}