#include "CONTROLLER.h"
#define T1S 1000
#define REGISTER_OPTION 1
#define LOGIN_OPTION 0

typedef struct{
char[8] name;
char[8] password;
char points;
}User;


static char Timer_1S;
static char state;
static char showAccess;
static char showRegister;
static char showLogin;
static char password_registering;
static char timer;
static char updated_status;
static char key_co;
static char key_co_old;
static char num_letters_co;
static char showMenu;
static char num_letters;
static char name_counter;
static User user;
static char temporal_word[8];
//static const char table = {72,2,4,8,16,32,64,128};
static char matrixKeypad[9][4] = {{'a','b','c','2'},
                                   {'d','e','f','3'},
                                   {'g','h','i','4'},
                                   {'j','k','l','5'},
                                   {'m','n','o','6'},
                                   {'p','r','s','7'},
                                   {'t','u','v','8'},
                                   {'w','x','y','9'}                            
                               };

void initController(void){
	Timer_1S = TiGetTimer();
	state = 0;
	showAccess = 0;
	showRegister = 0;
	showLogin = 0;
	password_registering = 0;
	timer=0;
	updated_status = 0;
	Key_co = 0;
	num_letters_co = 0;
	key_co_old = 0;
	num_letters = 0;
	name_counter = 0;
	user.points = 0;
}

void CoupdateKey(char key){
	key_co = key;
}

void CoKeyReceived(char updated){
	updated_status = updated;
}

void CostoreUser(void){
	
}
User CogetUser(void){
	return User;
}
void sameKey(void){
	return key_co == key_co_old;
}
void storeUserName(void){
	user.name = temporal_word;
}
void storeUserPassword(void){
	user.password = temporal_word;
}
void clearUserName(void){
	user.name = 0x0;
}


void controller_generated(void) {
	switch(state) {
		case 0:
			showAccess = 1;
			state = 1;
		break;
		case 1:
			if (updated_status == 1){
				updated_status = 0;
				if(key_co==REGISTER_OPTION){
					showAccess = 0;
					showRegister = 1;
					state = 2;
				}
				else{
					showAccess = 0;
					showLogin = 1;
					state = 2;
				}
			}
		break;
		case 2:
				if(updated_status == 1){
					num_letters = 0;
					key_co_old = key_co;
					TiResetTics(Timer_1S);
					state = 3;
				}
		break;
		case 3:
			if (updated_status == 1 && TiGetTics(Timer_1S) < T1S && sameKey()) {
				updated_status = 0;
				num_letters++;
				state = 3;
			}
			if(updated_status == 1 && TiGetTics(Timer_1S) < T1S && !sameKey()){
				num_letters = 0;
				temporal_word[name_counter]=matrixKeypad[key_co][num_letters];
				state = 5;
			}
_			else if (TiGetTics(Timer_1S) >= T1S) {
				temporal_word[name_counter++]=matrixKeypad[Key_co][num_letters];
				state = 5;
			}
		break;
		case 4:
			if (name_counter < 8 && key != '#') {
				state = 2;
			}
			if ((name_counter <= 8 || key == '#') && password_registering == 1) {
				if(name_counter < 8 && key == '#'){
					temporal_word[name_counter++] = '/0' ;
				}
				name_counter = 0;
				storeUserPassword();
				state = 9;
			}
			if ((name_counter <= 8 || key == '#') && showLogin == 1) {
				if(name_counter < 8 && key == '#'){
					temporal_word[name_counter++] = '/0';
				}
				name_counter = 0;
				storeUserName();
				state = 6;
			}
			if ((name_counter < 8 && key == '#') && showRegister == 1) {
				if(name_counter < 8 && key == '#'){
					temporal_word[name_counter++] = '/0';
				}
				name_counter = 0;
				storeUserName();
				state = 5;
			}
		break;
		case 5:
			if (!CouserExists()) {
				password_registering = 1;
				num_letters_co = num_letters;
				state = 2;
			}
			else{
				showAccess = 1;
				showRegister = 0;
				name_counter = 0;
				clearUserName();
				state = 1;
			}
		break;
		case 9:
		if(showRegister == 1){
			CostoreUser();
			state = 7;
		}
		if(showLogin == 1){
			showMenu = 1;
			CogetUser();
			state = 8;
		}

		break;
		case 6:
			if(CouserExists()){
				password_registering = 1;
				state = 2;
			}
			else{
				showAccess = 1;
				ShowLogin = 0;
				num_letters = 0;
				clearUserName();
				state = 1;
			}
			
		break;
		case 7:
			showAccess = 0;
			ShowLogin = 1;
			num_letters = 0;
			state = 2;
		break;
		case 8:

		break;
	}
}