//INT0
char TiGetTimer(void);
void TiResetTics(char handler);
unsigned int TiGetTics(void);

//INT1
void CoupdateKey(char key);
//Pre:
//Post:Updtes the key vrible in the controller
void CoKeyReceived(char updated);
//Pre:
//Post:Boolen 1 for new key received, and 0 if not.

//INT2
void LcInit(char rows, char columns);
// Pre: Rows = {1, 2, 4}  Columns = {8, 16, 20, 24, 32, 40 }
// Pre: There is a free timer
// Pre: It needs 40ms of tranquility between the VCC raising and this constructor being called.
// Post: This routine can last up to 100ms
// Post: The display remains cleared, the cursor turned off and at the position 0, 0.
void LcEnd(void);
// The destructor
void LcClear(void);
// Post: Clears the display and sets the cursor to its previous state. 
// Post: The next order can last up to 1.6ms. 
void LcCursorOn(void);
// Post: Turn on the cursor
// Post: The next order can last up to 40us. 
void LcCursorOff(void);
// Post: Turns off the cursor
// Post: The next order can last up to 40us. 
void LcGotoXY(char Column, char Row);
// Pre : Column between 0 and 39, row between 0 and 3. 
// Post: Sets the cursor to those coordinates. 
// Post: The next order can last up to 40us. 
void LcPutChar(char c);
// Post: Paints the char in the actual cursor position and increments 
// its position. If the column gets to 39 it returns to 0.
// The row of the LCD is increased when this happens until the second
// row and then it is reset back to row 0 if it has 2 rows total. 
// If the LCD has 4 rows it will reset back to row 0 when it
// reaches row 4 and the columns will go till 39 before reseting to 0.
// The one row LCDs returns to 0 when a column gets to 39. 
// The row is never increased. 
	// The char is written
void LcPutString(char *s);
// Post: Paints the string from the actual cursor position. 
// The coordinate criteria is the same as the LcPutChar. 
// Post: Can last up to 40us per char of a routine output.



//INT3
void initJoystick();
void updateJoystickMove();
void motorJoystick();

//INT4


char CouserExist(char username[MAX_NAME]);
void CoshowAccessMenu();
//Pre:
//Post: returns 1 if user exists and 0 if doesnt 
void CostoreUser(char username[MAX_NAME]);
//Pre: checks that the user does not exist 
//Post: Stores the user

//INT6
void showRegisterMenu();
//Pre:
//Post:
void showLoginMenu();
//Pre:
//Post:

//INT4
char MaOneSecond(char handler);
//Pre:
//Post: does a tiGetTics inside till 50 tics and returns 1
//if reached

//INT5
void initSIO(void);
void SiSendChar(char my_byte);
	// PRE: SIO is available to Send.
	// POST: Sends my_byte using the EUSART.
char SiIsAvailable(void);
	// PRE: --
	// POST: Returns 1 if SIO is ready to SEND. Otherwise, returns 0.
	// Returning the TRMT flag of the TXSTA register to check if we can transmit bytes again.
void SiHasReceived(void);
//PRE:--
//POST: Returns 1 if eusart has received, or 0.
char SiGetChar(void);
//Pre: siHasReceived
//Post: returns the first received byte.
//warning:destructive reading


//INT6
char EuKReceived(void);
//Pre: SiGetChar
//Post: returns 1 if K received, otherwise 0.

//INT7
void GaStartTime(void);
//Pre: EuKReceived
//Post: Starts remaining game time.
