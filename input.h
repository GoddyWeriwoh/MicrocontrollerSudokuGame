#ifndef T_INPUT
#define T_INPUT
#include <xc.h>
#include "TTimer.h"
#include "controller.h"
#include "LcTLCD.h"



void initInput(void);
char InbuttonPressed(void);
void input_generated(void);
void motorInput(void);

#endif