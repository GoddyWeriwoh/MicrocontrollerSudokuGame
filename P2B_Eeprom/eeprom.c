#include "eeprom.h"

static char state;
static char flag;
static char info;
static char address;


void initEeprom(void){
    state = 0;
    flag = 0;
    info = 0;
    address = 0;
 
}       
void EestoreUsername(char character, char address_s){
    info = character;
    address = address_s;
}
void EesetFlag(char flag_sett){
    flag = flag_sett;
}

void motorEeprom(void){
    switch(state){
        case 0:
            state = flag;
            break;
            
            case 1:
            EEADR = address;
            EEDATA = info;

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
            
            case 2:
            break;
    }
}