#include "stm32f4xx_hal.h"



/*----------------------variable declaration-----------------------------------------------------*/
int state;
uint8_t  pinValue;
uint8_t  pinValue1;
uint8_t sideNo1;
uint8_t sideNo2;
uint8_t sideNo3;
uint8_t sideNo4;
uint8_t sideNo1N;
uint8_t sideNo2N;
uint8_t sideNo3N;
uint8_t sideNo4N;
extern  uint8_t Disp[30];
extern uint8_t RecMsg2[250];
extern unsigned long AdcVal[17];
extern ADC_HandleTypeDef hadc2;
extern ADC_HandleTypeDef hadc1;
extern uint8_t RecMsg4[250];
extern void checkFeedback();
void SetAdcChannel(unsigned long AdcChannel);
uint8_t adcVal1;
uint8_t adcVal2;
/*----------------------function declaration-----------------------------------------------------*/

void outputPin(uint8_t  pinValue,uint8_t  pinValue1);
void inputPin();
void offAll();


/*----------------------function definition-----------------------------------------------------*/
void outputPin(uint8_t  pinValue,uint8_t  pinValue1)
{

//uint8_t  pinValue=0xFF;
//uint8_t  pinValue1=0xFF;
//uint8_t  pinValue2=0xFF;

if(( pinValue & 0x01 )== 0x01){
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);

}
else
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);
	}

if(( pinValue & 0x02 )== 0x02){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_SET);

}
else
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET);
	}

if(( pinValue & 0x04 )== 0x04){
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);

}
else
{
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
	}

if(( pinValue & 0x08 )== 0x08){
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);

}
else
{
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
	}

if(( pinValue & 0x10 )== 0x10){
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);

}
else
{
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
	}

if(( pinValue & 0x20 )== 0x20){
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);

}
else
{
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
	}
if(( pinValue & 0x40 )== 0x40){
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_SET);

}
else
{
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_RESET);
	}

if(( pinValue & 0x80 )== 0x80){
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);

}
else
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);
	}
//-----------------------------------
if(( pinValue1 & 0x01 )== 0x01){
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_SET);

}
else
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, GPIO_PIN_RESET);
	}
if(( pinValue1 & 0x02 )== 0x02){
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_SET);

}
else
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);
	}
if(( pinValue1 & 0x04 )== 0x04){
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);

}
else
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
	}
if(( pinValue1 & 0x08 )== 0x08){
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);

}
else
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);
	}
if(( pinValue1 & 0x10 )== 0x10){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);

}
else
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
	}
if(( pinValue1 & 0x20 )== 0x20){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);

}
else
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
	}
if(( pinValue1 & 0x40 )== 0x40){
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_SET);

}
else
{
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_RESET);
	}
if(( pinValue1 & 0x80 )== 0x80){
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_SET);

}
else
{
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_RESET);
	}

//-----------------------------------
//if(( pinValue2 & 0x01 )== 0x01){
//	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, GPIO_PIN_SET);
//
//}
//else
//{
//	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, GPIO_PIN_RESET);
//	}
//if(( pinValue2 & 0x02 )== 0x02){
//	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
//
//}
//else
//{
//	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
//	}
//if(( pinValue2 & 0x04 )== 0x04){
//	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, GPIO_PIN_SET);
//
//}
//else
//{
//	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, GPIO_PIN_RESET);
//	}
//if(( pinValue2 & 0x08 )== 0x08){
//	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, GPIO_PIN_SET);
//
//}
//else
//{
//	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_15, GPIO_PIN_RESET);
//	}
//if(( pinValue2 & 0x10 )== 0x10){
//	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_SET);
//
//}
//else
//{
//	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_RESET);
//	}
//if(( pinValue2 & 0x20 )== 0x20){
//	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, GPIO_PIN_SET);
//
//}
//else
//{
//	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, GPIO_PIN_RESET);
//	}
//if(( pinValue2 & 0x40 )== 0x40){
//	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_SET);
//
//}
//else
//{
//	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_RESET);
//	}
//if(( pinValue2 & 0x80 )== 0x80){
//	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_SET);
//
//}
//else
//{
//	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_RESET);
//	}




}


void inputPin(){

	 pinValue=0x00;
	 pinValue1=0x00;


	if(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_7))	{
		pinValue=pinValue | 0x01;
		state=1;
	}
	else{
		//pinValue=pinValue & 0x00;
		pinValue=pinValue;
		state=0;
	}
	if(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_6))	{
		pinValue=pinValue | 0x02;
		state=1;
	}
	else{
		//pinValue=pinValue & 0x02;
		pinValue=pinValue;
		state=0;
	}
	if(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_3))	{
		pinValue=pinValue | 0x04;
		state=1;
	}
	else{
		//pinValue=pinValue & 0x04;
		pinValue=pinValue;
		state=0;
	}
	if(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_1))	{
		pinValue=pinValue | 0x08;
		state=1;
	}
	else{
		//pinValue=pinValue & 0x08;
		pinValue=pinValue;
		state=0;
	}
	if(HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_0))	{
		pinValue=pinValue | 0x10;
			state=1;
		}
		else{
		//	pinValue=pinValue & 0x10;
			pinValue=pinValue;
			state=0;
		}
	if( HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_11))	{
		pinValue=pinValue | 0x20;
			state=1;
		}
		else{
		//	pinValue=pinValue & 0x20;
			pinValue=pinValue;
			state=0;
		}
	if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_10))	{
		pinValue=pinValue | 0x40;
			state=1;
		}
		else{
		//	pinValue=pinValue & 0x40;
			pinValue=pinValue;
			state=0;
		}

	if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_15))	{
		pinValue=pinValue | 0x80;
		state=1;
	}
	else{
	//	pinValue=pinValue & 0x80;
		pinValue=pinValue;
		state=0;
	}
	/*------------------------2nd byte----------------------------*/
	if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_2))	{
		pinValue1=pinValue1 | 0x01;
		state=1;
		}
		else{
		//	pinValue=pinValue & 0x01;
			pinValue1=pinValue1;
			state=0;
		}
	if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_1))	{
		pinValue1=pinValue1 | 0x02;
		state=1;
		}
		else{
		//	pinValue=pinValue & 0x02;
			pinValue1=pinValue1;
			state=0;
		}
	if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_0))	{
		pinValue1=pinValue1 | 0x04;
		state=1;
		}
		else{
		//	pinValue=pinValue & 0x04;
			pinValue1=pinValue1;
			state=0;
		}
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_7))	{
		pinValue1=pinValue1 | 0x08;
			state=1;
			}
			else{
		//		pinValue=pinValue & 0x08;
				pinValue1=pinValue1;
				state=0;
			}
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_6))	{
		pinValue1=pinValue1 | 0x10;
			state=1;
		}
		else{
		//	pinValue=pinValue & 0x10;
			pinValue1=pinValue1;
			state=0;
		}
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_5))	{
		pinValue1=pinValue1 | 0x20;
			state=1;
		}
		else{
		//	pinValue=pinValue & 0x20;
			pinValue1=pinValue1;
			state=0;
		}
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0))	{
		pinValue1=pinValue1 | 0x40;
			state=1;
		}
		else{
		//	pinValue=pinValue & 0x40;
			pinValue1=pinValue1;
			state=0;
		}
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_3))	{
		pinValue1=pinValue1 | 0x80;
			state=1;
		}
		else{
	//		pinValue=pinValue & 0x80;
			pinValue1=pinValue1;
			state=0;
		}



}

void checkSide(){

//	RecMsg4[5]=0x84;//side13
//	RecMsg4[6]=0x38;
	/*----------------Separating the values of sides------------------*/
	sideNo1= RecMsg4[5] >> 4; // right shift 4 bit
	sideNo1=sideNo1 << 4 ; //left shift 4 bit
    /*-----------------making it for 8bit--------------for ex-side1=0x80 converting it to 0x88*/
	sideNo1N=sideNo1 >> 4;
	sideNo1N=sideNo1^sideNo1N;

	sideNo3=  RecMsg4[5] ^ sideNo1; //

    sideNo3N=sideNo3 << 4;
    sideNo3N=sideNo3N^sideNo3;


	sideNo2= RecMsg4[6] >> 4; // right shift 4 bit
	sideNo2=sideNo2 << 4 ; //left shift 4 bit

	/*-----------------making it for 8bit--------------for ex-side1=0x80 converting it to 0x88*/
		sideNo2N=sideNo2 >> 4;
		sideNo2N=sideNo2^sideNo2N;


	sideNo4=  RecMsg4[6] ^ sideNo2; //

	sideNo4N=sideNo4 << 4;
	sideNo4N=sideNo4N^sideNo4;




}


void checkFeedback(){

	adcVal1=0;
	adcVal2=0;
	/*-------------------ADC---------------------------*/

	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_RESET); //a       0
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_RESET); //b       0
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_RESET); //c       0
	//for channel 0

	SetAdcChannel(ADC_CHANNEL_9);
	HAL_ADC_Start(&hadc2);
	HAL_ADC_PollForConversion(&hadc2, 100);

	AdcVal[1] = HAL_ADC_GetValue(&hadc2);

	/*--------------updating the value of adc variable-----------------------*/
   if(AdcVal[1]>100)
   {
	adcVal1=adcVal1^0x01;
   }
   else{
	adcVal1=adcVal1&0xFE;
   }

	SetAdcChannel(ADC_CHANNEL_8);
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, 100);

	AdcVal[9] = HAL_ADC_GetValue(&hadc1);

	/*--------------updating the value of adc variable-----------------------*/
   if(AdcVal[9]>100)
   {
	adcVal2=adcVal2^0x01;
   }
   else{
	adcVal2=adcVal2&0xFE;
   }

	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_SET);		//a       1
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_RESET);		//b   0
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_RESET);		//c   0
	//for channel 1

	SetAdcChannel(ADC_CHANNEL_9);
	HAL_ADC_Start(&hadc2);
	HAL_ADC_PollForConversion(&hadc2, 100);

	AdcVal[2] = HAL_ADC_GetValue(&hadc2);

	/*--------------updating the value of adc variable-----------------------*/
   if(AdcVal[2]>100)
   {
	adcVal1=adcVal1^0x02;
   }
   else{
	adcVal1=adcVal1&0xFD;
   }


	SetAdcChannel(ADC_CHANNEL_8);
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, 100);

	AdcVal[10] = HAL_ADC_GetValue(&hadc1);

	/*--------------updating the value of adc variable-----------------------*/
   if(AdcVal[10]>100)
   {
	adcVal2=adcVal2^0x02;
   }
   else{
	adcVal2=adcVal2&0xFD;
   }

	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_RESET);	//a     0
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET);	//b         1
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_RESET);	//c     0
	//for channel 2

	SetAdcChannel(ADC_CHANNEL_9);
	HAL_ADC_Start(&hadc2);
	HAL_ADC_PollForConversion(&hadc2, 100);

	AdcVal[3] = HAL_ADC_GetValue(&hadc2);

	/*--------------updating the value of adc variable-----------------------*/
   if(AdcVal[3]>100)
   {
	adcVal1=adcVal1^0x04;
   }
   else{
	adcVal1=adcVal1&0xFB;
   }


	SetAdcChannel(ADC_CHANNEL_8);
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, 100);

	AdcVal[11] = HAL_ADC_GetValue(&hadc1);

	/*--------------updating the value of adc variable-----------------------*/
   if(AdcVal[11]>100)
   {
	adcVal2=adcVal2^0x04;
   }
   else{
	adcVal2=adcVal2&0xFB;
   }

	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_SET);		//a       1
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET);		//b       1
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_RESET);		//c   0
	//for channel 3

	SetAdcChannel(ADC_CHANNEL_9);
	HAL_ADC_Start(&hadc2);
	HAL_ADC_PollForConversion(&hadc2, 100);

	AdcVal[4] = HAL_ADC_GetValue(&hadc2);

	/*--------------updating the value of adc variable-----------------------*/
   if(AdcVal[4]>100)
   {
	adcVal1=adcVal1^0x08;
   }
   else{
	adcVal1=adcVal1&0xF7;
   }

	SetAdcChannel(ADC_CHANNEL_8);
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, 100);

	AdcVal[12] = HAL_ADC_GetValue(&hadc1);

	/*--------------updating the value of adc variable-----------------------*/
   if(AdcVal[12]>100)
   {
	adcVal2=adcVal2^0x08;
   }
   else{
	adcVal2=adcVal2&0xF7;
   }


	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_RESET);	//a         0
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_RESET);	//b         0
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET);		//c         1
	//for channel 4

	SetAdcChannel(ADC_CHANNEL_9);
	HAL_ADC_Start(&hadc2);
	HAL_ADC_PollForConversion(&hadc2, 100);

	AdcVal[5] = HAL_ADC_GetValue(&hadc2);

	/*--------------updating the value of adc variable-----------------------*/
   if(AdcVal[5]>100)
   {
	adcVal1=adcVal1^0x10;
   }
   else{
	adcVal1=adcVal1&0xEF;
   }

	SetAdcChannel(ADC_CHANNEL_8);
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, 100);

	AdcVal[13] = HAL_ADC_GetValue(&hadc1);

	/*--------------updating the value of adc variable-----------------------*/
   if(AdcVal[13]>100)
   {
	adcVal2=adcVal2^0x10;
   }
   else{
	adcVal2=adcVal2&0xEF;
   }

	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_SET);		//a        1
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_RESET);	//b        0
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET);		//c        1
	//for channel 5

	SetAdcChannel(ADC_CHANNEL_9);
	HAL_ADC_Start(&hadc2);
	HAL_ADC_PollForConversion(&hadc2, 100);

	AdcVal[6] = HAL_ADC_GetValue(&hadc2);

	/*--------------updating the value of adc variable-----------------------*/
   if(AdcVal[6]>100)
   {
	adcVal1=adcVal1^0x20;
   }
   else{
	adcVal1=adcVal1&0xDF;
   }

	SetAdcChannel(ADC_CHANNEL_8);
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, 100);

	AdcVal[14] = HAL_ADC_GetValue(&hadc1);

	/*--------------updating the value of adc variable-----------------------*/
   if(AdcVal[14]>100)
   {
	adcVal2=adcVal2^0x20;
   }
   else{
	adcVal2=adcVal2&0xDF;
   }

	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_RESET);	//a      0
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET);		//b      1
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET);		//c      1
	//for channel 6

	SetAdcChannel(ADC_CHANNEL_9);
	HAL_ADC_Start(&hadc2);
	HAL_ADC_PollForConversion(&hadc2, 100);

	AdcVal[7] = HAL_ADC_GetValue(&hadc2);

	/*--------------updating the value of adc variable-----------------------*/
   if(AdcVal[7]>100)
   {
	adcVal1=adcVal1^0x40;
   }
   else{
	adcVal1=adcVal1&0xBF;
   }

	SetAdcChannel(ADC_CHANNEL_8);
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, 100);

	AdcVal[15] = HAL_ADC_GetValue(&hadc1);

	/*--------------updating the value of adc variable-----------------------*/
   if(AdcVal[15]>100)
   {
	adcVal2=adcVal2^0x40;
   }
   else{
	adcVal2=adcVal2&0xBF;
   }

//	       AdcVal[1] = HAL_ADC_GetValue(&hadc2);

	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_SET);	//a        1
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET);	//b        1
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET);	//c        1
	//for channel 6

	SetAdcChannel(ADC_CHANNEL_9);
	HAL_ADC_Start(&hadc2);
	HAL_ADC_PollForConversion(&hadc2, 100);

	AdcVal[8] = HAL_ADC_GetValue(&hadc2);

	/*--------------updating the value of adc variable-----------------------*/
   if(AdcVal[8]>100)
   {
	adcVal1=adcVal1^0x80;
   }
   else{
	adcVal1=adcVal1&0x7F;
   }

	SetAdcChannel(ADC_CHANNEL_8);
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, 100);

	AdcVal[16] = HAL_ADC_GetValue(&hadc1);

	/*--------------updating the value of adc variable-----------------------*/
   if(AdcVal[16]>100)
   {
	adcVal2=adcVal2^0x80;
   }
   else{
	adcVal2=adcVal2&0x7F;
   }

/*-----------------if adcVal1 or adcVal2 is 0, making it 0xFF-----------------*/

   if(adcVal1==0x00){
	   adcVal1=0xFF;
   }
   if(adcVal2==0x00){
	   adcVal2=0xFF;

   }





}


void offAll(){
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_15, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_RESET);
}





