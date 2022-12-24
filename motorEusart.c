char myString[MAXSTRINGS][MAXCHARACTERS];

void SiSendStringCooperative(char send[]){
	//"idea1: 2 motors, one for send and one for receiving"
	//idea2: copy pointer after making myString an array of stringd
}

void motorEusart(){
	while(send[count] != '\0'){
		SiSendChar(send[char++]);
	}
}