void initJoystick(){

//Setting analogues
    ADCON1 = 12;
    ADCON2 = 9;
    ADCON0 = 9;
}

void motorJoystick(){
 	ADCON0 = 5;
     do{
      ADCON0bits.1 = 1;
       wait(); 
    }while(ADCON0.1 == 1);
    X_high = ADRESH;

    
    check_X_position();
}


wait(){
    
}
WAIT
  LOOP1
    MOVLW .1000
    INCF WAITER,1,0
    SUBWF WAITER,0,0
    BTFSC STATUS,Z,0
    CLRF WAITER,0
    
    MOVLW .0
    SUBWF WAITER,0,0
    BTFSS STATUS,Z,0
    GOTO LOOP1
  RETURN

void check_X_position(){
    if(X_high => 190){
        increment();
    }
    if(X_high <= 30){
        LATAbits.LATA3 ^= 1;
    }
}

