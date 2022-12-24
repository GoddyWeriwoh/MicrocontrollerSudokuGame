#include "LCD.h"

#define T16MS 16
static char timer_16ms;

void command(unsigned int comand) //Sending initialing commands to lcd
{
LATD=comand; 
LATCbits.LATC6=0; //rs
LATCbits.LATC5=0; //rw
LATCbits.LATC7=0; //en
delay_t();
LATCbits.LATC7=1; //en
delay_t();
LATCbits.LATC7=0; //en
}

void lcddata(char value) //Sending data to be displayed on lcd screen
{
LATD=value; 
LATCbits.LATC6=0; //rs
LATCbits.LATC5=1; //rw
LATCbits.LATC7=0; //en
delay_t();
LATCbits.LATC7=1; //en
delay_t();
LATCbits.LATC7=0; //en
}

void delay_t(void)
{
unsigned int i,j;
for(i=0;i<3000;i++)
for(j=0;j<10;j++);
}

void initLCD(void){
	TRISC = 0x00;
	TRISD = 0x00;
	//LATD = 0;
	delay_t(); command(0x30); delay_t(); command(0x30); delay_t(); command(0x30);
	delay_t(); command(0x38); delay_t(); command(0x01); delay_t(); command(0x0F);
	delay_t(); command(0x0C); delay_t(); 
	command(0x80); //Lcd first row selected for data printing
	delay_t();
}

void showAccessMenuu(void){
    command(0x80); //Lcd first row selected for data printing
	delay_t();
	lcddata('1'); delay_t(), lcddata('.'); delay_t(); lcddata(' '); delay_t(); lcddata('L');
	delay_t(); lcddata('O'); delay_t(); lcddata('G'); delay_t(); lcddata('I');
	delay_t(); lcddata('N'); delay_t();

	command(0xC0); //Command to jump to second row of lcd
	delay_t(); lcddata('2'); delay_t(); lcddata('.'); delay_t(); lcddata(' '); delay_t(); lcddata('R');
	delay_t(); lcddata('E'); delay_t(); lcddata('G'); delay_t(); lcddata('I');
	delay_t(); lcddata('S'); delay_t(); lcddata('T'); delay_t(); lcddata('E');
	delay_t(); lcddata('R'); delay_t(); 
}
