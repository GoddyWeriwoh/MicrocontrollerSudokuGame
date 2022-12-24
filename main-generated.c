//#include <p18f4321.h>
#include <xc.h>
#include "CONTROLLER.h"
#include "TTimer.h"
#include "TSIO.h"
#include "LCD.h"

#pragma config OSC = HS // EXTERNAL OSCILLATOR OF 10Mhz.
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
    initInput1();
    initLCD();
    
    while(1){
    	input_generated();
    	controller_generated();
    }

    return;
}