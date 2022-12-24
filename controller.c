#include "CONTROLLER.h"
#define T1S 1000
#define T100MS 100

typedef struct{
char name[8] ;
char password[8]; 
}User;

//"GeeGeo/0"
static char timer_TimeRem;
static char state;
static char register_status;
static char updated_status;
static char key_co;
static char moveDown;
static char moveUp;
static char menu_counter;
static char seconds[2];
static char mins[2];
static char X_high;
static char gameStatus;
static char sentence[16];
static char num_letters;
static char position;
static char get_just_numbers;
static char key_coo;
static char key_pressed;
static User user;
static char instate6;
    
static char mins_tmp_first ;
static char mins_tmp_last ;
static char secs_tmp_first;
static char secs_tmp_last;
static char fromStateFive = 0;
           

char CouserExists(void){
    return 0;
}
void initController(void){
    OSCCON = 104;
    OSCTUNE = 0;
    timer_TimeRem = TiGetTimer();
	state = 0;
	register_status = 0;
	updated_status = 0;
	key_co = 0;
    key_coo = 0;
    moveDown = 0;
    moveUp = 0;
    menu_counter = 0;
    mins[1] = '2' - '0';
    mins[0] = '9' - '0';
    seconds[0] = '9' - '0';
    seconds[1] = '5' - '0';
    gameStatus = 0;
    num_letters = 0;
    position = 0x0000;
    get_just_numbers = 0;
    key_pressed = 0;
    fromStateFive = 0;
     mins_tmp_first = 0;
     mins_tmp_last = 0;
     secs_tmp_first = 0;
     secs_tmp_last = 0;
     instate6 = 0;
}

void CoupdateKey(char key){
	key_co = key;
}

void CoKeyReceived(char updated){
	updated_status = updated;
}

void ComoveMenuUp(char bool){
    moveUp = bool;
}
void ComoveMenuDown(char bool){
    moveDown = bool;
}
void CoLetterToShow(char keyy){
    key_coo = keyy;
}

void showMenuF(char menuNumber){
    gameStatus = 0;
    LcClear();
    if(menuNumber == 0){
        LcGotoXY(0,0);LcPutChar('1');LcGotoXY(1,0);LcPutChar('.');LcGotoXY(2,0);LcPutChar('P'); LcGotoXY(3,0);LcPutChar('L'); LcGotoXY(4,0);LcPutChar('A');LcGotoXY(5,0);LcPutChar('Y');LcGotoXY(6,0);
        LcGotoXY(0,1);LcPutChar('2');LcGotoXY(1,1);LcPutChar('.');LcGotoXY(2,1);LcPutChar('M');LcGotoXY(3,1);LcPutChar('O');LcGotoXY(4,1);LcPutChar('D'); LcGotoXY(5,1);LcPutChar('I'); LcGotoXY(6,1);LcPutChar('F');LcGotoXY(7,1);LcPutChar('Y');LcGotoXY(8,1);LcPutChar(' ');LcGotoXY(9,1);LcPutChar('T');LcGotoXY(10,1);LcPutChar('I');LcGotoXY(11,1);LcPutChar('M');LcGotoXY(12,1);LcPutChar('E');
        LcGotoXY(7,0);
    }
    if(menuNumber == 1){
        LcGotoXY(0,0);LcPutChar('2');LcGotoXY(1,0);LcPutChar('.');LcGotoXY(2,0);LcPutChar('M');LcGotoXY(3,0);LcPutChar('O');LcGotoXY(4,0);LcPutChar('D'); LcGotoXY(5,0);LcPutChar('I'); LcGotoXY(6,0);LcPutChar('F');LcGotoXY(7,0);LcPutChar('Y');LcGotoXY(8,0);LcPutChar(' ');LcGotoXY(9,0);LcPutChar('T');LcGotoXY(10,0);LcPutChar('I');LcGotoXY(11,0);LcPutChar('M');LcGotoXY(12,0);LcPutChar('E');
        LcGotoXY(0,1);LcPutChar('3');LcGotoXY(1,1);LcPutChar('.');LcGotoXY(2,1);LcPutChar('T'); LcGotoXY(3,1);LcPutChar('O'); LcGotoXY(4,1);LcPutChar('P');LcGotoXY(5,1);LcPutChar(' ');LcGotoXY(6,1);LcPutChar('5');LcGotoXY(7,1);
        LcGotoXY(13,0);
    }
    if(menuNumber == 2){
        LcGotoXY(0,0);LcPutChar('3');LcGotoXY(1,0);LcPutChar('.');LcGotoXY(2,0);LcPutChar('T'); LcGotoXY(3,0);LcPutChar('O'); LcGotoXY(4,0);LcPutChar('P');LcGotoXY(5,0);LcPutChar(' ');LcGotoXY(6,0);LcPutChar('5');LcGotoXY(7,0);
        LcGotoXY(0,1);LcPutChar('4');LcGotoXY(1,1);LcPutChar('.');LcGotoXY(2,1);LcPutChar('L');LcGotoXY(3,1);LcPutChar('O');LcGotoXY(4,1);LcPutChar('G'); LcGotoXY(5,1);LcPutChar('O'); LcGotoXY(6,1);LcPutChar('U');LcGotoXY(7,1);LcPutChar('T');
        LcGotoXY(8,0);
    }
    if(menuNumber == 3){
        LcGotoXY(0,0);LcPutChar('4');LcGotoXY(1,0);LcPutChar('.');LcGotoXY(2,0);LcPutChar('L');LcGotoXY(3,0);LcPutChar('O');LcGotoXY(4,0);LcPutChar('G'); LcGotoXY(5,0);LcPutChar('O'); LcGotoXY(6,0);LcPutChar('U');LcGotoXY(7,0);LcPutChar('T');
        LcGotoXY(8,0);
    }
}
void showTimeTopPanel(){
        LcClear();
            LcGotoXY(0,0);LcPutChar('T');LcGotoXY(1,0);LcPutChar('I');LcGotoXY(2,0);LcPutChar('M'); LcGotoXY(3,0);LcPutChar('E'); LcGotoXY(4,0);LcPutChar(' ');LcGotoXY(5,0);LcPutChar('R');LcGotoXY(6,0);LcPutChar('E');LcGotoXY(7,0);LcPutChar('M');LcGotoXY(8,0);LcPutChar('A');LcGotoXY(9,0);LcPutChar('I');LcGotoXY(10,0);LcPutChar('N');LcGotoXY(11,0);LcPutChar('I');LcGotoXY(12,0);LcPutChar('N');LcGotoXY(13,0);LcPutChar('G');LcGotoXY(14,0);LcPutChar(':');LcGotoXY(15,0);
}
void showTimeRemaining(){
    //LcClear();
        LcGotoXY(0,1);LcPutChar(mins[1] + '0');LcGotoXY(1,1);LcPutChar(mins[0]+ '0');LcGotoXY(2,1);LcPutChar(':');LcGotoXY(3,1);LcPutChar(seconds[1]+ '0');LcGotoXY(4,1);LcPutChar(seconds[0]+ '0'); LcGotoXY(5,1);
}

void showModifyTime(){
    LcClear();
        LcGotoXY(0,0);LcPutChar('M');LcGotoXY(1,0);LcPutChar('O');LcGotoXY(2,0);LcPutChar('D'); LcGotoXY(3,0);LcPutChar('I'); LcGotoXY(4,0);LcPutChar('F');LcGotoXY(5,0);LcPutChar('Y');LcGotoXY(6,0);LcPutChar(' ');LcGotoXY(7,0);LcPutChar('T');LcGotoXY(8,0);LcPutChar('I');LcGotoXY(9,0);LcPutChar('M');LcGotoXY(10,0);LcPutChar('E');LcGotoXY(11,0);LcPutChar(':');LcGotoXY(12,0);
        LcGotoXY(0,1);
}

char CoInGame(){
    return gameStatus;
}


char CoJustGetNumberStat(){
    return get_just_numbers;
}
 void CoKeyPressed(char boolean){
     key_pressed = boolean;
 }

void motorController(void) {
         
	switch(state) {
		case 0:
            register_status = 0;
            num_letters = 0;
            PrPrint(1);
            if(PrPrintOkay()){
               LcCursorOff();
                state = 1;  
            } 
		break;
        
		case 1:
            gameStatus = 1;
            get_just_numbers = 1;
            if(key_pressed){
                if(updated_status){
                    if(key_co=='1'){   
                        PrPrint(2);
                        if(PrPrintOkay()){
                            get_just_numbers = 0;
                            LcCursorOn();
                            num_letters = 0;
                            state = 2;  
                        }   
                        
                    }
                    if(key_co=='2'){
                        register_status = 1;
                        PrPrint(2);
                        if(PrPrintOkay()){
                            get_just_numbers = 0;
                            LcCursorOn();
                            num_letters = 0;
                            state = 2;  
                        }
                    }
                    updated_status = 0;
                }  
                key_pressed = 0;
            }

		break;
		case 2:
           //Username
             if(key_pressed){
                if(key_coo == '#'){
                        user.name[num_letters] = '/0';  
                        LcGotoXY(6,1);
                        num_letters = 0;
                        state = 3; 
                    }                
                if(key_coo == '*'){
                        state = 0;
                    }               
                if(key_coo != '#' && key_coo != '*' ){
                    LcPutChar(key_coo);//show letter
                    if(updated_status){
                         
                        user.name[num_letters++] = key_co;
                        char c = 0;
                        if(num_letters == 7){
                            key_co = 0;
                            LcDelete();
                            user.name[num_letters] = '/0';
                            LcGotoXY(6,1);
                            num_letters = 0;           
                            state = 3; 
                        }
                    updated_status = 0;
                    }
                }
                key_pressed = 0;
            }
                
		break;
        
        case 3:
            if(num_letters < 8){
                    EepromStoreUser(user.name[num_letters], 1, num_letters);
               num_letters++;
            }
            if(num_letters == 8){    
                     num_letters = 0;
                  
                    if(instate6){
                        state = 5;
                    }
                    else{
                        state = 4; 
                    }
            }
        break;
            
        case 5:
            if(num_letters < 8){
                    EepromStoreUser(user.password[num_letters], 2, num_letters);          
               num_letters++;
            }
            if(num_letters == 8){
                    num_letters = 0;
                   
                    fromStateFive = instate6;
                    state = 6;
                }

        break;
        
		case 4:   
            //Password
            if(key_pressed){
                if(key_coo == '#'){
                        user.password[num_letters] = '/0';  
                        LcGotoXY(6,1);
                        num_letters = 0;
                        state = 5;               
                    }
                if(key_coo == '*'){
                        state = 0;
                    }                
                if(key_coo != '#' && key_coo != '*' ){
                    LcPutChar(key_coo);
                    if(updated_status){
                         
                        user.password[num_letters++] = key_co;
                        
                        if(num_letters == 7){
                            LcDelete();
                            user.password[num_letters] = '/0';
                            LcGotoXY(6,1);
                            num_letters = 0;
                            
                            state = 5; 
                        }
                    updated_status = 0;
                    }
                }
                key_pressed = 0;
            }
                
		break;
		case 6:
            instate6 = 1;
            if(register_status){
                    if(EeRegisteredInfoOk()){
                        
                        register_status = 0;
                        LcClear();                     
                        //Printing
                        PrPrint(2);
                        if(PrPrintOkay()){
                            get_just_numbers = 0;
                            LcCursorOn();
                            state = 2;  
                        }                      
                    }
                    else{
                       EesetFlag(1); 
                       }
            }
            else{   
                if(!fromStateFive){
                   state = 3;  
                }
                else{
                    EesetFlag(2);
                  if(EepromDataDifferent()){
                      LATAbits.LATA3 ^= 1;
                     state = 0;         
                  }
                  else{
                    if(EeRegisteredInfoOk()){
                     LcClear();
                     PrPrint(3);
                     showMenuF(menu_counter);
                     EesetNumPlayers();
                     state = 7;    
                     } 
                  }  
                }
            }
            
		break;
        
        
		case 7:	
            position = 0;
            if(key_pressed){ 
 				if(updated_status){
                    
                    if(key_co == '*'){
                        
                        state = 0;
                    }
                    
                    if((key_co == '#') && menu_counter == 0){
                        
                            state = 8; 
                    }
                    if((key_co == '#') && menu_counter == 1){

                            state = 9;  
                    }
                     updated_status = 0;
				}
                key_pressed = 0;
            }
	
            if(moveDown){
             moveDown = 0;
             //LATAbits.LATA3 ^= 1;
                if(menu_counter < 5){
                    showMenuF(menu_counter++);
                }
            }
            if(moveUp){
                moveUp = 0;
                //LATAbits.LATA4 ^= 1; 
                if(menu_counter > 0){
                    showMenuF(menu_counter--);

                }
            } 
            break;
                    
        case 8:
            LATAbits.LATA3 ^= 1;
            if(SiIsAvailable()){  
                SiSendChar(user.name[num_letters++]);
            }
            if(SiHasReceived){
                char received = SiGetChar();
                if(received == 'K'){
                    num_letters = 0;
                    showTimeTopPanel();
                    LcCursorOff();
                    state = 10;
                }
            }
        break;
            
        case 10:
            gameStatus = 1;
            showTimeRemaining();
            if(TiGetTics(timer_TimeRem) >= T1S){
            TiResetTics(timer_TimeRem);
                seconds[0]--;
                if(seconds[0] == 0){
                seconds[1]--;
                seconds[0]=9;
                    //showTimeRemaining();
                    if(seconds[1] == 0){
                        mins[0]--;
                        seconds[1]=5;
                        //showTimeRemaining();
                        if(mins[0] == 0){
                            mins[1]--;
                            mins[0]=5;
                            //showTimeRemaining();    
                        }
                    }
                }
            }
                if(mins[1] == 0){
                    if(SiIsAvailable()){  
                        SiSendChar('F');
                        state = 0;
                    }
                }
        break;
		
		
		case 9:
			get_just_numbers = 1;
            if(updated_status){
                updated_status = 0;
                if((key_co == '#')){
                        mins[1] = mins_tmp_first;
                        mins[0] = mins_tmp_last;
                        seconds[1] = secs_tmp_first;
                        seconds[0] = secs_tmp_last;
                        state = 4;
                        }
                if((key_co == '*')){   
                    state = 4; 
                }
                 
                else{
                    LcPutChar(key_co);
                  
                    if(num_letters == 0){
                        mins_tmp_first = key_co;
                    }
                    if(num_letters == 1){
                        mins_tmp_last = key_co;
                    }
                    if(num_letters == 2){
                        LcPutChar(':');
                    }
                    if(num_letters == 3){
                        secs_tmp_first = key_co;
                    }
                    if(num_letters == 4){
                        secs_tmp_last = key_co;
                    }
                    
                    num_letters++;    
                    /*if(num_letters == 5){
                        /*if((key_co == '$' || key_co == ' ' ||key_co == '@')){
                        LcGotoXY(0,1);
                        mins[1] = mins_tmp_first;
                        mins[0] = mins_tmp_last;
                        seconds[1] = secs_tmp_first;
                        seconds[0] = secs_tmp_last;
                        state = 4;
                        }
                        else{
                           num_letters = 0;
                           LcGotoXY(0,1);
                        //}
                    }*/
                    
                                               
                //}
                
                //updated_status = 0;
            //}
                }
            }
        
		break;
        
	}
    
}