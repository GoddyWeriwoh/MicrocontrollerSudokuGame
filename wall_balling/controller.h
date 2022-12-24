#ifndef T_CONTROLLER
#define T_CONTROLLER
#include <xc.h>
#include "TTimer.h"
#include "sensor.h"

void initController(void);
void motorController(void);
void CoSensorTouched(char);

#endif