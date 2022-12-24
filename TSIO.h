#ifndef T_SIO
#define T_SIO
#include <xc.h>


void initSIO(void);
void SiSendChar(char my_byte);
	// PRE: SIO is available to Send.
	// POST: Sends my_byte using the EUSART.
char SiIsAvailable(void);
	// PRE: --
	// POST: Returns 1 if SIO is ready to SEND. Otherwise, returns 0.
	// Returning the TRMT flag of the TXSTA register to check if we can transmit bytes again.
char SiHasReceived(void);
//PRE:--
//POST: Returns 1 if eusart has received, or 0.
char SiGetChar(void);
//Pre: siHasReceived
//Post: returns the first received byte.
//warning:destructive reading

#endif