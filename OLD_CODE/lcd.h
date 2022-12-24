#ifndef T_LCD
#define T_LCD
#include <xc.h>
#include "TTimer.h"

void initLCD(void);
void showRegisterMenu(void);
void showAccessMenuu(void);
void delay_t(void);
void lcddata(char value); //Sending data to be displayed on lcd screen
void command(unsigned int comand); //Sending initialing commands to lcd


#endif