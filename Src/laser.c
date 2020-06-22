//#include "stm32f0xx_hal.h"
#include "stm32f4xx_hal.h"

/* Buffer used for reception */
#define RXBUFFERSIZE                      132
extern UART_HandleTypeDef huart1;
extern uint8_t aRxBuffer[RXBUFFERSIZE];




/* Private variables ---------------------------------------------------------*/
extern uint8_t frame[100] ;
extern int sideNo;
int sideGreen;
int LaserPinState;
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart6;
extern UART_HandleTypeDef huart2;
extern int signVal ;
 int laserPinStatus=0;
extern  uint8_t RecMsg2[250];
extern  uint8_t RecMsg1[250];

extern __IO uint32_t TimingDelay4;
extern int electricSupplyStatus;
extern  int laserPinStatusFlag;
extern  int isGreen;
extern int sec;
int sideNo;
extern __IO uint32_t stringInt[25]; // string array to store messege received in uart
extern __IO uint32_t CRCValue ;
 uint8_t Disp[30];
extern __IO uint32_t crcbits;
extern char crcstring[4];
CRC_HandleTypeDef hcrc;
extern uint8_t RecMsg2[250];
extern uint8_t Data[100] ;
extern int cntVal;
int data[50];
extern char crcVal[5];
extern  int commFlag;
int slaveNo;

uint8_t RecMsg4[250];
extern uint8_t adcVal1;
extern uint8_t adcVal2;

uint8_t pedestrain[2];
uint8_t powerStatus;

//extern TIM_HandleTypeDef htim1;
//extern TIM_HandleTypeDef htim2;
//extern TIM_HandleTypeDef htim4;
//extern TIM_HandleTypeDef htim5;
//extern TIM_HandleTypeDef htim8;
//extern TIM_HandleTypeDef htim9;
//extern TIM_HandleTypeDef htim10;
//extern TIM_HandleTypeDef htim11;
//extern TIM_HandleTypeDef htim12;
//extern TIM_HandleTypeDef htim13;
//extern TIM_HandleTypeDef htim14;



/* Private functions prototypes---------------------------------------------------------*/
void laserM();
extern void puts3 (uint8_t *dat , int i);
extern void puts1 (uint8_t *dat , int i);
extern void clearARxbuffer(void);
extern 	int crcApi(void);
extern void clearingBuffer();
void function6();
extern int crcApi(void);
extern	void clearARxbuffer(void);
extern 	short msgParse(char *SPtr , char *sigPtr , short pointer);
extern void clearingRecBuffer();
extern void clearingFrameBuffer();
extern void TimingDelay_Decrement4(void);
extern int crcApi2(int signval);
extern void transferToaRxBuffer();
extern int crcApiLaser(void);
void clearingRecBuffer();
extern uint32_t HAL_CRC_Calculate(CRC_HandleTypeDef *hcrc, uint32_t pBuffer[], uint32_t BufferLength);
void transferRecValues(int cnt);
void transferRecValuesToData(int cnt);
void function66();
void transferRec1ValuesToData(int cnt);
void clearingStringIntBuffer();
void clearingDataBuffer();
void  clearingDispBuffer();
void function10();
void function11();
void slaveSelection();
void transferRecValuesToDataRecMsg2(int cnt);
//extern static void setPWM(TIM_HandleTypeDef timer, uint32_t channel, uint16_t period, uint16_t pulse);
//void setPWMPin(int pulse);

/* Private functions ---------------------------------------------------------*/


void laserM()
{
//	GPIOB->BRR = GPIO_PIN_3;/*Side1 off*/
//	GPIOB->BRR = GPIO_PIN_4;/*Side2 off*/
//	GPIOB->BRR = GPIO_PIN_5;/*Side3 off*/
//	GPIOB->BRR = GPIO_PIN_6;/*Side4 off*/
//

//	GPIOB->BSRR = GPIO_PIN_3;/*Side1 off*/
//	GPIOB->BSRR = GPIO_PIN_4;/*Side2 off*/
//	GPIOB->BSRR = GPIO_PIN_5;/*Side3 off*/
//	GPIOB->BSRR = GPIO_PIN_6;/*Side4 off*/

	sideNo=99;

	 if((HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_1)))/*Side 1*/
		{
			sideNo=1;
		}
		else
		{
			if((HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_5)))/*Side 2*/
		{
			sideNo=2;
			}
		else
		{
    if((HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_6)))/*Side 3*/
		{
			sideNo=3;

			}
    else
    {
   if((HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_7)))/*Side 4*/
		{
			sideNo=4;
    }
		else
		{
		sideNo=99;
		}
	  }
	  }
		}



if((sideNo==1)||(sideNo==2)||(sideNo==3)||(sideNo==4))
{


		function6();


    	if(LaserPinState==1)
			{
					  // GPIOB->BSRR = GPIO_PIN_3;/*laser on*/
    		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET);/*laser on*/

			}
			else
			{
			//GPIOB->BRR = GPIO_PIN_3;/*laser off*/
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);/*laser off*/
			}
		}
		else
			{
	//		GPIOB->BRR = GPIO_PIN_3;/*laser off*/
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);/*laser off*/

			}




}





void function66()
{

//	TimingDelay4=20;
	TimingDelay4=6;
TimingDelay_Decrement4();
while(1)

{

if(TimingDelay4==1)
break;
}
//		GPIOC->BSRR = GPIO_PIN_8;//set bit as high

//HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);


//GPIOB->BSRR = GPIO_PIN_4;//set bit as high
HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_SET);

//			TimingDelay4=25;
           TimingDelay4=12;
TimingDelay_Decrement4();
while(1)
{

if(TimingDelay4==1)
break;
}






clearingFrameBuffer();

          frame[0]=0x01 ;//Primary Byte
          frame[1]=0x02 ;//Secondary Byte
          frame[2]=0x02;//GPI
	      frame[3]=0x03;//TBD
	      frame[4]=0x05;//TBD
//	      frame[5]=0x04;//
//	      frame[6]=0x06;//
//	      frame[7]=0x02;//0x88;
//	      frame[8]=0x22;//0x09;
//	      frame[9]=0x02;//0x1D;
//	   	 	    	 	      frame[10]=0x03;//0x22;
//	   	 	    	 	      frame[11]=0x05;//0x40;
//	   	 	    	 	      frame[12]=0x04;//0x54;
//	   	 	    	 	      frame[13]=0x06;//0x38;
//	   	 	    	 	      frame[14]=0x02;//0x88;
//	   	 	    	 	      frame[15]=0x22;//0x09;
//	   	 	    	 	    frame[16]=0x02;//0x1D;
//	   	 	    	 	    frame[17]=0x03;//0x22;
//	   	 	    	 	    frame[18]=0x05;//0x40;
//	   	 	    	 	  	frame[19]=0x04;//0x54;
//	   	 	    	 	  	frame[20]=0xFF;//0x38;//red
//	   	 	    	 	  	frame[21]=0xFF;//0x88; //rgy
//	   	 	    	 	  	frame[22]=0xFA;//0x09; //pulse width
	   //	 	      if(RecMsg2[9]==0x08)
	   //	 	      {
	   //	 	      frame[9]=0x09;//0x48;
	   //	 	      }
	   //	 	      else
	   //	 	      {
//	   	 	      frame[23]=0x32;
//	   	 	     frame[24]=0x36;
	   //	 	      }


	   	 //-------------------------data array------------------//
	   	 	      Disp[0]=frame[0];
	   	 	      Disp[1]=frame[1];
	   	 	      Disp[2]=frame[2];
	   	 	      Disp[3]=frame[3];
	   	 	      Disp[4]=frame[4];
//	   	 	      Disp[5]=frame[7];
//	   	 	      Disp[6]=frame[8];
//	   	 	      Disp[7]=frame[9];
//	   	 	      Disp[8]=frame[10];
//	   	 	      Disp[9]=frame[10];
//	   	 	     Disp[10]= frame[11];
//	   	 	    Disp[11]= frame[12];
//	   	 	   Disp[12]= frame[13];
//	   	 	  Disp[13]= frame[14];
//	   	 	 Disp[14]= frame[15];
//	   	 	Disp[15]= frame[16];
//	   	 	Disp[16]=frame[17];
//	   	 	Disp[17]=frame[18];
//	   	 	Disp[18]=frame[19];
//	   	 	Disp[19]=frame[20];
//	   	 	Disp[20]=frame[21];
//	   	 	Disp[21]=frame[22];
//	   	 	Disp[22]=frame[23];
//	   	 	Disp[23]=frame[24];


	   		byteToIntegerVal(&Disp[0],0);
	   		 	       	CRCValue =	HAL_CRC_Calculate(&hcrc,(uint32_t *)stringInt, 8);
	   		 	       	intToByte(CRCValue);
	   		           frame[5]=crcVal[3];//CRC
	   		           frame[6]=crcVal[2];//CRC
	   		           frame[7]=crcVal[1];//CRC
	   		           frame[8]=crcVal[0];//CRC

	   //	 	       	byteToIntegerVal(&Disp[0],0);
	   //	 	       	CRCValue =	HAL_CRC_Calculate(&hcrc,(uint32_t *)stringInt, 8);
	   //	 	       	intToByte(CRCValue);
	   //	           frame[10]=crcVal[3];
	   //	           frame[11]=crcVal[2];
	   //	           frame[12]=crcVal[1];
	   //	           frame[13]=crcVal[0];




frame[9]=125 ;
frame[10]=125 ;

// frame[22]= 0 ;
// frame[23]= 0 ;
// frame[24]= 0 ;
clearingRecBuffer();
//puts2(&frame[0],1);
HAL_UART_Transmit (&huart1, (uint8_t*)frame,11,5000) ;


HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_RESET);

//puts3(&frame[0],14);
//
//			HAL_UART_Receive(&huart2, (uint8_t *)aRxBuffer, 20, 0xFFF);
//	signVal=msgParse((uint8_t *)aRxBuffer,"~~~~",0);
//if(!(signVal==0))
//{
//	if(aRxBuffer[signVal+12]==sideNo)
//	{
//	if(aRxBuffer[signVal+13]=='1')
//	{
//	 LaserPinState=1;
//	}
//	else{
//	 LaserPinState=0;
//	}
//
//	}
//	else{
//	 LaserPinState=0;
//	}
//
//
//
//
//}
}
void clearingDispBuffer()
{
int x=0;
for(;x<40;x++)
{
Disp[x]=0x00;

}

}
void function11()
{

//	TimingDelay4=20;
	TimingDelay4=6;
TimingDelay_Decrement4();
while(1)

{

if(TimingDelay4==1)
break;
}
//		GPIOC->BSRR = GPIO_PIN_8;//set bit as high

//HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9);


//GPIOB->BSRR = GPIO_PIN_4;//set bit as high
HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_SET);

//			TimingDelay4=25;
           TimingDelay4=12;
TimingDelay_Decrement4();
while(1)
{

if(TimingDelay4==1)
break;
}





clearingDispBuffer();
clearingFrameBuffer();

          frame[0]=0x01 ;//Timming
          frame[1]=0x01 ;//intensity
          frame[2]=0x02;//GPO
	      frame[3]=0x03;//TBD
	      frame[4]=0x05;//TBD
	      frame[5]=0x04;//TBD
//	      frame[6]=0x06;//0x38;
//	      frame[7]=0x02;//0x88;
//	      frame[8]=0x22;//0x09;
//	      frame[9]=0x02;//0x1D;
//	   	 	    	 	      frame[10]=0x03;//0x22;
//	   	 	    	 	      frame[11]=0x05;//0x40;
//	   	 	    	 	      frame[12]=0x04;//0x54;
//	   	 	    	 	      frame[13]=0x06;//0x38;
//	   	 	    	 	      frame[14]=0x02;//0x88;
//	   	 	    	 	      frame[15]=0x22;//0x09;
//	   	 	    	 	    frame[16]=0x02;//0x1D;
//	   	 	    	 	    frame[17]=0x03;//0x22;
//	   	 	    	 	    frame[18]=0x05;//0x40;
//	   	 	    	 	  	frame[19]=0x04;//0x54;
//	   	 	    	 	  	frame[20]=0xCC;//0x38;
//	   	 	    	 	  	frame[21]=0xCC;//0x88;
//	   	 	    	 	  	frame[22]=0x3E;//0x09;
	   //	 	      if(RecMsg2[9]==0x08)
	   //	 	      {
	   //	 	      frame[9]=0x09;//0x48;
	   //	 	      }
	   //	 	      else
	   //	 	      {
//	   	 	      frame[23]=0x32;
//	   	 	     frame[24]=0x36;
	   //	 	      }


	   	 //-------------------------data array------------------//
	   	 	      Disp[0]=frame[0];
	   	 	      Disp[1]=frame[1];
	   	 	      Disp[2]=frame[2];
	   	 	      Disp[3]=frame[3];
	   	 	      Disp[4]=frame[4];
	   	 	      Disp[5]=frame[5];
//	   	 	      Disp[6]=frame[8];
//	   	 	      Disp[7]=frame[9];
//	   	 	      Disp[8]=frame[10];
//	   	 	      Disp[9]=frame[10];
//	   	 	     Disp[10]= frame[11];
//	   	 	    Disp[11]= frame[12];
//	   	 	   Disp[12]= frame[13];
//	   	 	  Disp[13]= frame[14];
//	   	 	 Disp[14]= frame[15];
//	   	 	Disp[15]= frame[16];
//	   	 	Disp[16]=frame[17];
//	   	 	Disp[17]=frame[18];
//	   	 	Disp[18]=frame[19];
//	   	 	Disp[19]=frame[20];
//	   	 	Disp[20]=frame[21];
//	   	 	Disp[21]=frame[22];
//	   	 	Disp[22]=frame[23];
//	   	 	Disp[23]=frame[24];


	   		byteToIntegerVal(&Disp[0],0);
	   		 	       	CRCValue =	HAL_CRC_Calculate(&hcrc,(uint32_t *)stringInt, 8);
	   		 	       	intToByte(CRCValue);
	   		           frame[6]=crcVal[3]; //CRC
	   		           frame[7]=crcVal[2]; //CRC
	   		           frame[8]=crcVal[1]; //CRC
	   		           frame[9]=crcVal[0]; //CRC

	   //	 	       	byteToIntegerVal(&Disp[0],0);
	   //	 	       	CRCValue =	HAL_CRC_Calculate(&hcrc,(uint32_t *)stringInt, 8);
	   //	 	       	intToByte(CRCValue);
	   //	           frame[10]=crcVal[3];
	   //	           frame[11]=crcVal[2];
	   //	           frame[12]=crcVal[1];
	   //	           frame[13]=crcVal[0];




frame[10]=125 ;
frame[11]=125 ;

// frame[22]= 0 ;
// frame[23]= 0 ;
// frame[24]= 0 ;
clearingRecBuffer();
//puts2(&frame[0],1);
HAL_UART_Transmit (&huart1, (uint8_t*)frame,12,5000) ;


HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_RESET);

//puts3(&frame[0],14);
//
//			HAL_UART_Receive(&huart2, (uint8_t *)aRxBuffer, 20, 0xFFF);
//	signVal=msgParse((uint8_t *)aRxBuffer,"~~~~",0);
//if(!(signVal==0))
//{
//	if(aRxBuffer[signVal+12]==sideNo)
//	{
//	if(aRxBuffer[signVal+13]=='1')
//	{
//	 LaserPinState=1;
//	}
//	else{
//	 LaserPinState=0;
//	}
//
//	}
//	else{
//	 LaserPinState=0;
//	}
//
//
//
//
//}
}

void function10()//slave1 to master
 {

	 //	TimingDelay4=20;
	 	TimingDelay4=6;
	 TimingDelay_Decrement4();
	 while(1)

	 {

	 if(TimingDelay4==1)
	 break;
	 }
	 //		GPIOC->BSRR = GPIO_PIN_8;//set bit as high

	 //HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_8);


	 //GPIOB->BSRR = GPIO_PIN_4;//set bit as high
//	 HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET);
	 HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);

	 //			TimingDelay4=25;
	            TimingDelay4=12;
	 TimingDelay_Decrement4();
	 while(1)
	 {

	 if(TimingDelay4==1)
	 break;
	 }






	 clearingFrameBuffer();


	 pedestrain[0]=0xFF;
	 pedestrain[1]=0xFF;
	 powerStatus=1;


	           frame[0]=adcVal1;//0x01 ; //  (horizontal and vertical bit pattern)
	           frame[1]=adcVal2;//0x02 ; //  (horizontal and vertical bit pattern)
	           frame[2]=0x02;// segment byte (hundred place)
	 	      frame[3]=0x03;// segment byte (tens place)
	 	      frame[4]=0x05;// segment byte (unit place)
	 	      frame[5]=slaveNo;// slaveNo
	 	      frame[6]=0x06;// GPI
	 	      frame[7]=pedestrain[0];// pedestrain1
	 	      frame[8]=pedestrain[1];// pedestrain2
	 	                  frame[9]=powerStatus;//power status
 	 	    	 	      frame[10]=0x03;//TBD
 	 	    	 	      frame[11]=0x05;//TBD
 	 	    	 	      frame[12]=0x04;//TBD
 	 	    	 	      frame[13]=0x06;//TBD
// 	 	    	 	      frame[14]=0x02;//TBD
// 	 	    	 	      frame[15]=0x22;//TBD
// 	 	    	 	    frame[16]=0x02;//TBD
// 	 	    	 	    frame[17]=0x03;//TBD
// 	 	    	 	    frame[18]=0x05;//TBD
// 	 	    	 	  	frame[19]=0x04;//TBD
//	 	    	 	  	frame[20]=0x06;//0x38;
//	 	    	 	  	frame[21]=0x02;//0x88;
//	 	    	 	  	frame[22]=0x22;//0x09;
//	 	      if(RecMsg2[9]==0x08)
//	 	      {
//	 	      frame[9]=0x09;//0x48;
//	 	      }
//	 	      else
//	 	      {
//	 	      frame[23]=0x32;
//	 	     frame[24]=0x36;
//	 	      }


	 //-------------------------data array------------------//
	 	      Disp[0]=frame[0];
	 	      Disp[1]=frame[1];
	 	      Disp[2]=frame[2];
	 	      Disp[3]=frame[3];
	 	      Disp[4]=frame[4];
	 	      Disp[5]=frame[5];
	 	      Disp[6]=frame[6];
	 	      Disp[7]=frame[7];
	 	      Disp[8]=frame[8];
	 	      Disp[9]=frame[9];
 	 	      Disp[10]= frame[11];
 	 	      Disp[11]= frame[12];
 	 	      Disp[12]= frame[13];
 	 	      Disp[13]= frame[14];
// 	 	 Disp[14]= frame[15];
// 	 	Disp[15]= frame[16];
// 	 	Disp[16]=frame[17];
// 	 	Disp[17]=frame[18];
// 	 	Disp[18]=frame[19];
//	 	Disp[19]=frame[20];
//	 	Disp[20]=frame[21];
//	 	Disp[21]=frame[22];
//	 	Disp[22]=frame[23];
//	 	Disp[23]=frame[24];


		byteToIntegerVal(&Disp[0],0);
		 	       	CRCValue =	HAL_CRC_Calculate(&hcrc,(uint32_t *)stringInt, 8);
		 	       	intToByte(CRCValue);
		           frame[14]=crcVal[3]; //CRC
		           frame[15]=crcVal[2]; //CRC
		           frame[16]=crcVal[1]; //CRC
		           frame[17]=crcVal[0]; //CRC

//	 	       	byteToIntegerVal(&Disp[0],0);
//	 	       	CRCValue =	HAL_CRC_Calculate(&hcrc,(uint32_t *)stringInt, 8);
//	 	       	intToByte(CRCValue);
//	           frame[10]=crcVal[3];
//	           frame[11]=crcVal[2];
//	           frame[12]=crcVal[1];
//	           frame[13]=crcVal[0];




	 frame[18]=125 ;
	 frame[19]=125 ;

	 // frame[22]= 0 ;
	 // frame[23]= 0 ;
	 // frame[24]= 0 ;




	 //clearingRecBuffer();




	 //puts2(&frame[0],1);
	 HAL_UART_Transmit (&huart6, (uint8_t*)frame,20,5000) ;
	 HAL_UART_Transmit (&huart2, (uint8_t*)frame,20,5000) ;


//	 HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_RESET);
	 HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);

	 //puts3(&frame[0],14);
	 //
	 //			HAL_UART_Receive(&huart2, (uint8_t *)aRxBuffer, 20, 0xFFF);
	 //	signVal=msgParse((uint8_t *)aRxBuffer,"~~~~",0);
	 //if(!(signVal==0))
	 //{
	 //	if(aRxBuffer[signVal+12]==sideNo)
	 //	{
	 //	if(aRxBuffer[signVal+13]=='1')
	 //	{
	 //	 LaserPinState=1;
	 //	}
	 //	else{
	 //	 LaserPinState=0;
	 //	}
	 //
	 //	}
	 //	else{
	 //	 LaserPinState=0;
	 //	}
	 //
	 //
	 //
	 //
	 //}
}


void function6()
{

//	TimingDelay4=20;
	TimingDelay4=6;
TimingDelay_Decrement4();
while(1)

{

if(TimingDelay4==1)
break;
}
//		GPIOC->BSRR = GPIO_PIN_8;//set bit as high

//HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_8);


//GPIOB->BSRR = GPIO_PIN_4;//set bit as high
HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET);

//			TimingDelay4=25;
           TimingDelay4=12;
TimingDelay_Decrement4();
while(1)
{

if(TimingDelay4==1)
break;
}






clearingFrameBuffer();

          frame[0]=126 ;
          frame[1]=126 ;
          frame[2]=0x02;//0x1D;
	      frame[3]=0x03;//0x22;
	      frame[4]=0x05;//0x40;
	      frame[5]=0x04;//0x54;
	      frame[6]=0x06;//0x38;
	      frame[7]=0x02;//0x88;
	      frame[8]=0x22;//0x09;
//	      if(RecMsg2[9]==0x08)
//	      {
//	      frame[9]=0x09;//0x48;
//	      }
//	      else
//	      {
	      frame[9]=0x08;
//	      }


//-------------------------data array------------------//
	      Disp[0]=frame[2];
	      Disp[1]=frame[3];
	      Disp[2]=frame[4];
	      Disp[3]=frame[5];
	      Disp[4]=frame[6];
	      Disp[5]=frame[7];
	      Disp[6]=frame[8];
	      Disp[7]=frame[9];

	       	byteToIntegerVal(&Disp[0],0);
	       	CRCValue =	HAL_CRC_Calculate(&hcrc,(uint32_t *)stringInt, 8);
	       	intToByte(CRCValue);
          frame[10]=crcVal[3];
          frame[11]=crcVal[2];
          frame[12]=crcVal[1];
          frame[13]=crcVal[0];




frame[14]=125 ;
frame[15]=125 ;

// frame[22]= 0 ;
// frame[23]= 0 ;
// frame[24]= 0 ;




//clearingRecBuffer();




//puts2(&frame[0],1);
//HAL_UART_Transmit (&huart2, (uint8_t*)frame,16,5000) ;


HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_RESET);

//puts3(&frame[0],14);
//
//			HAL_UART_Receive(&huart2, (uint8_t *)aRxBuffer, 20, 0xFFF);
//	signVal=msgParse((uint8_t *)aRxBuffer,"~~~~",0);
//if(!(signVal==0))
//{
//	if(aRxBuffer[signVal+12]==sideNo)
//	{
//	if(aRxBuffer[signVal+13]=='1')
//	{
//	 LaserPinState=1;
//	}
//	else{
//	 LaserPinState=0;
//	}
//
//	}
//	else{
//	 LaserPinState=0;
//	}
//
//
//
//
//}
}


//int crcApi(void)
//	{
//		int zzzz = zxx9+frame[3] ;
//		zyy9=0;
//    zxx9 =4 ;
//		zzzz = zxx9+frame[3] ;
//		while(zxx9<zzzz)
//		{
//			zyy9=zyy9+frame[zxx9++];
//		}
//
//		return zyy9;



//	}
//
//	void clearARxbuffer(void)
//{
//int a =0 ;
//	for (a=0;a<100;a++)
//		{
//aRxBuffer[a]=0;

//}
//}


void transferRecValues(int cnt){

	   int i=0;
	   int counter;
	//   counter=cnt-2;
	   counter=cnt;
	   while (!(RecMsg2[i] == 0x7D))
		{
		   Data[i]=RecMsg2[counter];
		   i++;
		   counter++;

}
//	   Data[i++]=0x7D;
//	   Data[i]=0x7D;
	   cntVal=i;



}

void transferRecValuesToData(int cnt){
	   int counter;
	//   counter=cnt-2;
	   cnt=cnt+1;
	 //  while (!(RecMsg1[i] == 0x7D))
		for(int i=0;i<cnt;i++)
	   {
		   Data[i]=RecMsg4[i];
//		   i++;
//		   counter++;

}

//	   int i=0;
//	   int counter;
//	//   counter=cnt-2;
//	   counter=cnt;
//	   while (!(RecMsg2[i] == 0x7D))
//		{
//		   Data[i]=RecMsg2[counter];
//		   i++;
//		   counter++;
//
//}
////	   Data[i++]=0x7D;
////	   Data[i]=0x7D;
//	   cntVal=i;



}

void transferRecValuesToDataRecMsg2(int cnt){
	   int counter;
	//   counter=cnt-2;
	   cnt=cnt+1;
	 //  while (!(RecMsg1[i] == 0x7D))
		for(int i=0;i<cnt;i++)
	   {
		   Data[i]=RecMsg2[i];
//		   i++;
//		   counter++;

}

//	   int i=0;
//	   int counter;
//	//   counter=cnt-2;
//	   counter=cnt;
//	   while (!(RecMsg2[i] == 0x7D))
//		{
//		   Data[i]=RecMsg2[counter];
//		   i++;
//		   counter++;
//
//}
////	   Data[i++]=0x7D;
////	   Data[i]=0x7D;
//	   cntVal=i;



}



void transferRec1ValuesToData(int cnt)
{

	 //  int i=0;
	   int counter;
	//   counter=cnt-2;
	   cnt=cnt+1;
	 //  while (!(RecMsg1[i] == 0x7D))
		for(int i=0;i<cnt;i++)
	   {
		   Data[i]=RecMsg1[i];
//		   i++;
//		   counter++;

}
//	   Data[i++]=0x7D;
//	   Data[i]=0x7D;
//	   cntVal=i;



}




/*----------------laser slave---------------------*/
 void function6_A()
 {

	 //	TimingDelay4=20;
	 	TimingDelay4=6;
	 TimingDelay_Decrement4();
	 while(1)

	 {

	 if(TimingDelay4==1)
	 break;
	 }
	 //		GPIOC->BSRR = GPIO_PIN_8;//set bit as high

	 //HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_8);


	 //GPIOB->BSRR = GPIO_PIN_4;//set bit as high
	 HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET);

	 //			TimingDelay4=25;
	            TimingDelay4=12;
	 TimingDelay_Decrement4();
	 while(1)
	 {

	 if(TimingDelay4==1)
	 break;
	 }






	 clearingFrameBuffer();

	           frame[0]=126 ;
	           frame[1]=126 ;
	           frame[2]=0x02;//0x1D;
	 	      frame[3]=0x03;//0x22;
	 	      frame[4]=0x05;//0x40;
	 	      frame[5]=0x04;//0x54;
	 	      frame[6]=0x06;//0x38;
	 	      frame[7]=0x02;//0x88;
	 	      frame[8]=0x22;//0x09;
	 	                  frame[9]=0x02;//0x1D;
	 	    	 	      frame[10]=0x03;//0x22;
	 	    	 	      frame[11]=0x05;//0x40;
	 	    	 	      frame[12]=0x04;//0x54;
	 	    	 	      frame[13]=0x06;//0x38;
	 	    	 	      frame[14]=0x02;//0x88;
	 	    	 	      frame[15]=0x22;//0x09;
	 	    	 	    frame[16]=0x02;//0x1D;
	 	    	 	    frame[17]=0x03;//0x22;
	 	    	 	    frame[18]=0x05;//0x40;
	 	    	 	  	frame[19]=0x04;//0x54;
	 	    	 	  	frame[20]=0x06;//0x38;
	 	    	 	  	frame[21]=0x02;//0x88;
	 	    	 	  	frame[22]=0x22;//0x09;
//	 	      if(RecMsg2[9]==0x08)
//	 	      {
//	 	      frame[9]=0x09;//0x48;
//	 	      }
//	 	      else
//	 	      {
	 	      frame[23]=0x32;
	 	     frame[24]=0x36;
//	 	      }


	 //-------------------------data array------------------//
	 	      Disp[0]=frame[2];
	 	      Disp[1]=frame[3];
	 	      Disp[2]=frame[4];
	 	      Disp[3]=frame[5];
	 	      Disp[4]=frame[6];
	 	      Disp[5]=frame[7];
	 	      Disp[6]=frame[8];
	 	      Disp[7]=frame[9];
	 	      Disp[8]=frame[10];
	 	      Disp[9]=frame[10];
	 	     Disp[10]= frame[11];
	 	    Disp[11]= frame[12];
	 	   Disp[12]= frame[13];
	 	  Disp[13]= frame[14];
	 	 Disp[14]= frame[15];
	 	Disp[15]= frame[16];
	 	Disp[16]=frame[17];
	 	Disp[17]=frame[18];
	 	Disp[18]=frame[19];
	 	Disp[19]=frame[20];
	 	Disp[20]=frame[21];
	 	Disp[21]=frame[22];
	 	Disp[22]=frame[23];
	 	Disp[23]=frame[24];


		byteToIntegerVal(&Disp[0],0);
		 	       	CRCValue =	HAL_CRC_Calculate(&hcrc,(uint32_t *)stringInt, 8);
		 	       	intToByte(CRCValue);
		           frame[25]=crcVal[3];
		           frame[26]=crcVal[2];
		           frame[27]=crcVal[1];
		           frame[28]=crcVal[0];

//	 	       	byteToIntegerVal(&Disp[0],0);
//	 	       	CRCValue =	HAL_CRC_Calculate(&hcrc,(uint32_t *)stringInt, 8);
//	 	       	intToByte(CRCValue);
//	           frame[10]=crcVal[3];
//	           frame[11]=crcVal[2];
//	           frame[12]=crcVal[1];
//	           frame[13]=crcVal[0];




	 frame[29]=125 ;
	 frame[30]=125 ;

	 // frame[22]= 0 ;
	 // frame[23]= 0 ;
	 // frame[24]= 0 ;




	 //clearingRecBuffer();




	 //puts2(&frame[0],1);
//	 HAL_UART_Transmit (&huart2, (uint8_t*)frame,16,5000) ;
	 HAL_UART_Transmit (&huart6, (uint8_t*)frame,31,5000) ;


	 HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_RESET);

	 //puts3(&frame[0],14);
	 //
	 //			HAL_UART_Receive(&huart2, (uint8_t *)aRxBuffer, 20, 0xFFF);
	 //	signVal=msgParse((uint8_t *)aRxBuffer,"~~~~",0);
	 //if(!(signVal==0))
	 //{
	 //	if(aRxBuffer[signVal+12]==sideNo)
	 //	{
	 //	if(aRxBuffer[signVal+13]=='1')
	 //	{
	 //	 LaserPinState=1;
	 //	}
	 //	else{
	 //	 LaserPinState=0;
	 //	}
	 //
	 //	}
	 //	else{
	 //	 LaserPinState=0;
	 //	}
	 //
	 //
	 //
	 //
	 //}
}




void transferingRecMsg2ToaRxBuffer()
{
int x=0;
for(;x<20;x++)
{
frame[x]=RecMsg2[x];

}

}

void clearingRecBuffer()
{
int x=0;
for(;x<160;x++)
{
RecMsg2[x]=0x00;

}

}
void clearingDataBuffer()
{
int x=0;
for(;x<90;x++)
{
Data[x]=0x00;

}

}
void clearingStringIntBuffer()
{
int x=0;
for(;x<26;x++)
{
stringInt[x]=0x00;

}

}
void transferToaRxBuffer()
{

int x=0;
for(;x<20;x++)
{
aRxBuffer[x]=RecMsg2[x];

}



}

void clearingFrameBuffer()
{
int x=0;
for(;x<100;x++)
{
frame[x]=0x00;

}

}

void slaveSelection()
{

	if(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_14)){
	if(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_13))	{

		slaveNo=1;
		}}

	if(!HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_14)){
		if(!HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_13))	{

			slaveNo=2;
			}}

	if(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_14)){
			if(!HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_13))	{

				slaveNo=4;
				}}

	if(!HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_14)){
			if(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_13))	{

				slaveNo=3;
				}}


}




