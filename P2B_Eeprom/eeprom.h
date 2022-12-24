#ifndef EEPROM_H
#define EEPROM_H
#include <xc.h>
#include "TTimer.h"


void initEeprom(void);
void motorEeprom(void);
void EestoreUsername(char char_to_store, char position);
void EesetFlag(char flag_sett);

#endif
