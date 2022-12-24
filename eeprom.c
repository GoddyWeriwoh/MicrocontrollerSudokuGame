#include "eeprom.h"

typedef struct{
char name[8] ;
char password[8];
}User;

static char state;
static char flag;
static char posi;
static char ok_to_store;
static User user1;
static char well_registered;
static char posi_info;
static char num_players;
static char notSame;
static char c;


void initEeprom(void){
    state = 0;
    flag = 0;
    posi = 0;
    ok_to_store = 0;
    well_registered = 0;
    posi_info = 0;
    num_players = 0;
    notSame = 0;
    c = 0;
}       

void EesetFlag(char flag_sett){
    flag = flag_sett;
}
char EeOkStore(void){
    return ok_to_store;
}
void EepromStoreUser(char name_char, char booli, char posi){
    if(booli == 1){
        user1.name[posi] = name_char;
    }
    if(booli == 2){
        user1.password[posi] = name_char;
    }
}
void writeToEeprom(char character, char position){
    EEADR = position;
    EEDATA = character;

    EECON1bits.EEPGD = 0;
    EECON1bits.CFGS = 0;
    EECON1bits.WREN = 1;
    INTCONbits.GIE = 0;
    EECON2 = 0x55;
    EECON2 = 0x0AA;
    EECON1bits.WR = 1;
    INTCONbits.GIE = 1;
    EECON1bits.WREN = 0;
}
char readFromEeprom(char position){
    EEADR = position;
    EECON1bits.EEPGD = 0;
    EECON1bits.CFGS = 0;
    EECON1bits.RD = 1;
    
    return EEDATA;
}

char EeRegisteredInfoOk(void){
    return well_registered;
}

void EesetNumPlayers(){
    num_players++; 
}

char EepromDataDifferent(void){
    return notSame;
}

void motorEeprom(void){
    switch(state){
        case 0:
            if(flag == 1){
                well_registered = 0;
                posi=0;
                posi = posi +(num_players * 16);
                posi_info = 1;
                state = 1;
            }
            if(flag == 2){
                well_registered = 0;
                posi=0;
                posi = posi +(num_players * 16);
                posi_info = 1;
                notSame = 0;
                state = 3;
            }
            break;
            
            case 1:
                if(EECON1bits.WR == 0){  
                 writeToEeprom(user1.name[posi_info], posi);
                 posi_info++;
                  posi++;
                    if(posi_info >= 8){
                        posi_info = 0;
                        state = 2; 
                    }
                      
                }
           
            break;
            case 2:
                if(EECON1bits.WR == 0){
                 writeToEeprom(user1.password[posi_info], posi);
                    posi++;
                    posi_info++;
                    if(posi_info >= 8){
                        well_registered = 1;
                        posi_info = 0;
                        flag = 0;
                        state = 0; 
                    }
                      
                }
           
            break;
            
        case 3:
            c = readFromEeprom(posi);
            if(readFromEeprom(posi) != user1.name[posi_info]){
                notSame = 1;
                state = 0;
            }
            else{
                posi_info++;
                posi++;
                if(posi_info >= 8){
                    posi_info = 0;
                   state = 4;
               }   
                
                
            }
            
        break;
            
            case 4:
                 
            if(readFromEeprom(posi) != user1.password[posi_info]){
                notSame = 1;
                state = 0;
            }
            else{
                posi_info++;
                posi++;
                if(posi_info >= 8){
                    well_registered = 1;
                   state = 0;
               }   
            }
            
            break;

    }
}