#include "INPUT.h"

#define T16MS 16
#define T1S 1000
static char timer_16ms;
static char state;
static char key;
static unsigned char cols;
static unsigned char rows;
static char timer_1S;
static char sms;
static char old_key ;
static char new_key;
static char repeat;
static char cols_two;
static char key_last;
static char matrixKeypad[4][3][4] = {
                                {
                                   {'1','1','1','1'},
                                   {'a','b','c','2'},
                                   {'d','e','f','3'}
                                },
                                {
                                   {'g','h','i','4'},
                                   {'j','k','l','5'},
                                   {'m','n','o','6'}
                                },
                                {
                                   {'p','r','s','7'},
                                   {'t','u','v','8'},
                                   {'w','x','y','9'}
                                },
                                {
                                   {'*','*','*','*'},
                                   {'0','0','0','0'},
                                   {'#','#','#','#'}
                                }
                               };


void initInput(void){
timer_16ms = TiGetTimer();
state = 0;
key = 0;
cols = 0; 
rows = 0;
sms = 0;
timer_1S = TiGetTimer();
old_key = 0;
new_key = 0;
repeat = 0;
cols_two = 0;
key_last = 0;

//Setting pull-ups
//INTCON2bits.NOT_RBPU = 0;

//outputs
    TRISBbits.RB3 =  TRISBbits.RB4 = TRISBbits.RB5 = TRISBbits.RB6 = TRISBbits.RB7 = 0;
    
    //Inputs
    TRISBbits.RB2 =  TRISBbits.RB1 = TRISBbits.RB0 = 1;
    
    //initialising outputs
    LATBbits.LATB3 = LATBbits.LATB4 = LATBbits.LATB5 = LATBbits.LATB6 = TRISBbits.RB7 = 0;


}

void decodeKey(){
    if(cols == 4){
        cols = 3;
    }
    if(cols_two == 4){
        cols_two = 3;
    }
    if(rows == 0){
        rows = 4; 
    }
    
    key = matrixKeypad[rows - 1][cols-1][sms];
    
    if(CoJustGetNumberStat()){
        key = matrixKeypad[rows-1][cols-1][3];   
    }
    old_key = matrixKeypad[rows-1][cols-1][3];
    new_key = matrixKeypad[rows-1][cols_two-1][3];
}

void motorInput(void) {
	switch(state) {
		case 0:
            repeat = 0;
                if (PORTBbits.RB0 && PORTBbits.RB1 && PORTBbits.RB2) {
                 state = 4;
			}
            else{
                cols = ~(PORTB | 0xF8);
                TiResetTics(timer_1S);
				TiResetTics(timer_16ms);
                state = 1;
            }
		break;
		case 1:
			if ((TiGetTics(timer_16ms) >= T16MS)) {
                if (PORTBbits.RB0 && PORTBbits.RB1 && PORTBbits.RB2) {
                    decodeKey();
                    CoLetterToShow(key);
                    key_last = key;
                    if(repeat){
                       if(new_key == old_key){
                            sms++;
                            if(sms >= 4){
                                sms = 0;
                            }
                            LcDelete();
                       } 
                    }
                    state = 2;
                    
                }
                
                TiResetTics(timer_16ms);
			}
			
		break;
		case 2:
			if (TiGetTics(timer_16ms) >= T16MS) {
                CoKeyPressed(1);  
                TiResetTics(timer_16ms);
				state = 3;
			}
		break;
        case 3:
			if (TiGetTics(timer_1S) >= T1S) {
                CoupdateKey(key_last);
                CoKeyReceived(1);
                TiResetTics(timer_1S);
                sms = 0;
                state = 0;
			}
            else{
                repeat = 1;
                state = 4;
                if(!PORTBbits.RB0 || !PORTBbits.RB1 || !PORTBbits.RB2){
                    cols_two = ~(PORTB | 0xF8);
                    TiResetTics(timer_16ms);
                    state = 1; 
                }
                
            }
		break;
        
        case 4 :
            rows = (rows + 1) % 4;
                switch(rows){
                    case 0:
                        LATBbits.LATB5 = 1;
                        LATBbits.LATB6 = 0;
                    break;
                    
                    case 1:
                       LATBbits.LATB3 = 0;
                        LATBbits.LATB6 = 1; 
                    break;
                    
                    case 2:
                        LATBbits.LATB3 = 1;
                        LATBbits.LATB4 = 0;
                    break;
                    
                    case 3:
                        LATBbits.LATB4 = 1;
                        LATBbits.LATB5 = 0;
                    break;
                }
                  
                if(repeat){
                    state = 3;
                }
                else{
                 state = 0;   
                }
                  
            break;
	}
}