#include "stm32f4xx_hal.h"

extern uint8_t RecMsg2[250];
 uint8_t frame[100] ;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart4;
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart3;

extern uint8_t aRxBuffer[225];
extern uint8_t aRxBuffer1[225];
extern uint8_t RecMsg1[250];
extern uint8_t aRxBuffer3[225];
extern uint8_t RecMsg3[250];
extern uint8_t aRxBuffer4[225];
extern uint8_t RecMsg4[250];
extern uint8_t aRxBuffer5[225];
extern uint8_t RecMsg5[250];
int zxx9 =4 ;
int zxx9Res = 6 ;
uint8_t Data[100] ;
int state;
int clearanceMode;
int serverMode;
uint8_t fileNo=111  ;
extern int signVal ;
__IO uint8_t string[126]; // string array to store message received in UART
uint8_t junctionId=111  ;
uint8_t noOfSides=0  ;
uint8_t noOfPlans=0  ;
uint8_t programVersionNo=0  ;
uint8_t programVersionNoLast=0  ;
uint8_t registrationStatus=0  ;
int padestarianTime = 10 ;
int noOfPlansNew;
int noOfPlanCnt=1;
uint8_t signalData[20];
 uint8_t planNo ;
 __IO uint32_t stringInt[25]; // string array to store messege received in uart
 char data1[17];
extern uint8_t second[17];
int indexCnt=0;
int indexCnt1=0;
uint8_t first[17];
int cntVal;
extern int recCnt;
extern int recCnt1;
char crcVal[5];
 __IO uint32_t test = 0 ;



void clearBuffer();
void transmit();
void clearaRxBuffer1();
void clearBuffer1();
void clearaRxBuffer3();
void clearBuffer3();
void clearaRxBuffer4();
void clearBuffer4();
void clearaRxBuffer5();
void clearBuffer5();
void function7_1();
void function7_2();
void function3_1();
void function3_2();
int crcApi();
void transferDataValues(int cnt);
void function6_2();
void function6_1();
void sendToUsart1();
//void outputPin();
//void inputPin();
void function8();
void checkMode();
void checkClearenceMode();
int crcApiResponse();
void function1();
void function1Response();
int crcApi2(int signval);
void program3();
void function4Response();
void byteToIntegerVal(char *dat,uint8_t index);
void byteToIntegerVal1(uint8_t dat);
void intToString(__IO uint32_t dat ) ;
void clearStringBuffer();
void intToChar(uint8_t dat);
void intToChar1(uint8_t dat);
void trafficDisplay2Value();
void trafficDisplay1Value();
void checkMsgLengthForUart4();
void checkMsgLengthForUart2();
void intToByte(int val);



void clearBuffer(){
	int x=0;
	for(;x<160;x++)
	{
		RecMsg2[x]=0x00;

	}
}


void clearaRxBuffer(){
	int x=0;
	for(;x<160;x++)
	{
		aRxBuffer[x]=0x00;

	}
}

void clearBuffer1(){
	int x=0;
	for(;x<160;x++)
	{
		RecMsg1[x]=0x00;

	}
}


void clearaRxBuffer1(){
	int x=0;
	for(;x<160;x++)
	{
		aRxBuffer1[x]=0x00;

	}
}
void clearBuffer3(){
	int x=0;
	for(;x<160;x++)
	{
		RecMsg3[x]=0x00;

	}
}


void clearaRxBuffer3(){
	int x=0;
	for(;x<160;x++)
	{
		aRxBuffer3[x]=0x00;

	}
}

void clearBuffer4(){
	int x=0;
	for(;x<160;x++)
	{
		RecMsg4[x]=0x00;

	}
}


void clearaRxBuffer4(){
	int x=0;
	for(;x<160;x++)
	{
		aRxBuffer4[x]=0x00;

	}
}

void clearBuffer5(){
	int x=0;
	for(;x<160;x++)
	{
		RecMsg5[x]=0x00;

	}
}


void clearaRxBuffer5(){
	int x=0;
	for(;x<160;x++)
	{
		aRxBuffer5[x]=0x00;

	}
}

void transmit(){

//	frame[0] = 0x41;
//	frame[1] = 0x54;
//	frame[2] = 0x2B;
//	frame[3] = 0x43;
//	frame[4] = 0x50;
//	frame[5] = 0x42;
//	frame[6] = 0x46;
//	frame[7] = 0x0D;
//	frame[8] = 0x0A;
	//HAL_UART_Transmit (&huart2, (uint8_t*)frame, 9,5000) ;


//	HAL_UART_Transmit (&huart4, (uint8_t*)Data,38,5000) ;
//	HAL_UART_Transmit (&huart2, (uint8_t*)Data,38,5000) ; cntVal

		HAL_UART_Transmit (&huart4, (uint8_t*)Data,cntVal,5000) ;
		HAL_UART_Transmit (&huart2, (uint8_t*)Data,cntVal,5000) ;

		cntVal=0;


}

void function7_1() // read SD Card
{

	    frame[0] = 0x7E;
		frame[1] = 0x7E;
		frame[2] = 0x00;//byte size 1
		frame[3] = 0x0E;//byte size 2
		frame[4] = 0x01;//project number
		frame[5] = 0x01;//program version
		frame[6] = 0x01;//file_num
		frame[7] = 0x07;//function num
		frame[8] = 0x01;//read
		frame[9] = 0x01;//msg
		frame[10] = 0x01;//data
		frame[11] = 0x01;//data
		frame[12] = 0x00;//data
		frame[13] = 0x00;//data
		frame[14] = 0x00;//data
		frame[15] = 0x00;//data
		frame[16] = 0x00;//data
		frame[17] = 0x00;//data
		frame[18] = 0xFF -	crcApi();//CRC
		frame[19] = 0x7D;// ending delimeter
	    frame[20] = 0x7D;//ending delimeter
//		frame[21] = 0x0D;
		HAL_UART_Transmit (&huart4, (uint8_t*)frame, 21,5000) ;




}
void function7_2()//write SD Card
{

	    frame[0] = 0x7E;
		frame[1] = 0x7E;
		frame[2] = 0x00;//byte size 1
		frame[3] = 0x0E;//byte size 2
		frame[4] = 0x01;//project number
		frame[5] = 0x01;//program version
		frame[6] = 0x01;//file_num
		frame[7] = 0x07;//function num
		frame[8] = 0x02;//write
		frame[9] =  0x02;//Data[1];//msg
		frame[10] = 0x31;//Data[2];//data2
		frame[11] = 0x32;//Data[3];//data3
		frame[12] = 0x33;//Data[4];//data4
		frame[13] = 0x34;//Data[5];//data5
		frame[14] = 0x35;//Data[6];//data6
		frame[15] = 0x36;//Data[7];//data7
		frame[16] = 0x37;//Data[8];//data8
		frame[17] = 0x38;//Data[9];//data9
		frame[18] = 0x39;//Data[10];//data1
		frame[19] = 0x30;//Data[11];//data2
		frame[20] = 0x31;//Data[12];//data3
		frame[21] = 0x32;//Data[13];//data4
		frame[22] = 0x33;//Data[14];//data5
		frame[23] = 0x34;//Data[15];//data6
		frame[24] = 0x35;//Data[16];//data7
		frame[25] = 0x36;//Data[17];//data8
		frame[26] = 0x37;//Data[18];//data9
		frame[27] = 0x38;//Data[19];//data7
		frame[28] = 0x39;//Data[20];//data8
		frame[29] = 0x30;//Data[21];//data9
		frame[30] = 0x31;//Data[22];//data9
		frame[31] = 0xFF -	crcApi();//CRC
		frame[32] = 0x7D;// ending delimeter
	    frame[33] = 0x7D;//ending delimeter
//		frame[21] = 0x0D;
		HAL_UART_Transmit (&huart4, (uint8_t*)frame,34,5000) ;




}



void function3_1()// read RTC
{

	    frame[0] = 0x7E;
		frame[1] = 0x7E;
		frame[2] = 0x00;//byte size 1
		frame[3] = 0x0E;//byte size 2
		frame[4] = 0x01;//project number
		frame[5] = 0x01;//program version
		frame[6] = 0x01;//file_num
		frame[7] = 0x03;//function num
		frame[8] = 0x01;//read
		frame[9] = 0x00;//Day
		frame[10] = 0x00;//Month
		frame[11] = 0x00;//Year
		frame[12] = 0x00;//Hr
		frame[13] = 0x00;//Min
		frame[14] = 0x00;//data
		frame[15] = 0x00;//data
		frame[16] = 0x00;//data
		frame[17] = 0x00;//data
		frame[18] = 0xFF -	crcApi();//CRC
		frame[19] = 0x7D;// ending delimeter
	    frame[20] = 0x7D;//ending delimeter
//		frame[21] = 0x0D;
		HAL_UART_Transmit (&huart4, (uint8_t*)frame, 21,5000) ;




}


void function3_2()// write RTC
{

	    frame[0] = 0x7E;
		frame[1] = 0x7E;
		frame[2] = 0x00;//byte size 1
		frame[3] = 0x0E;//byte size 2
		frame[4] = 0x01;//project number
		frame[5] = 0x01;//program version
		frame[6] = 0x01;//file_num
		frame[7] = 0x03;//function num
		frame[8] = 0x02;//write
		frame[9] = 0x1A;//Day
		frame[10] = 0x0B;//Month
		frame[11] = 0x12;//Year
		frame[12] = 0x0F;//Hr
		frame[13] = 0x32;//Min
		frame[14] = 0x00;//data
		frame[15] = 0x00;//data
		frame[16] = 0x00;//data
		frame[17] = 0x00;//data
		frame[18] = 0xFF -	crcApi();//CRC
		frame[19] = 0x7D;// ending delimeter
	    frame[20] = 0x7D;//ending delimeter
//		frame[21] = 0x0D;
		HAL_UART_Transmit (&huart4, (uint8_t*)frame, 21,5000) ;




}



int crcApi(void)
	{

	int	zzzz = zxx9+frame[3] ; // have changed frame[3] to frame[5]
	int	zyy9=0;
   int zxx9 =4 ;           // have changed zxx9=4; to zxx9=6;
		zzzz = zxx9+frame[3] ;
		while(zxx9<zzzz)
		{
			zyy9=zyy9+frame[zxx9++];
		}

		return zyy9;



	}


int crcApiResponse(void)
	{

	int	zzzzRes = zxx9Res+frame[5] ; // have changed frame[3] to frame[5]
	int	zyy9Res=0;
   int zxx9Res =6 ;           // have changed zxx9=4; to zxx9=6;
		zzzzRes = zxx9Res+frame[5] ;
		while(zxx9Res<zzzzRes)
		{
			zyy9Res=zyy9Res+frame[zxx9Res++];
		}

		return zyy9Res;



	}

   void transferDataValues(int cnt){
////int i=0;
//	   Data[cnt-3]=0x7E;
//	  // Data[cnt-2]=0x7E;
//cnt=cnt-1;
//  for(int i=1;i<38;i++){
//  // while(RecMsg1== '0x7D'){
//	   Data[i]=RecMsg1[cnt];
//	   cnt++;
//	   //i++;


	   int i=0;
	   int counter;
//	   Data[cnt-3]=0x7E;
//	   cnt=cnt-1;
//	   Data[0]=0x7E;
//	   Data[1]=0x7E;
	   counter=cnt-2;
	   while (!(RecMsg1[i] == 0x7D))
		{
		   Data[i]=RecMsg1[counter];
		   i++;
		   counter++;

   }
	   Data[i++]=0x7D;
//	   Data[i]=0x7D;
	   cntVal=i;



   }


   void function6_2()//write server
   {

   	    frame[0] = 0x7E;
   		frame[1] = 0x7E;
   		frame[2] = 0x00;//byte size 1
   		frame[3] = 0x1B;//byte size 2
   		frame[4] = 0x01;//project number
   		frame[5] = 0x01;//program version
   		frame[6] = 0x01;//file_num
   		frame[7] = 0x06;//function num
   		frame[8] = 0x02;//write
   		frame[9] =  Data[1];//data1
   		frame[10] = Data[2];//data2
   		frame[11] = Data[3];//data3
   		frame[12] = Data[4];//data4
   		frame[13] = Data[5];//data5
   		frame[14] = Data[6];//data6
   		frame[15] = Data[7];//data7
   		frame[16] = Data[8];//data8
   		frame[17] = Data[9];//data9
   		frame[18] = Data[10];//data1
   		frame[19] = Data[11];//data2
   		frame[20] = Data[12];//data3
   		frame[21] = Data[13];//data4
   		frame[22] = Data[14];//data5
   		frame[23] = Data[15];//data6
   		frame[24] = Data[16];//data7
   		frame[25] = Data[17];//data8
   		frame[26] = Data[18];//data9
   		frame[27] = Data[19];//data7
   		frame[28] = Data[20];//data8
   		frame[29] = Data[21];//data9
   		frame[30] = Data[22];//data9
   		frame[31] = 0xFF -	crcApi();//CRC
   		frame[32] = 0x7D;// ending delimeter
   	    frame[33] = 0x7D;//ending delimeter
   //		frame[21] = 0x0D;
   		HAL_UART_Transmit (&huart4, (uint8_t*)frame,34,5000) ;




   }

   void function6_1()//read server
   {

   	    frame[0] = 0x7E;
   		frame[1] = 0x7E;
   		frame[2] = 0x00;//byte size 1
   		frame[3] = 0x0E;//byte size 2
   		frame[4] = 0x01;//project number
   		frame[5] = 0x01;//program version
   		frame[6] = 0x01;//file_num
   		frame[7] = 0x06;//function num
   		frame[8] = 0x01;//read
   		frame[9] =  Data[1];//data1
   		frame[10] = Data[2];//data2
   		frame[11] = Data[3];//data3
   		frame[12] = Data[4];//data4
   		frame[13] = Data[5];//data5
   		frame[14] = Data[6];//data6
   		frame[15] = Data[7];//data7
   		frame[16] = Data[8];//data8
   		frame[17] = Data[9];//data9
   		frame[18] = Data[10];//data1
   		frame[19] = Data[11];//data2
   		frame[20] = Data[12];//data3
   		frame[21] = Data[13];//data4
   		frame[22] = Data[14];//data5
   		frame[23] = Data[15];//data6
   		frame[24] = Data[16];//data7
   		frame[25] = Data[17];//data8
   		frame[26] = Data[18];//data9
   		frame[27] = Data[19];//data7
   		frame[28] = Data[20];//data8
   		frame[29] = Data[21];//data9
   		frame[30] = Data[22];//data9
   		frame[31] = 0xFF -	crcApi();//CRC
   		frame[32] = 0x7D;// ending delimeter
   	    frame[33] = 0x7D;//ending delimeter
   //		frame[21] = 0x0D;
   		HAL_UART_Transmit (&huart4, (uint8_t*)frame,34,5000) ;




   }



void sendToUsart1(){
	uint8_t send[20];

	for(int i=0;i<18;i++){
		send[i]=RecMsg4[i];

	}


//	HAL_UART_Transmit (&huart1, (uint8_t*)send,18,5000) ;

}




//void outputPin(){
//
//uint8_t  pinValue=0xA5;
//uint8_t  pinValue1=0xA5;
//if(( pinValue & 0x01 )== 0x01){
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
//
//}
//else
//{
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
//	}
//
//if(( pinValue & 0x02 )== 0x02){
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
//
//}
//else
//{
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
//	}
//
//if(( pinValue & 0x04 )== 0x04){
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
//
//}
//else
//{
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
//	}
//
//if(( pinValue & 0x08 )== 0x08){
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);
//
//}
//else
//{
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
//	}
//
//if(( pinValue & 0x10 )== 0x10){
//	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_SET);
//
//}
//else
//{
//	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_RESET);
//	}
//
//if(( pinValue & 0x20 )== 0x20){
//	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_SET);
//
//}
//else
//{
//	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_RESET);
//	}
//if(( pinValue & 0x40 )== 0x40){
//	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);
//
//}
//else
//{
//	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
//	}
//
//if(( pinValue & 0x80 )== 0x80){
//	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET);
//
//}
//else
//{
//	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);
//	}
////-----------------------------------
//if(( pinValue1 & 0x01 )== 0x01){
//	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_SET);
//
//}
//else
//{
//	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_RESET);
//	}
//if(( pinValue1 & 0x02 )== 0x02){
//	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET);
//
//}
//else
//{
//	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_RESET);
//	}
//if(( pinValue1 & 0x04 )== 0x04){
//	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET);
//
//}
//else
//{
//	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_RESET);
//	}
//if(( pinValue1 & 0x08 )== 0x08){
//	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_SET);
//
//}
//else
//{
//	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_RESET);
//	}
//if(( pinValue1 & 0x10 )== 0x10){
//	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_SET);
//
//}
//else
//{
//	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_RESET);
//	}
//if(( pinValue1 & 0x20 )== 0x20){
//	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_SET);
//
//}
//else
//{
//	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET);
//	}
//if(( pinValue1 & 0x40 )== 0x40){
//	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_SET);
//
//}
//else
//{
//	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_RESET);
//	}
//if(( pinValue1 & 0x80 )== 0x80){
//	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_SET);
//
//}
//else
//{
//	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_RESET);
//	}
//
//
//
//
//}

//void inputPin(){
//
//
//
//	if(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_4))	{
//		state=1;
//	}
//	else{
//		state=0;
//	}
//	if(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_5))	{
//		state=1;
//	}
//	else{
//		state=0;
//	}
//	if(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_6))	{
//		state=1;
//	}
//	else{
//		state=0;
//	}
//	if(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_7))	{
//		state=1;
//	}
//	else{
//		state=0;
//	}
//
//	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_3))	{
//		state=1;
//	}
//	else{
//		state=0;
//	}
//	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_5))	{
//		state=1;
//		}
//		else{
//			state=0;
//		}
//	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_6))	{
//		state=1;
//		}
//		else{
//			state=0;
//		}
//	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_7))	{
//		state=1;
//		}
//		else{
//			state=0;
//		}
//
//
//
//}

void function8(){



	        frame[0] = 0x7E;
		   	frame[1] = 0x7E;
	        frame[2] = 0x7E;
	   		frame[3] = 0x7E;
	   		frame[4] = 0x00;//byte size 1
	   		frame[5] = 0x08;//byte size 2
	   		frame[6] = 0x0B;//junction id
	   		frame[7] = 0x05;//program_version_number
	   		frame[8] = 0x04;//file_num
	   		frame[9] = 0x08;//function num
	   		frame[10] = clearanceMode;//activity
	   		frame[11] = 0x01;//activity1
	   		frame[12] = 0x01;//counter;//activity2
	   		frame[13] = 0x01;//activity3
	   		frame[14] = 0xFF -	crcApiResponse();//CRC
	   		frame[15] = 0x7D;// ending delimeter
	   	    frame[16] = 0x7D;//ending delimeter

	   	 HAL_UART_Transmit (&huart1, (uint8_t*)frame,17,5000) ;

}

void function1()// check registration
{

	    frame[0] = 126;
		frame[1] = 126;
		frame[2] = 00;//byte size 1
		frame[3] = 19;//byte size 2
		frame[4] = 127 ;//junctionId ;
		frame[5] = 127 ;//programVersionNo ;
		frame[6] = fileNo;
		frame[7] = 1 ;//function no
		frame[8] =  '0' ;
		frame[9] =  '1' ;
		frame[10] = '3' ;
		frame[11] = '7' ;
		frame[12] = '7' ;
		frame[13] = '7' ;
		frame[14] = '0' ;
		frame[15] = '0' ;
		frame[16] = '0' ;
		frame[17] = '6' ;
		frame[18] = '2' ;
		frame[19] = '0' ;
	    frame[20] = '9' ;//'1'
	    frame[21] = '1' ;//'0' ; //'5' ;
	    frame[22] = '5' ;// '2' ;//'9' ;//'1' ;
	    frame[23] = 0xFF -	crcApi();
	    frame[24] =125 ;
	    frame[25] =125 ;
//		frame[21] = 0x0D;
		HAL_UART_Transmit (&huart4, (uint8_t*)frame, 26,5000) ;




}
int function4(void)
{

//for (i =1 ; i<noOfPlans+1 ; i++)
//{
	planNo=noOfPlanCnt ;
//msg_processed = 0 ;     //Raise flag to indicate a msg to be processed by main is present
//RxCount = 0 ;			// Reset msg receive counter
//
//flag  = 0 ;
//// puts1("AT+CIPSEND\r\n",11);
//// delay(9800000);
////    signVal = msgParse(RxBuffer,"T\r\r\nOK",0);
frame[0]=126 ;
frame[1]=126 ;
frame[2]= 0 ; // function no
frame[3]=5;
frame[4]=junctionId; // junction no
frame[5] =programVersionNo ;// junction no
frame[6] =fileNo ;// junction no
frame[7] =4 ;// function no
frame[8] = planNo ;  // plan no
frame[9] =0xFF-crcApi() ;// junction no
frame[10]=125 ;
frame[11]=125 ;
HAL_UART_Transmit (&huart4, (uint8_t*)frame, 26,5000) ;
//
//}
}

void function4Response(void)
{
	signVal =signVal+2 ;

		if ((RecMsg4[signVal]==junctionId))
		if ((RecMsg4[signVal+3]==4))
		if ((RecMsg4[signVal+4]==planNo)){

			signalData[0] = RecMsg4[signVal+5] ;// on time hour
					if (signalData[0]==0x6F)
						signalData[0]=0 ;
					signalData[1] = RecMsg4[signVal+6] ;// on time min
					if (signalData[1]==0x6F)
						signalData[1]=0 ;
					signalData[2] = RecMsg4[signVal+7] ;// off time hour
					signalData[3] = RecMsg4[signVal+8] ;// off time min

//				byteToInteger(0);
//				eepromData[planNo*4+1]=stringInt[0];

					signalData[4] = RecMsg4[signVal+9] ;// side1 green time
					signalData[5] = RecMsg4[signVal+10] ;// side2 green time
					signalData[6] = RecMsg4[signVal+11] ;// side3 green time
					signalData[7] = RecMsg4[signVal+12] ;// side4 green time
//				byteToInteger(0);
//				eepromData[planNo*4+2]=stringInt[0];

					signalData[8] = RecMsg4[signVal+14] ;// side1 amber time
					signalData[9] = RecMsg4[signVal+15] ;// side2 amber time
					signalData[10] = RecMsg4[signVal+16] ;// side3 amber time
					signalData[11] = RecMsg4[signVal+17] ;// side4 amber time
//				byteToInteger(0);
//				eepromData[planNo*4+3]=stringInt[0];

					signalData[12] = RecMsg4[signVal+19] ;// plan mode
					signalData[13] = RecMsg4[signVal+13] ;// side5 green time
					signalData[14] = RecMsg4[signVal+18] ;// side5 amber time
					signalData[15] = 0xFF ;//
//				byteToInteger(0);
//				eepromData[planNo*4+4]=stringInt[0];

					if(noOfPlanCnt<noOfPlansNew)
					{
						noOfPlanCnt++;
						function4();

					}



		}

}



void checkClearenceMode(){
//----------------------------PD4 for jump---------------------//
	if(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_4))	{
		clearanceMode=4;
		}

//----------------------------PD5 for extend---------------------//
		if(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_5))	{
			clearanceMode=6;
		}

//----------------------------PD6 for modeChange--------------------//
		if(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_6))	{
			clearanceMode=3;
		}

//--------------------------PD7 for shutdown-----------------------//
		if(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_7))	{
			clearanceMode=5;
		}




}

//-------------------changeMode()---> whether serverMode or manualMode---------------//
void checkMode()

{

	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_3))	{
		serverMode=1;
		}
		else{
			serverMode=0;
		}

}

void function1Response(){

	//if (RecMsg4[signVal+(RecMsg4[signVal+1])+2]+crcApi2(signVal)==0xFF)
//		{
//		signVal =signVal+2 ;
//		signVal =signVal+3 ;
//		signVal =signVal+6 ;
	    signVal =signVal+2 ;
//	    junctionId=RecMsg4[signVal];
		if (!(RecMsg4[signVal]==111))
		//if (RecMsg4[signVal+1]==1)
		{

			junctionId=RecMsg4[signVal];
			programVersionNo=RecMsg4[signVal+1];
			programVersionNoLast=RecMsg4[signVal+1];
			fileNo=RecMsg4[signVal+2];
			registrationStatus=RecMsg4[signVal+4];
			noOfSides=RecMsg4[signVal+5];
			noOfPlans=RecMsg4[signVal+6];
			padestarianTime=RecMsg4[signVal+7];
			//junctionId=RecMsg4[signVal];

//		}
//		}

			// 	fnData[0] = RxBuffer[6] ;// junctiond id

//			string[0]=RxBuffer[signVal];//junction id
//			string[0]=RxBuffer[signVal];//junction id
//			junctionId=RxBuffer[signVal];
//			string[1]=RxBuffer[signVal+1];//no of sides
//			programVersionNo=RxBuffer[signVal+1];
//			programVersionNoLast=RxBuffer[signVal+1];
//			string[2]=RxBuffer[signVal+2];//no of sides
//			fileNo=RxBuffer[signVal+2];
//			string[3]=RxBuffer[signVal+4];//no of sides
//			registrationStatus=RxBuffer[signVal+4];
//			byteToInteger(0);
//			eepromData[0]=stringInt[0];
//			string[0]=RxBuffer[signVal+5];//no of sides
//			noOfSides=RxBuffer[signVal+5];
//			string[1]=RxBuffer[signVal+6];// no of plans
//			noOfPlans=RxBuffer[signVal+6];
//			//noOfPlans=3;
//			string[2]=RxBuffer[signVal+7];// program version no
//			padestarianTime=RxBuffer[signVal+7];
//	//		padestarianOn=RxBuffer[signVal+8];
//			string[3]=RxBuffer[signVal+8];
//			byteToInteger(0);
//			eepromData[1]=stringInt[0];



	signVal=0;

	if(junctionId==111){
		function1();
	}
	else{
	noOfPlansNew=noOfPlans+1;
//	if(noOfPlanCnt<noOfPlansNew)
//	{
		function4();
//
//	}

	}


		}

}

int crcApi2(int signval)
{
	int zxx9 =signval+2 ;
	int zyy9 =0 ;
	int zzzz =zxx9+RecMsg4[signval+1] ;
	while(zxx9<zzzz)
	{
		zyy9=zyy9+RecMsg4[zxx9++] ;
	}

	return zyy9;



}

void program3()
{
	//if(junctionId=111){
	function1();
	//}else{
//		noOfPlansNew=noOfPlans+1;
//		if(noOfPlanCnt<noOfPlansNew)
	//	{
//			function4();

	//	}
//	}
}
void byteToIntegerVal(char *dat,uint8_t index)
{
int zx =0 ;
//	while (zx<8)
while (zx<24)

{
	stringInt[zx+index]= *dat ;

	*dat++;
	zx++;

	}
}

void intToByte(int val)
{
test = val ;
test &=0xFF ;
crcVal[0]= test;

test = (val & 0xFF00) >> 8 ;
crcVal[1]= test ;

test = (val & 0xFF0000) >> 16;
crcVal[2]= test ;
test = (val & 0xFF000000) >> 24;
crcVal[3]= test ;
crcVal[4]= 0 ;

}

void byteToIntegerVal1(uint8_t dat)
{
//	int z = 0;
	stringInt[0] = string[dat+0];
	stringInt[0] |= (string[dat+0]<<0);
	stringInt[0] |= (string[dat+1]<<8);
	stringInt[0] |= (string[dat+2]<<16);
	stringInt[0] |= (string[dat+3]<<24);

	}
void intToString(__IO uint32_t dat )
{
	int  i=0;
	int  k=0;
	 char buf[10];
	 while(dat>0)
	  {
	  buf[i]=dat%10;
	  buf[i] = buf[i] + 48 ;
	  dat=dat/10;
	  i++;
	  }
	string[125]=i;
   	 buf[i]= 0 ;
	string[i]=0;
	 while(i>0)
	 {
	 string[i-1] = buf[k];
	 i--;
	 k++;
	 }
 }

void clearStringBuffer()
{
 for(int i=0;i<10;i++)
{
string[i]=0x00;
}
}

void intToChar(uint8_t dat)
{

	data1[0]=dat;


	if((data1[0] > 0x64))//3digit value
	{
			data1[1]=data1[0]/100; // 235/100=2
			second[indexCnt]=data1[1]+ 0x30;//

			indexCnt++;
			data1[2]=(data1[1]*100); //2*100=200
			data1[2]=data1[0]-data1[2]; //235-200=35
			data1[3]=data1[2]/10;// 35/10=3
			second[indexCnt]=data1[3]+ 0x30;//
			indexCnt++;

			data1[4]=(data1[3]*10); //3*10=30
			data1[4]=data1[2]-data1[4]; //35-30=5
			second[indexCnt]=data1[4]+ 0x30;//
			indexCnt++;

			second[indexCnt]=0x3A;//

	}

	if((data1[0] < 0x64) && (data1[0] > 0x0A))//2digit value
	{
		data1[1]=data1[0]/10; // 19/10=1
		second[indexCnt]=data1[1]+ 0x30;
		indexCnt++;

		data1[2]=(data1[1]*10); //1*10=10
		data1[2]=data1[0]-data1[2]; //19-10=9
		second[indexCnt]=data1[2]+ 0x30;//
		indexCnt++;

		second[indexCnt]=0x3A;//


//	data1[1]=data1[0]/100; // 235/100=2
//	second[indexCnt]=data1[1]+ 0x30;//
//
//	indexCnt++;
//	data1[2]=(data1[1]*100); //2*100=200
//	data1[2]=data1[0]-data1[2]; //235-200=35
//	data1[3]=data1[2]/10;// 35/10=3
//	second[indexCnt]=data1[2]+ 0x30;//
//
//	data1[4]=(data1[3]*10); //3*10=30
//	data1[4]=data1[2]-data1[4]; //35-30=5
//	data1[10]=data1[4]+ 0x30;//

	}
	if((data1[0] < 0x0A) && (data1[0] > 0x00))//1digit value
	{
		second[indexCnt]=data1[0]+ 0x30;//
				indexCnt++;

				second[indexCnt]=0x3A;//


	}

}


void clearSecondBuffer(){
	int x=0;
	for(;x<50;x++)
	{
		second[x]=0x00;

	}
}

void trafficDisplay2Value(){

	clearSecondBuffer();
	intToChar((uint8_t)Data[18]);
	indexCnt++;
	intToChar((uint8_t)Data[19]);
	indexCnt++;
	intToChar((uint8_t)Data[20]);
	indexCnt++;
	intToChar((uint8_t)Data[21]);
	indexCnt++;
	intToChar((uint8_t)Data[22]);
//	indexCnt++;
//	intToChar((uint8_t)Data[12]);
	clearData1Buffer();
	indexCnt=0;

}

void clearFirstBuffer(){
	int x=0;
	for(;x<50;x++)
	{
		first[x]=0x00;

	}
}
void clearData1Buffer(){
	int x=0;
	for(;x<50;x++)
	{
		data1[x]=0x00;

	}
}

void trafficDisplay1Value(){
	clearFirstBuffer();
	    intToChar1((uint8_t)Data[5]);
		indexCnt1++;
		intToChar1((uint8_t)Data[8]);
		indexCnt1++;
		intToChar1((uint8_t)Data[9]);
		indexCnt1++;
		intToChar1((uint8_t)Data[10]);
		indexCnt1++;
		intToChar1((uint8_t)Data[11]);
		indexCnt1++;
		intToChar1((uint8_t)Data[12]);
//	clearData1Buffer();
	 indexCnt1=0;

}
void intToChar1(uint8_t dat)
{

	data1[0]=dat;


	if((data1[0] > 0x64))//3digit value
	{
			data1[1]=data1[0]/100; // 235/100=2
			first[indexCnt1]=data1[1]+ 0x30;//

			indexCnt1++;
			data1[2]=(data1[1]*100); //2*100=200
			data1[2]=data1[0]-data1[2]; //235-200=35
			data1[3]=data1[2]/10;// 35/10=3
			first[indexCnt1]=data1[3]+ 0x30;//
			indexCnt1++;

			data1[4]=(data1[3]*10); //3*10=30
			data1[4]=data1[2]-data1[4]; //35-30=5
			first[indexCnt1]=data1[4]+ 0x30;//
			indexCnt1++;

			first[indexCnt1]=0x3A;//

	}

	if((data1[0] < 0x64) && (data1[0] > 0x0A))//2digit value
	{
		data1[1]=data1[0]/10; // 19/10=1
		first[indexCnt1]=data1[1]+ 0x30;
		indexCnt1++;

		data1[2]=(data1[1]*10); //1*10=10
		data1[2]=data1[0]-data1[2]; //19-10=9
		first[indexCnt1]=data1[2]+ 0x30;//
		indexCnt1++;

		first[indexCnt1]=0x3A;//


//	data1[1]=data1[0]/100; // 235/100=2
//	second[indexCnt]=data1[1]+ 0x30;//
//
//	indexCnt++;
//	data1[2]=(data1[1]*100); //2*100=200
//	data1[2]=data1[0]-data1[2]; //235-200=35
//	data1[3]=data1[2]/10;// 35/10=3
//	second[indexCnt]=data1[2]+ 0x30;//
//
//	data1[4]=(data1[3]*10); //3*10=30
//	data1[4]=data1[2]-data1[4]; //35-30=5
//	data1[10]=data1[4]+ 0x30;//

	}
	if((data1[0] < 0x0A) && (data1[0] > 0x00))//1digit value
	{
		first[indexCnt1]=data1[1]+ 0x30;//
				indexCnt1++;

				first[indexCnt1]=0x3A;//


	}

}


void checkMsgLengthForUart4(){
	int i=0;
while(!(RecMsg4[i] == 0x7D))
{
	recCnt++;
	i++;
}
recCnt++;
}

void checkMsgLengthForUart2(){
	int i=0;
while(!(RecMsg2[i] == 0x7D))
{
	recCnt1++;
	i++;
}
recCnt1++;
}






