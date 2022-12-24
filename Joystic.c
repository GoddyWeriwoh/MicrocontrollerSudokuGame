#include "INPUT.h"
static char state;
static char X_high;

void initJoystick(){
    TRISAbits.TRISA2 = 1; 
    state = 0;
    X_high = 0;
    //Setting analogues
    ADCON1 = 13;//12
    //lr justif
    ADCON2 = 137;//9
    //ADCON0 = 9;    
    ADCON0 = 5;

}

void motorJoystick(){
 	switch(state) {
		case 0:
                ADCON0bits.GO = 1;
				state = 1;
		break;
		case 1:
                if(ADCON0bits.GO == 0){
                    state = 2;
                }
                             
        break;
        
        case 2:
        
			X_high = ADRESH;
            //LATD = X_high;
            
            if(X_high == 3){    
                ComoveMenuUp(1);
            }

            if(X_high == 0){
                ComoveMenuDown(1);
            }

            state = 0;
        break;
    }
}



