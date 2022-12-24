#ifndef EEPROM_H
#define EEPROM_H
#include <xc.h>
#include "TTimer.h"


void initEeprom(void);
void motorEeprom(void);
void EesetFlag(char flag_sett);
void EepromStoreUser(char name_char, char booli, char posi);
char EeRegisteredInfoOk(void);
void EesetNumPlayers(void);
char EepromDataDifferent(void);
#endif
