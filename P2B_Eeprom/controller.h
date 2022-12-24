#ifndef T_CONTROLLER
#define T_CONTROLLER
#include <xc.h>
#include "TTimer.h"
#include "LcTLCD.h"

void initController(void);
void CoupdateKey(char key);
//Pre:
//Post:Updtes the key vrible in the controller
void CoKeyReceived(char updated);
//Pre:
//Post:Boolen 1 for new key received, and 0 if not.
char CoCheckKeyReceived(void);
//Pre: ..
//Post:returns 1 if key received nd 0 if not.
void motorController(void);
//Pre:
//Post:
void ComoveMenuUp(char status);
void ComoveMenuDown(char status);

#endif