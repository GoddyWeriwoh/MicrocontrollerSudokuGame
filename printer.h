#ifndef PRINTER_H
#define PRINTER_H
#include <xc.h>
#include "printer.h"
#include "LcTLCD.h"

void motorPrinter(void);
void initPrinter(void);
void PrPrint(char stat);
char PrPrintOkay(void);
#endif
