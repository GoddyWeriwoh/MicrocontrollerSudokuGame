#ifndef TITTIMER_H
#define TITTIMER_H
#define         TI_NUMTIMERS                    32//////////////////////////////////////////////
#define         TI_MAXTICS                      30000 //Suficient per aprox. 30 o 40 segons
#include "TSIO.h"
//#include "RxSIO.h"
//#include "TxSIO.h"
void RSI_Timer0(void);
void TiInitTimer (void);
	/***********************
	//Postcondicions: Inicialitza el T.A.D. ês precondici¢ global haver cridat
	//                aquesta funci¢ quan es cridi qualsevol altra funci¢.
	\\***********************/
char TiGetTimer (void);
	/***********************
	//Precondicions: Hi ha algun timer lliure. Maxim TI_NUMTIMERS
	//Postcondicions: Retorna un handle per usar les funcions TiGetTics i
	//TiResetTics. Retorna -1 si no hi ha cap timer disponible.
	\\***********************/
void TiResetTics (unsigned char Handle);
	/***********************
	//Precondicions: Handle ha estat retornat per Ti_OpenTimer.
	//Postcondicions: Engega la temporitzaci¢ associada a 'Handle'.
	//              i agafa la referencia temporal del sistema
	\\***********************/
unsigned int  TiGetTics (unsigned char Handle);
	/***********************
	//Precondicions: Handle ha estat retornat per TiGetTimer.
	// La dist?ncia temmporal entre GetTics i ResetTics ha de ser menor
	// de TI_MAXTICS ms (actualment, 30 segons)
	//Postcondicions: Retorna els milisegons transcorreguts des de la crida
	//                a l'StartTimer del 'Handle'.
	\\***********************/
#endif