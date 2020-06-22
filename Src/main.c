/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;
ADC_HandleTypeDef hadc2;

CRC_HandleTypeDef hcrc;

TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim5;
TIM_HandleTypeDef htim10;
TIM_HandleTypeDef htim11;
TIM_HandleTypeDef htim13;
TIM_HandleTypeDef htim14;

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;
UART_HandleTypeDef huart3;
UART_HandleTypeDef huart6;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/
 uint32_t TimingDelay;
uint32_t TimingDelay1;
uint32_t TimingDelay2;
 uint32_t TimingDelay3;
uint32_t TimingDelay4;
uint32_t TimingDelay5;

uint8_t aRxBuffer1[225];
uint8_t aRxBuffer3[225];
uint8_t aRxBuffer4[225];
uint8_t aRxBuffer[225];
int msgUnPrcd;
int msgUnPrcd1;
int msgUnPrcd3;
int msgUnPrcd4;

extern uint8_t RecMsg2[250];
extern uint8_t RecMsg4[250];
int signVal ;
uint8_t Data[100] ;
uint32_t CRCValue ;
extern uint32_t stringInt[25]; // string array to store messege received in uart
uint32_t crcbits;
char crcstring[4];
int commFlag;
int commFlag=0;
extern int slaveNo;
unsigned long AdcVal[17];
int pulse1=0;
extern uint8_t sideNo1;
extern uint8_t sideNo2;
extern uint8_t sideNo3;
extern uint8_t sideNo4;
extern uint8_t sideNo1N;
extern uint8_t sideNo2N;
extern uint8_t sideNo3N;
extern uint8_t sideNo4N;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_USART3_UART_Init(void);
static void MX_USART6_UART_Init(void);
static void MX_TIM14_Init(void);
static void MX_TIM13_Init(void);
static void MX_TIM11_Init(void);
static void MX_TIM10_Init(void);
static void MX_CRC_Init(void);
static void MX_TIM5_Init(void);
static void MX_ADC2_Init(void);
static void MX_TIM3_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_ADC1_Init(void);
/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/
static void setPWM(TIM_HandleTypeDef, uint32_t, uint16_t, uint16_t);
//extern void outputPin();
extern void inputPin();

void TimingDelay_Decrement();
void TimingDelay_Decrement1();
void TimingDelay_Decrement2();
void TimingDelay_Decrement3();
void TimingDelay_Decrement4();
void TimingDelay_Decrement5();
void SetAdcChannel(unsigned long AdcChannel);

extern uint32_t HAL_CRC_Calculate(CRC_HandleTypeDef *hcrc, uint32_t pBuffer[], uint32_t BufferLength);
extern void transferRecValues(int cnt);
extern void transferRecValuesToData(int cnt);
extern void function6();
extern void function10();
extern void function66();
extern void function6_A();
extern void transferRec1ValuesToData(int cnt);
void setPWMPin(uint8_t  pinValue,uint8_t  pinValue1,uint8_t pulse);
extern void clearingStringIntBuffer();
extern void clearingDataBuffer();
extern void clearBuffer();
extern void	clearaRxBuffer();
extern void byteToIntegerVal(char *dat,uint8_t index);
extern void slaveSelection();
extern void outputPin(uint8_t  pinValue,uint8_t  pinValue1);
extern short msgParse(uint8_t *SPtr , char *sigPtr , short pointer);
extern void checkSide();
extern void clearBuffer4();
extern void clearaRxBuffer4();
extern void checkFeedback();
extern void offAll();
extern void transferRecValuesToDataRecMsg2(int cnt);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */
  

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  MX_USART3_UART_Init();
  MX_USART6_UART_Init();
  MX_TIM14_Init();
  MX_TIM13_Init();
  MX_TIM11_Init();
  MX_TIM10_Init();
  MX_CRC_Init();
  MX_TIM5_Init();
  MX_ADC2_Init();
  MX_TIM3_Init();
  MX_USART2_UART_Init();
  MX_ADC1_Init();
  /* USER CODE BEGIN 2 */
//            HAL_UART_Receive_IT(&huart2, (uint8_t *)aRxBuffer,1); // everytime have to enable uart2 interrupt
         	HAL_UART_Receive_IT(&huart1, (uint8_t *)aRxBuffer1,1); // everytime have to enable uart2 interrupt
         	HAL_UART_Receive_IT(&huart3, (uint8_t *)aRxBuffer3,1); // everytime have to enable uart2 interrupt
//         	HAL_UART_Receive_IT(&huart4, (uint8_t *)aRxBuffer4,1); // everytime have to enable uart2 interrupt
//         	HAL_UART_Receive_IT(&huart5, (uint8_t *)aRxBuffer5,1); // everytime have to enable uart2 interrupt
         	 HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);

         	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_SET);//G2
//         	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_RESET);//G2
         	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);//G2
//         	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);//G2

         	slaveSelection();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		HAL_UART_Receive_IT(&huart2, (uint8_t *)aRxBuffer4,1); // everytime have to enable uart2 interrupt

	  HAL_UART_Receive_IT(&huart6, (uint8_t *)aRxBuffer,1); // everytime have to enable uart6 interrupt
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
//	  	  setPWM(htim14, TIM_CHANNEL_1, 255, 50);    //PA7
//	  	  setPWM(htim13, TIM_CHANNEL_1, 255, 50);    //PA6
//	  	  setPWM(htim12, TIM_CHANNEL_1, 255, 50);    //PB14
//	  	  setPWM(htim12, TIM_CHANNEL_2, 255, 50);   //PB15
//	  	  setPWM(htim11, TIM_CHANNEL_1, 255, 50);   //PB9
//	  	  setPWM(htim10, TIM_CHANNEL_1, 255, 50);  //PB8
//	  	  setPWM(htim9, TIM_CHANNEL_1, 255, 50);   //PE5
//	  	  setPWM(htim9, TIM_CHANNEL_2, 255, 50);   //PE6
//	  	     HAL_Delay(3000);
//
//	  	      setPWM(htim14, TIM_CHANNEL_1, 255, 100);    //PA7
//	  	      setPWM(htim13, TIM_CHANNEL_1, 255, 100);    //PA6
//	  		  setPWM(htim12, TIM_CHANNEL_1, 255, 100);    //PB14
//	  		  setPWM(htim12, TIM_CHANNEL_2, 255, 100);   //PB15
//	  		  setPWM(htim11, TIM_CHANNEL_1, 255, 100);   //PB9
//	  		  setPWM(htim10, TIM_CHANNEL_1, 255, 100);  //PB8
//	  		  setPWM(htim9, TIM_CHANNEL_1, 255, 100);   //PE5
//	  		  setPWM(htim9, TIM_CHANNEL_2, 255, 100);   //PE6
//	  		  HAL_Delay(3000);
//
//	  			      setPWM(htim14, TIM_CHANNEL_1, 255, 150);    //PA7
//	  			      setPWM(htim13, TIM_CHANNEL_1, 255, 150);    //PA6
//	  				  setPWM(htim12, TIM_CHANNEL_1, 255, 150);    //PB14
//	  				  setPWM(htim12, TIM_CHANNEL_2, 255, 150);   //PB15
//	  				  setPWM(htim11, TIM_CHANNEL_1, 255, 150);   //PB9
//	  				  setPWM(htim10, TIM_CHANNEL_1, 255, 150);  //PB8
//	  				  setPWM(htim9, TIM_CHANNEL_1, 255, 150);   //PE5
//	  				  setPWM(htim9, TIM_CHANNEL_2, 255, 150);   //PE6
//	  				  HAL_Delay(3000);
//
//	  					      setPWM(htim14, TIM_CHANNEL_1, 255, 200);    //PA7
//	  					      setPWM(htim13, TIM_CHANNEL_1, 255, 200);    //PA6
//	  						  setPWM(htim12, TIM_CHANNEL_1, 255, 200);    //PB14
//	  						  setPWM(htim12, TIM_CHANNEL_2, 255, 200);   //PB15
//	  						  setPWM(htim11, TIM_CHANNEL_1, 255, 200);   //PB9
//	  						  setPWM(htim10, TIM_CHANNEL_1, 255, 200);  //PB8
//	  						  setPWM(htim9, TIM_CHANNEL_1, 255, 200);   //PE5
//	  						  setPWM(htim9, TIM_CHANNEL_2, 255, 200);   //PE6
//	  						  HAL_Delay(3000);
//
//	  							      setPWM(htim14, TIM_CHANNEL_1, 255, 250);    //PA7
//	  							      setPWM(htim13, TIM_CHANNEL_1, 255, 250);    //PA6
//	  								  setPWM(htim12, TIM_CHANNEL_1, 255, 250);    //PB14
//	  								  setPWM(htim12, TIM_CHANNEL_2, 255, 250);   //PB15
//	  								  setPWM(htim11, TIM_CHANNEL_1, 255, 250);   //PB9
//	  								  setPWM(htim10, TIM_CHANNEL_1, 255, 250);  //PB8
//	  								  setPWM(htim9, TIM_CHANNEL_1, 255, 250);   //PE5
//	  								  setPWM(htim9, TIM_CHANNEL_2, 255, 250);   //PE6
//	  								  HAL_Delay(3000);

//	  checkFeedback();
//	  /*----------------------------slave1 new-----------------------------------------*/
////	 /*uart6*/
//	if(msgUnPrcd==1)
//	 /*uart2*/
	if(msgUnPrcd4==1)
	{


//	functionRec=0;
	signVal=msgParse((uint8_t *)RecMsg4,"}}",0); //for slave
	//					  		signVal=msgParse((uint8_t *)RecMsg2,"~~~~",0);  //for master
	if(!(signVal==0))
	{
      transferRecValuesToData(19);
	  byteToIntegerVal(&Data[0],0);
	  CRCValue = HAL_CRC_Calculate(&hcrc,(uint32_t *)stringInt, 8);
	  crcbits =	CRCValue;

	  crcstring[0] = crcbits & 0xFF;

	  crcstring[1] = (crcbits >> 8) & 0xFF;

	  crcstring[2] = (crcbits >> 16) & 0xFF;

	  crcstring[3] = (crcbits >> 24) & 0xFF;
	  //					  		CRC_ResetDR();
	  /*-------------------------slave side-----------------------------------*/
	 //					  		if(RecMsg2[10] == crcstring[3])
	 //					  		{
	 //					  		if(RecMsg2[11] == crcstring[2])
	 //					  		{
	 //					  		if(RecMsg2[12] == crcstring[1])
	 //					  		{
	 //					  		if(RecMsg2[13] == crcstring[0])
	 if(RecMsg4[20] == crcstring[3])
	 {
	if(RecMsg4[21] == crcstring[2])
	 {
	 if(RecMsg4[22] == crcstring[1])
	 {
	 if(RecMsg4[23] == crcstring[0]){

		 if(RecMsg4[10]==slaveNo)
		 {
	HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_3);//master
//	function6_A();//usart6
			 checkSide();
			 if(slaveNo==1){
			 setPWMPin(sideNo1,sideNo3,RecMsg4[8]);//pin1 pin2 pwm
			 }
			 if(slaveNo==2){
			 setPWMPin(sideNo1,sideNo2,RecMsg4[8]);//pin1 pin2 pwm
			 }
			 if(slaveNo==3){
//			 setPWMPin(sideNo3N,sideNo3N,RecMsg4[8]);//pin1 pin2 pwm
//				 setPWMPin(sideNo3N,sideNo3N,RecMsg4[8]);//pin1 pin2 pwm
				 setPWMPin(sideNo3N,sideNo3N,RecMsg4[8]);//pin1 pin2 pwm
			 }
			 if(slaveNo==4){
			 setPWMPin(sideNo4,sideNo4,RecMsg4[8]);//pin1 pin2 pwm
			 }

			 checkFeedback();
	function10();

		 }
//	millisec1=0;
	commFlag=1;

		  			//function6_A(); ///slave1
	 /*---------master-----------*/
	//						  			if(commFlag==0)
	//						  			{
	//						  			function6(); //master
	//						  			}
	//						  			if(RecMsg2[9]==0x09){
	////						  				function66();
   //						  				commFlag=1;
   //						  			}
	  	  }

	  	}
	  	 }
	  	 }
	  	  		 // clearingRecBuffer();
	  	//						  		commFlag=1;
//	  	  	sec=0;
	  	  	msgUnPrcd4=0;

	  	  	}


	 //		  			  	signVal=msgParse((uint8_t *)RecMsg2,"~~~~",0);
	  	 //		  			  if (!(signVal == 0 )){
	  	 //		  			  			// transferDataValues(signVal);
	  	//		  				checkMsgLengthForUart2();
	  	//		  			  	HAL_UART_Transmit (&huart1, (uint8_t*)RecMsg2,recCnt1,5000) ;
	  	  		//		  			  		  			  		}
	    clearBuffer4();
	    clearaRxBuffer4();
	    msgUnPrcd4=0;
	  	//	transmit();
     }


/*-------------------------LORA (uart6)-----------------------*/
	if(msgUnPrcd==1)
	{


//	functionRec=0;
	signVal=msgParse((uint8_t *)RecMsg2,"}}",0); //for slave
	//					  		signVal=msgParse((uint8_t *)RecMsg2,"~~~~",0);  //for master
	if(!(signVal==0))
	{
	  transferRecValuesToDataRecMsg2(19);
	  byteToIntegerVal(&Data[0],0);
	  CRCValue = HAL_CRC_Calculate(&hcrc,(uint32_t *)stringInt, 8);
	  crcbits =	CRCValue;

	  crcstring[0] = crcbits & 0xFF;

	  crcstring[1] = (crcbits >> 8) & 0xFF;

	  crcstring[2] = (crcbits >> 16) & 0xFF;

	  crcstring[3] = (crcbits >> 24) & 0xFF;
	  //					  		CRC_ResetDR();
	  /*-------------------------slave side-----------------------------------*/
	 //					  		if(RecMsg2[10] == crcstring[3])
	 //					  		{
	 //					  		if(RecMsg2[11] == crcstring[2])
	 //					  		{
	 //					  		if(RecMsg2[12] == crcstring[1])
	 //					  		{
	 //					  		if(RecMsg2[13] == crcstring[0])
	 if(RecMsg2[20] == crcstring[3])
	 {
	if(RecMsg2[21] == crcstring[2])
	 {
	 if(RecMsg2[22] == crcstring[1])
	 {
	 if(RecMsg2[23] == crcstring[0]){

		 if(RecMsg2[10]==slaveNo)
		 {
	HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_3);//master
//	function6_A();//usart6
			 checkSide();
			 if(slaveNo==1){
			 setPWMPin(sideNo1,sideNo3,RecMsg2[8]);//pin1 pin2 pwm
			 }
			 if(slaveNo==2){
			 setPWMPin(sideNo2,sideNo4,RecMsg2[8]);//pin1 pin2 pwm
			 }
			 if(slaveNo==3){
//			 setPWMPin(sideNo3N,sideNo3N,RecMsg4[8]);//pin1 pin2 pwm
				 setPWMPin(sideNo3,sideNo1,RecMsg2[8]);//pin1 pin2 pwm
			 }
			 if(slaveNo==4){
			 setPWMPin(sideNo4,sideNo2,RecMsg2[8]);//pin1 pin2 pwm
			 }

			 checkFeedback();
	function10();

		 }
//	millisec1=0;
	commFlag=1;

		  			//function6_A(); ///slave1
	 /*---------master-----------*/
	//						  			if(commFlag==0)
	//						  			{
	//						  			function6(); //master
	//						  			}
	//						  			if(RecMsg2[9]==0x09){
	////						  				function66();
   //						  				commFlag=1;
   //						  			}
	  	  }

	  	}
	  	 }
	  	 }
	  	  		 // clearingRecBuffer();
	  	//						  		commFlag=1;
//	  	  	sec=0;
	  	  	msgUnPrcd=0;

	  	  	}


	 //		  			  	signVal=msgParse((uint8_t *)RecMsg2,"~~~~",0);
	  	 //		  			  if (!(signVal == 0 )){
	  	 //		  			  			// transferDataValues(signVal);
	  	//		  				checkMsgLengthForUart2();
	  	//		  			  	HAL_UART_Transmit (&huart1, (uint8_t*)RecMsg2,recCnt1,5000) ;
	  	  		//		  			  		  			  		}
	    clearBuffer();
	    clearaRxBuffer();
	    msgUnPrcd=0;
	  	//	transmit();
     }














	   if(commFlag==1){
//	  	  function66();
	  	 commFlag++;
	  	 }

	   if(commFlag==3){
	  		commFlag=0;
	   }


///*--------------------------------------------slave2-----------------------------------------*/
//	  /*uart1 PA10 & PA9*/
//	 	if(msgUnPrcd1==1)
//	  	{
//
//
//	  	  signVal=msgParse((uint8_t *)RecMsg1,"}",0); //for slave
//	//					  		signVal=msgParse((uint8_t *)RecMsg2,"~~~~",0);  //for master
//	  	if(!(signVal==0))
//	  	{
//	  		signVal=signVal-6;
//	  	  	transferRec1ValuesToData(signVal);
////	  	  Data[0]=0x01 ;//Timming
////	  	Data[1]=0x01 ;//intensity
////	  	Data[2]=0x02;//GPO
////	  	Data[3]=0x03;//TBD
////	  	Data[4]=0x05;//TBD
////	  	Data[5]=0x04;//TBD
////	  	  transferRec1ValuesToData(0);
//	  	    byteToIntegerVal(&Data[0],0);
//	  	  	CRCValue = HAL_CRC_Calculate(&hcrc,(uint32_t *)stringInt, 8);
//	  	  	crcbits =	CRCValue;
//
//	  	  	crcstring[0] = crcbits & 0xFF;
//
//	  	    crcstring[1] = (crcbits >> 8) & 0xFF;
//
//	  	    crcstring[2] = (crcbits >> 16) & 0xFF;
//
//	  	   crcstring[3] = (crcbits >> 24) & 0xFF;
//	  	//					  		CRC_ResetDR();
//	   /*-------------------------slave side-----------------------------------*/
//	 //					  		if(RecMsg2[10] == crcstring[3])
//	 //					  		{
//	 //					  		if(RecMsg2[11] == crcstring[2])
//	//					  		{
//	//					  		if(RecMsg2[12] == crcstring[1])
//	//					  		{
//	//					  		if(RecMsg2[13] == crcstring[0])
//	/*-------------------------master side----------------------------------*/
////	  	 function66();
//	  	if(RecMsg1[6] == crcstring[3])
//	  	  {
//	    if(RecMsg1[7] == crcstring[2])
//	  	  {
//	  	if(RecMsg1[8] == crcstring[1])
//	  	  {
//	    if(RecMsg1[9] == crcstring[0]){
//	  	//					  			function6_A(); ///slave
//	 HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_8);//master
//	 //			  			function66();//slave2
//	//				  			if(RecMsg1[9]==0x08){ //slave1
//	//				  				commFlag=0x04;
////	  		if((commFlag>1)&&(commFlag<3)){
//	  	  	function66();
//	  	  pinValue1=RecMsg1[0];
//		  pinValue2=RecMsg1[1];
//	  	  pulseVal =RecMsg1[2];
//	  	  	if((pulseVal != pulseValLast)||(pinValue1 !=pinValue1Last)||(pinValue2 !=pinValue2Last))
//	  	  	{
//	  	  	pulseValLast=pulseVal;
//	  	  pinValue1Last=pinValue1;
//	  	pinValue2Last=pinValue2;
//
////	  	  pulseCnt++;
////	  	  if(pulseCnt>15){
////	  		pulseVal=0;
////	  		pulseVal=pulseVal+25;
//	  		setPWMPin(RecMsg1[0],RecMsg1[1],RecMsg1[2]);
//	  	  	}
////	  		if(pulseVal>250){
////	  			  		pulseVal=25;
////	  			  	}
////	  		pulseCnt=0;
////	  	  }
//
////	  	setPWMPin(pulseVal);
////	  	pulseVal=pulseVal+2;
////	  	if(pulseVal==250){
////	  		pulseVal=2;
////	  	}
////	  	  commFlag++;
//
////	  	}
//
//	  	  									       	//				  			}
//
//	  	  									       					  			//function6(); //master
//	  	  									       		//			  			if(RecMsg2[9]==0x09){
//	  	  									       		//			  				function66();
//	  	  									       		//			  			}
//	  	  									       					  		}
//
//	  	  									       				  		}
//	  	  									       				  		}
//	  	  									       				  		}
//	  	  									       				  		 // clearingRecBuffer();
//	  	  									       					  	//	commFlag=1;
//	  	  									       					  		sec=0;
//	  	  									       					  		msgUnPrcd1=0;
//
//	  	  									       				  				}
//
//
//
////	  	clearingStringIntBuffer();
//	  	clearingDataBuffer();
//	  	clearBuffer1();
//	  	clearaRxBuffer1();
//	  	msgUnPrcd1=0;
//	  	  									       							//	transmit();
//	  	}
//
//	 	/*--------------------------------------------slave2-----------------------------------------*/
/*-------------------ADC---------------------------*/

//	   HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_RESET);//a
//	   HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET);//b
//	   HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET);//c
////for channel 6
//
//	   SetAdcChannel(ADC_CHANNEL_9);
//	   HAL_ADC_Start(&hadc2);
//	   HAL_ADC_PollForConversion(&hadc2,100);
//
//
//
//	   AdcVal = HAL_ADC_GetValue(&hadc2);


  /* USER CODE BEGIN 3 */

  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */
  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion) 
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.ScanConvMode = DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time. 
  */
  sConfig.Channel = ADC_CHANNEL_8;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief ADC2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC2_Init(void)
{

  /* USER CODE BEGIN ADC2_Init 0 */

  /* USER CODE END ADC2_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC2_Init 1 */

  /* USER CODE END ADC2_Init 1 */
  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion) 
  */
  hadc2.Instance = ADC2;
  hadc2.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
  hadc2.Init.Resolution = ADC_RESOLUTION_12B;
  hadc2.Init.ScanConvMode = DISABLE;
  hadc2.Init.ContinuousConvMode = DISABLE;
  hadc2.Init.DiscontinuousConvMode = DISABLE;
  hadc2.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc2.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc2.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc2.Init.NbrOfConversion = 1;
  hadc2.Init.DMAContinuousRequests = DISABLE;
  hadc2.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc2) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time. 
  */
  sConfig.Channel = ADC_CHANNEL_9;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc2, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC2_Init 2 */

  /* USER CODE END ADC2_Init 2 */

}

/**
  * @brief CRC Initialization Function
  * @param None
  * @retval None
  */
static void MX_CRC_Init(void)
{

  /* USER CODE BEGIN CRC_Init 0 */

  /* USER CODE END CRC_Init 0 */

  /* USER CODE BEGIN CRC_Init 1 */

  /* USER CODE END CRC_Init 1 */
  hcrc.Instance = CRC;
  if (HAL_CRC_Init(&hcrc) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CRC_Init 2 */

  /* USER CODE END CRC_Init 2 */

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 0;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 0;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_PWM_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */
  HAL_TIM_MspPostInit(&htim3);

}

/**
  * @brief TIM5 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM5_Init(void)
{

  /* USER CODE BEGIN TIM5_Init 0 */

  /* USER CODE END TIM5_Init 0 */

  /* USER CODE BEGIN TIM5_Init 1 */

  /* USER CODE END TIM5_Init 1 */
  htim5.Instance = TIM5;
  htim5.Init.Prescaler = 0;
  htim5.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim5.Init.Period = 0;
  htim5.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim5.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_OnePulse_Init(&htim5, TIM_OPMODE_SINGLE) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM5_Init 2 */

  /* USER CODE END TIM5_Init 2 */

}

/**
  * @brief TIM10 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM10_Init(void)
{

  /* USER CODE BEGIN TIM10_Init 0 */

  /* USER CODE END TIM10_Init 0 */

  /* USER CODE BEGIN TIM10_Init 1 */

  /* USER CODE END TIM10_Init 1 */
  htim10.Instance = TIM10;
  htim10.Init.Prescaler = 0;
  htim10.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim10.Init.Period = 0;
  htim10.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim10.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim10) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM10_Init 2 */

  /* USER CODE END TIM10_Init 2 */

}

/**
  * @brief TIM11 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM11_Init(void)
{

  /* USER CODE BEGIN TIM11_Init 0 */

  /* USER CODE END TIM11_Init 0 */

  /* USER CODE BEGIN TIM11_Init 1 */

  /* USER CODE END TIM11_Init 1 */
  htim11.Instance = TIM11;
  htim11.Init.Prescaler = 0;
  htim11.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim11.Init.Period = 0;
  htim11.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim11.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim11) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM11_Init 2 */

  /* USER CODE END TIM11_Init 2 */

}

/**
  * @brief TIM13 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM13_Init(void)
{

  /* USER CODE BEGIN TIM13_Init 0 */

  /* USER CODE END TIM13_Init 0 */

  /* USER CODE BEGIN TIM13_Init 1 */

  /* USER CODE END TIM13_Init 1 */
  htim13.Instance = TIM13;
  htim13.Init.Prescaler = 0;
  htim13.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim13.Init.Period = 0;
  htim13.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim13.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim13) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM13_Init 2 */

  /* USER CODE END TIM13_Init 2 */

}

/**
  * @brief TIM14 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM14_Init(void)
{

  /* USER CODE BEGIN TIM14_Init 0 */

  /* USER CODE END TIM14_Init 0 */

  /* USER CODE BEGIN TIM14_Init 1 */

  /* USER CODE END TIM14_Init 1 */
  htim14.Instance = TIM14;
  htim14.Init.Prescaler = 0;
  htim14.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim14.Init.Period = 0;
  htim14.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim14.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim14) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM14_Init 2 */

  /* USER CODE END TIM14_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 19200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief USART3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */

  /* USER CODE END USART3_Init 2 */

}

/**
  * @brief USART6 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART6_UART_Init(void)
{

  /* USER CODE BEGIN USART6_Init 0 */

  /* USER CODE END USART6_Init 0 */

  /* USER CODE BEGIN USART6_Init 1 */

  /* USER CODE END USART6_Init 1 */
  huart6.Instance = USART6;
  huart6.Init.BaudRate = 19200;
  huart6.Init.WordLength = UART_WORDLENGTH_8B;
  huart6.Init.StopBits = UART_STOPBITS_1;
  huart6.Init.Parity = UART_PARITY_NONE;
  huart6.Init.Mode = UART_MODE_TX_RX;
  huart6.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart6.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart6) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART6_Init 2 */

  /* USER CODE END USART6_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13|GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2 
                          |GPIO_PIN_3, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3 
                          |GPIO_PIN_7|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10 
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12 
                          |GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15|GPIO_PIN_0 
                          |GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4 
                          |GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pins : PC13 PC0 PC1 PC2 
                           PC3 */
  GPIO_InitStruct.Pin = GPIO_PIN_13|GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2 
                          |GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PA0 PA1 PA2 PA3 
                           PA7 PA15 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3 
                          |GPIO_PIN_7|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PA5 PA6 */
  GPIO_InitStruct.Pin = GPIO_PIN_5|GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PE7 PE8 PE9 PE10 
                           PE11 PE12 PE15 */
  GPIO_InitStruct.Pin = GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10 
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : PE13 PE14 */
  GPIO_InitStruct.Pin = GPIO_PIN_13|GPIO_PIN_14;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : PB11 PB12 PB13 */
  GPIO_InitStruct.Pin = GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PD8 PD10 PD11 PD12 
                           PD13 PD14 PD15 PD0 
                           PD1 PD2 PD3 PD4 
                           PD7 */
  GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12 
                          |GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15|GPIO_PIN_0 
                          |GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4 
                          |GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : PC10 PC11 PC12 */
  GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PB5 PB8 PB9 */
  GPIO_InitStruct.Pin = GPIO_PIN_5|GPIO_PIN_8|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void setPWM(TIM_HandleTypeDef timer, uint32_t channel, uint16_t period,uint16_t pulse)
{
 HAL_TIM_PWM_Stop(&timer, channel); // stop generation of pwm
 TIM_OC_InitTypeDef sConfigOC;
// timer.Init.Period = period; // set the period duration
// HAL_TIM_PWM_Init(&timer); // re-inititialise with new period value
 sConfigOC.OCMode = TIM_OCMODE_PWM1;
 sConfigOC.Pulse = pulse; // set the pulse duration
 sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
 sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
 HAL_TIM_PWM_ConfigChannel(&timer, &sConfigOC, channel);
 HAL_TIM_PWM_Start(&timer, channel); // start pwm generation
}


void TimingDelay_Decrement(void)
{
  if (TimingDelay != 0x00)
  {
    TimingDelay--;
  }
}
void TimingDelay_Decrement1(void)
{
  if (TimingDelay1 != 0x00)
  {
    TimingDelay1--;
  }
}
void TimingDelay_Decrement2(void)
{
  if (TimingDelay2 != 0x00)
  {
    TimingDelay2--;
  }
}
void TimingDelay_Decrement3(void)
{
  if (TimingDelay3 != 0x00)
  {
    TimingDelay3--;
  }
}
void TimingDelay_Decrement4(void)
{
  if (TimingDelay4 != 0x00)
  {
    TimingDelay4--;
  }
}
void TimingDelay_Decrement5(void)
{
  if (TimingDelay5 != 0x00)
  {
    TimingDelay5--;
  }
}

void setPWMPin(uint8_t  pinValue,uint8_t  pinValue1,uint8_t pulse)
{
/*---------------set PWM pin-----------------------------*/
	if(!(RecMsg4[8]==pulse1)){

		pulse1=RecMsg4[8];

		if(pulse1==1){
		 setPWM(htim3, TIM_CHANNEL_1, 255, 400);    //PB4
		}
		if(pulse1==2){
		 setPWM(htim3, TIM_CHANNEL_1, 255, 600);    //PB4
		}
		if(pulse1==3){
		 setPWM(htim3, TIM_CHANNEL_1, 255, 1000);    //PB4
		}

	}

//	/*--------------LORA uart6--------*/
//	if(!(RecMsg2[8]==pulse1)){
//		 setPWM(htim3, TIM_CHANNEL_1, 255, 500);    //PB4
//			pulse1=RecMsg4[8];
//	}
//		 setPWM(htim2, TIM_CHANNEL_2, 255, 200);    //PB3

	 offAll();

	 /*---------------------------for primary and secondary--------------------------*/
	 /*--------------green1 and green2-----------------*/
	 		 if(( pinValue & 0x33 )== 0x33)
	 		 {
	 		 //			 setPWM(htim14, TIM_CHANNEL_1, 255, pulse);    //PA7
	 		 			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_SET);//G2
	 		 			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET);//G2
	 		 			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, GPIO_PIN_SET);//G1
	 		 			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_SET);//G1

	 		 		}
	 /*------------------------amber--------------------*/
	 		 if(( pinValue & 0x44 )== 0x44)
	 			 {
	 			 //			 setPWM(htim14, TIM_CHANNEL_1, 255, pulse);    //PA7
	 			 			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);//A
	 			 			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, GPIO_PIN_SET);//A

	 			 		}
	 /*------------------------red--------------------*/
	 		 if(( pinValue & 0x88 )== 0x88)
	 		 	{
	 		 	 //			 setPWM(htim14, TIM_CHANNEL_1, 255, pulse);    //PA7
	 		 			 	 HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, GPIO_PIN_SET);//R
	 		 			 	 HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10, GPIO_PIN_SET);//R

	 		 	}


	 		 /*---------------------------for primary and secondary--------------------------*/
	 		 /*--------------green1 and green2-----------------*/
	 		 		 if(( pinValue1 & 0x33 )== 0x33)
	 		 		 {
	 		 		 //			 setPWM(htim14, TIM_CHANNEL_1, 255, pulse);    //PA7
	 		 		 			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_SET);//G2
	 		 		 			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);//G1
	 		 		 			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);//G2
	 		 		 			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_15, GPIO_PIN_SET);//G1

	 		 		 		}
	 		 /*------------------------amber--------------------*/
	 		 		 if(( pinValue1 & 0x44 )== 0x44)
	 		 			 {
	 		 			 //			 setPWM(htim14, TIM_CHANNEL_1, 255, pulse);    //PA7
	 		 			 			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);//A
	 		 			 			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);//A

	 		 			 		}
	 		 /*------------------------red--------------------*/
	 		 		 if(( pinValue1 & 0x88 )== 0x88)
	 		 		 	{
	 		 		 	 //			 setPWM(htim14, TIM_CHANNEL_1, 255, pulse);    //PA7
	 		 		 			 	 HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);//R
	 		 		 			 	 HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_SET);//R

	 		 		 	}






///*----------------GPIO------------------------*/
//
//	if(( pinValue & 0x03 )== 0x03){
////			 setPWM(htim14, TIM_CHANNEL_1, 255, pulse);    //PA7
//			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_SET);
//			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, GPIO_PIN_SET);
//
//		}
////		else
////		{
//////			 setPWM(htim14, TIM_CHANNEL_1, 255,0);    //PA7
////			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_RESET);
////			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, GPIO_PIN_RESET);
////			}
//
//
//
//	if(( pinValue & 0x01 )== 0x01){
////			 setPWM(htim14, TIM_CHANNEL_1, 255, pulse);    //PA7
//			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_SET);
//
//		}
////		else
////		{
//////			 setPWM(htim14, TIM_CHANNEL_1, 255,0);    //PA7
////			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_RESET);
////			}
//
//		if(( pinValue & 0x02 )== 0x02){
////			  setPWM(htim13, TIM_CHANNEL_1, 25, pulse);    //PA6
//			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, GPIO_PIN_SET);
//
//		}
////		else
////		{
//////			  setPWM(htim13, TIM_CHANNEL_1, 255, 0);    //PA6
////			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, GPIO_PIN_RESET);
////			}
//
//		if(( pinValue & 0x04 )== 0x04){
////			  setPWM(htim12, TIM_CHANNEL_1, 255, pulse);    //PB14
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
//
//		}
////		else
////		{
//////			  setPWM(htim12, TIM_CHANNEL_1, 255, 0);    //PB14
////			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
////			}
//
//		if(( pinValue & 0x08 )== 0x08){
////			  setPWM(htim12, TIM_CHANNEL_2, 255, pulse);   //PB15
//			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, GPIO_PIN_SET);
//
//		}
////		else
////		{
//////			  setPWM(htim12, TIM_CHANNEL_2, 255, 0);   //PB15
////			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, GPIO_PIN_RESET);
////			}
//
//		if(( pinValue & 0x10 )== 0x10){
////			  setPWM(htim11, TIM_CHANNEL_1, 255, pulse);   //PB9
//			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET);
//
//		}
////		else
////		{
//////			  setPWM(htim11, TIM_CHANNEL_1, 255, 0);   //PB9
////			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_RESET);
////			}
//
//		if(( pinValue & 0x20 )== 0x20){
////			  setPWM(htim10, TIM_CHANNEL_1, 255, pulse);  //PB8
//			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_SET);
//
//		}
////		else
////		{
//////			  setPWM(htim10, TIM_CHANNEL_1, 255, 0);  //PB8
////			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_RESET);
////			}
//		if(( pinValue & 0x40 )== 0x40){
////			  setPWM(htim9, TIM_CHANNEL_1, 255, pulse);   //PE5
//			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, GPIO_PIN_SET);
//
//		}
////		else
////		{
//////			  setPWM(htim9, TIM_CHANNEL_1, 255, 0);   //PE5
////			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, GPIO_PIN_RESET);
////			}
//
//		if(( pinValue & 0x80 )== 0x80){
////			  setPWM(htim9, TIM_CHANNEL_2, 255, pulse);   //PE6
//			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10, GPIO_PIN_SET);
//
//		}
////		else
////		{
//////			  setPWM(htim9, TIM_CHANNEL_2, 255, 0);   //PE6
////			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10, GPIO_PIN_RESET);
////			}
//		//-----------------------------------
//
//		if(( pinValue1 & 0x03 )== 0x03){
//	//	        setPWM(htim8, TIM_CHANNEL_4, 255, pulse);    //PC9
//				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_SET);
//				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
//
//			}
////			else
////			{
////	//	        setPWM(htim8, TIM_CHANNEL_4, 255, 0);    //PC9
////				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_RESET);
////				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
////				}
//
//
//
//
//		if(( pinValue1 & 0x01 )== 0x01){
////	        setPWM(htim8, TIM_CHANNEL_4, 255, pulse);    //PC9
//			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_SET);
//
//		}
////		else
////		{
//////	        setPWM(htim8, TIM_CHANNEL_4, 255, 0);    //PC9
////			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_RESET);
////			}
//		if(( pinValue1 & 0x02 )== 0x02){
////			  setPWM(htim4, TIM_CHANNEL_4, 255, pulse);    //PD15
//			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
//
//		}
////		else
////		{
//////			  setPWM(htim4, TIM_CHANNEL_4, 255, 0);    //PD15
////			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
////			}
//		if(( pinValue1 & 0x04 )== 0x04){
////			  setPWM(htim4, TIM_CHANNEL_2, 255, pulse);    //PD13
//			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
//
//		}
////		else
////		{
//////			  setPWM(htim4, TIM_CHANNEL_2, 255, 0);    //PD13
////			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
////			}
//		if(( pinValue1 & 0x08 )== 0x08){
////			  setPWM(htim4, TIM_CHANNEL_1, 255, pulse);   //PD12
//			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
//
//		}
////		else
////		{
//////			  setPWM(htim4, TIM_CHANNEL_1, 255, 0);   //PD12
////			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
////			}
//		if(( pinValue1 & 0x10 )== 0x10){
////			  setPWM(htim1, TIM_CHANNEL_4, 255, pulse);   //PA11
//			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
//
//		}
////		else
////		{
//////			  setPWM(htim1, TIM_CHANNEL_4, 255, 0);   //PA11
////			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
////			}
//		if(( pinValue1 & 0x20 )== 0x20){
////			  setPWM(htim2, TIM_CHANNEL_3, 255, pulse);  //PB10
//			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_15, GPIO_PIN_SET);
//
//		}
////		else
////		{
//////			  setPWM(htim2, TIM_CHANNEL_3, 255, 0);  //PB10
////			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_15, GPIO_PIN_RESET);
////			}
//		if(( pinValue1 & 0x40 )== 0x40){
////			  setPWM(htim2, TIM_CHANNEL_4, 255, pulse);   //PB11
//			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);
//
//		}
////		else
////		{
//////			  setPWM(htim2, TIM_CHANNEL_4, 255, 0);   //PB11
////			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);
////			}
//		if(( pinValue1 & 0x80 )== 0x80){
////			  setPWM(htim4, TIM_CHANNEL_3, 255, pulse);   //PD14
//			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_SET);
//
//		}
////		else
////		{
//////			  setPWM(htim4, TIM_CHANNEL_3, 255, 0);   //PD14
////			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_RESET);
////			}
//




}



void SetAdcChannel(unsigned long AdcChannel)
{
	ADC_ChannelConfTypeDef sConfig = {0};

	sConfig.Channel = AdcChannel;
	sConfig.Rank = 1;
	sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
	HAL_ADC_ConfigChannel(&hadc2, &sConfig);
}


/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
