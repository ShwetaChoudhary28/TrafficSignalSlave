 #include "stm32f4xx_hal.h"
char string[225];
 char sign[115];
short signCntr = 0 ;
short msgCntr =  0 ;
	short msgParse(uint8_t *SPtr , char *sigPtr , short pointer);
			void clearStringNsign(void);

    /*
    This function receives a message string and a signature string . Objective is to check if message string contains signature
    string or if true it will return index in message string before which  signature ends and  else it will return 0
    */
	short msgParse(uint8_t *SPtr ,char *sigPtr , short pointer )
	{
	 clearStringNsign();

	short stringCounter =0 ;
	short sigCounter =0 ;
	 signCntr = 0 ;
	 msgCntr =  0 ;

	 //if msg starts from '\0' so increment the value of SPtr till some values is rec.
	  while(*SPtr == '\0'){
	    *SPtr++;
	   msgCntr++;
	  }



    // Transfer  msg string to character local array
 //   *SPtr= *SPtr+4;
		while(*SPtr != '\0') {
      string[msgCntr] =  *SPtr ;
      *SPtr++;
      msgCntr++;
      }
      string[msgCntr] =  '\0' ;
//set_cursor(0,0);
//lcd_command(0x80);
//lcd_print(string);
// Transfer  signature string to character local array
      while(*sigPtr != '\0') {
      sign[signCntr] =  *sigPtr ;
      *sigPtr++;
      signCntr++;
      }
      sign[signCntr] =  '\0' ;
    // Intitialise array counter variables to first value i.e. 0
	 signCntr = 0 ;
	 msgCntr = pointer ;

   // Check if contents of two arrays match if not increment string array counter by one
    	while(1)
        {
            if(string[msgCntr]!=sign[signCntr])
        	{
            msgCntr++ ;
            // Check if end of string has occured
                if (string[msgCntr]=='\0')
                {
                 return 0 ;
                }
				signCntr = 0 ;  // Reset signature counter
        	}
            else
            {
            msgCntr++ ;
            signCntr++ ;
            // Check if end of signString has occured
                if (sign[signCntr]=='\0')
                {
                 return msgCntr;
                }
            // Check if end of msgString has occured
                if (string[msgCntr]=='\0')
                {
                 return 0 ;
                }


            }
    	}
    }












		void clearStringNsign(void)
		{
int a =0 ;
	for (a=0;a<100;a++)
		{
string[a]=0;
sign[a]=0;
}
}






