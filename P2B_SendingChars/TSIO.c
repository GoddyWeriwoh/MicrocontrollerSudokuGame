#include "TSIO.h"
#include <xc.h>

void initSIO(void){
    TXSTA = 32;
    RCSTA = 144;
    BAUDCONbits.BRG16 = 1;
    TRISCbits.TRISC6 = 1;
    TRISCbits.TRISC7 = 1;

    //loading bauder
    SPBRG = 25;
//FOSC = 10Mhz, Baudrate of 9600
	/*TXSTA = 0x24;
	RCSTA =  0x90;//b'1001 0000'
	BAUDCONbits.BRG16 = 0;*/
	//SPRGB = 64;
}

char SiIsAvailable(void){
	// PRE: --
	// POST: Returns 1 if SIO is ready to SEND. Otherwise, returns 0.
	// Returning the TRMT flag of the TXSTA register to check if we can transmit bytes again.
	return (TXSTAbits.TRMT == 1);

}
void SiSendChar(char my_byte){
	// PRE: SIO is available to Send.
	// POST: Sends my_byte using the EUSART.
	
	TXREG = my_byte;
}
char SiHasReceived(void){
	
//PRE:--
//POST: Returns 1 if eusart has received, or 0.
  return (PIR1bits.RCIF == 1);
}
char SiGetChar(void){
//Pre: siHasReceived
//Post: returns the first received byte.
//warning:destructive reading
    return RCREG;
}