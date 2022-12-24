#include "PRINTER.h"
static char state;
static char print_status;
static char user_tag[9] = "USER: \0";
static char pswd_tag[9] = "PSWD: \0";
static char login_tag[9] = "1.LOGIN\0";
static char register_tag[12] = "2.REGISTER\0";
static char print_ok;
static char position;


void initPrinter(){
    state = 0;
    print_status = 0;
    print_ok = 0;
    position = 0;
}

void PrPrint(char stat){
    print_status = stat;
}

char PrPrintOkay(void){
    return print_ok;
}

void motorPrinter(){
 	switch(state) {
		case 0:
            position = 0;
            if(print_status == 1){
                print_ok = 0;
                LcClear();
                LcGotoXY(0,0);
                state = 1;
            }
            if(print_status == 2){
                print_ok = 0;
                LcClear();
                LcGotoXY(0,0);
                state = 3;
            }
            
		break;
		case 1:
             LcPutChar(login_tag[position]);
             position++;
               if(login_tag[position] == '\0'){
                   LcGotoXY(0,1);
                   position = 0;
                  state = 2; 
               }              
        break;
        
        case 2:
             LcPutChar(register_tag[position]);
             position++;
               if(register_tag[position] == '\0'){
                  print_ok = 1;
                  print_status = 0;
                  state = 0; 
               }              
        break;
        
        case 3:
             LcPutChar(user_tag[position]);
             position++;
               if(user_tag[position] == '\0'){
                   LcGotoXY(0,1);
                   position = 0;
                  state = 4; 
               }              
        break;
        
        case 4:
             LcPutChar(pswd_tag[position]);
             position++;
               if(pswd_tag[position] == '\0'){
                    LcGotoXY(6,0);
                    print_ok = 1;
                  print_status = 0;
                  state = 0; 
               }              
        break;
       
    }
}



