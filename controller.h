#ifndef T_CONTROLLER
#define T_CONTROLLER
#include <xc.h>
#include "TTimer.h"
#include "LcTLCD.h"
#include "TSIO.h"
#include "eeprom.h"
#include "printer.h"


void initController(void);

void CoupdateKey(char key);
//Pre:
//Post:Updtes the key vrible in the controller
void CoKeyReceived(char updated);
//Pre:
//Post:Boolen 1 for new key received, and 0 if not.

void motorController(void);
//Pre:
//Post:
void ComoveMenuUp(char status);
void ComoveMenuDown(char status);

char CoInGame(void);

void Co_one_Sec(void);
char CoJustGetNumberStat(void);
void CoKeyPressed(char boolean);
void CoLetterToShow(char keyy);

#endif