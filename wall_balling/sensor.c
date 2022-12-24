#include "CONTROLLER.h"
static char state;

void motorSensor() {
         
	switch(state) {
		case 0:
            if(PORTBbits.PORTB0 == 1){
                CoSensorTouched(1);
            }
		break;
        
        
	}
    
}