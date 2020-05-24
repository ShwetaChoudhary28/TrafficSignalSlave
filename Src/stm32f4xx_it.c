/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f4xx_it.c
  * @brief   Interrupt Service Routines.
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
#include "stm32f4xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
 
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;
extern UART_HandleTypeDef huart6;
/* USER CODE BEGIN EV */
//----------for usart3------//
uint8_t RecMsg3[250];
extern int msgUnPrcd3;
extern  uint32_t TimingDelay3;
 uint32_t flag3=0;  // This is to indicate whether a messege is in process at uart or not . 0 indicates no and 1 indicates yes
 uint16_t RxCount3 = 0;
extern uint8_t aRxBuffer3[225];


//------for usart 1------------//
uint8_t RecMsg1[250];
extern int msgUnPrcd1;
extern   uint32_t TimingDelay1;
 uint32_t flag1=0;  // This is to indicate whether a messege is in process at uart or not . 0 indicates no and 1 indicates yes
 uint16_t RxCount1 = 0;
extern uint8_t aRxBuffer1[225];

//-----for usart2----------//
uint8_t RecMsg2[250];
extern int msgUnPrcd;
extern   uint32_t TimingDelay;
 uint32_t flag2=0;  // This is to indicate whether a messege is in process at uart or not . 0 indicates no and 1 indicates yes
 uint16_t RxCount2 = 0;
extern uint8_t aRxBuffer[225];

//----------for usart4------//
uint8_t RecMsg4[250];
extern int msgUnPrcd4;
extern  __IO uint32_t TimingDelay4;
__IO uint32_t flag4=0;  // This is to indicate whether a messege is in process at uart or not . 0 indicates no and 1 indicates yes
__IO uint16_t RxCount4 = 0;
extern uint8_t aRxBuffer4[225];

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */ 
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */

  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Pre-fetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */
	          TimingDelay_Decrement();
			  TimingDelay_Decrement1();
			  TimingDelay_Decrement3();
			  TimingDelay_Decrement4();
			  TimingDelay_Decrement5();
  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */
  /*for */
       	if (TimingDelay<2) //if timming delay is less than 2
       		{
       		if (flag2==1)  //flag is 1 (flag tells that has msg came)
       			{
       //	__HAL_UART_DISABLE_IT(&huart1, UART_IT_RXNE);
       //	 __HAL_UART_ENABLE_IT(&huart1, UART_IT_RXNE);
       //	 	HAL_UART_Receive_IT(&huart1, (uint8_t *)aRxBuffer1,1);

             flag2= 0 ;
       		  msgUnPrcd = 1 ;     //Raise flag to indicate a msg to be processed by main is present
       		  RxCount2 = 0 ;

       			/* Disable the EVAL_COM1 Receive interrupt */
       //      USART_ITConfig(USART1, USART_IT_RXNE, DISABLE);

       }
       }
        /*for uart1*/
         	if (TimingDelay1<2) //if timming delay is less than 2
         		{
         		if (flag1==1)  //flag is 1 (flag tells that has msg came)
         			{
         //	__HAL_UART_DISABLE_IT(&huart1, UART_IT_RXNE);
         //	 __HAL_UART_ENABLE_IT(&huart1, UART_IT_RXNE);
         //	 	HAL_UART_Receive_IT(&huart1, (uint8_t *)aRxBuffer1,1);

               flag1= 0 ;
         		  msgUnPrcd1 = 1 ;     //Raise flag to indicate a msg to be processed by main is present
         		  RxCount1 = 0 ;

         			/* Disable the EVAL_COM1 Receive interrupt */
         //      USART_ITConfig(USART1, USART_IT_RXNE, DISABLE);

         }
         }
            /*for uart3*/
              	if (TimingDelay3<2) //if timming delay is less than 2
              		{
              		if (flag3==1)  //flag is 1 (flag tells that has msg came)
              			{
              //	__HAL_UART_DISABLE_IT(&huart1, UART_IT_RXNE);
              //	 __HAL_UART_ENABLE_IT(&huart1, UART_IT_RXNE);
              //	 	HAL_UART_Receive_IT(&huart1, (uint8_t *)aRxBuffer1,1);

                    flag3= 0 ;
              		  msgUnPrcd3 = 1 ;     //Raise flag to indicate a msg to be processed by main is present
              		  RxCount3 = 0 ;

              			/* Disable the EVAL_COM1 Receive interrupt */
              //      USART_ITConfig(USART1, USART_IT_RXNE, DISABLE);

              }
              }
                /*for uart2*/
                  	if (TimingDelay4<2) //if timming delay is less than 2
                  		{
                  		if (flag4==1)  //flag is 1 (flag tells that has msg came)
                  			{
                  //	__HAL_UART_DISABLE_IT(&huart1, UART_IT_RXNE);
                  //	 __HAL_UART_ENABLE_IT(&huart1, UART_IT_RXNE);
                  //	 	HAL_UART_Receive_IT(&huart1, (uint8_t *)aRxBuffer1,1);

                        flag4= 0 ;
                  		  msgUnPrcd4 = 1 ;     //Raise flag to indicate a msg to be processed by main is present
                  		  RxCount4 = 0 ;

                  			/* Disable the EVAL_COM1 Receive interrupt */
                  //      USART_ITConfig(USART1, USART_IT_RXNE, DISABLE);

                  }
                  }

//                    /*for uart5*/
//                              	if (TimingDelay5<2) //if timming delay is less than 2
//                              		{
//                              		if (flag5==1)  //flag is 1 (flag tells that has msg came)
//                              			{
//                              //	__HAL_UART_DISABLE_IT(&huart1, UART_IT_RXNE);
//                              //	 __HAL_UART_ENABLE_IT(&huart1, UART_IT_RXNE);
//                              //	 	HAL_UART_Receive_IT(&huart1, (uint8_t *)aRxBuffer1,1);
//
//                                    flag5= 0 ;
//                              		  msgUnPrcd5 = 1 ;     //Raise flag to indicate a msg to be processed by main is present
//                              		  RxCount5 = 0 ;
//
//                              			/* Disable the EVAL_COM1 Receive interrupt */
//                              //      USART_ITConfig(USART1, USART_IT_RXNE, DISABLE);
//
//                              }
//                              }
  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f4xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles USART1 global interrupt.
  */
void USART1_IRQHandler(void)
{
  /* USER CODE BEGIN USART1_IRQn 0 */
	TimingDelay1 = 10; //initilizing timingDelay with 10 & decremening this delay.
  	if(flag1==0)     //if flag was previous 0,it means that 1byte is being rec(fresh msg) if not goes to else part
  {
  RxCount1 = 0 ; //initilizing the count of recieved array with 0,means that it is the first byte(0 is used bcoz indexing in array is done from 0th index)
  flag1=1;   		//UART is active in process of receiving a messege
//	msgTime = 0 ;
  }
	else // if it is not a fresh msg than incrementing RxCount2(RxCount2 shows the number of bytes being rec)
		RxCount1++;

	if (RxCount1>50)
	{
		flag1=0 ;
		RxCount1 = 0 ;
//		comCount=2;
//				comCount=3;
//		comCount=1;
//		comCount=2;

  }
  /* USER CODE END USART1_IRQn 0 */
  HAL_UART_IRQHandler(&huart1);
  /* USER CODE BEGIN USART1_IRQn 1 */
  RecMsg1[RxCount1]=aRxBuffer1[0]; //after every byte is rec it is transferred to RecMsg2 array(here RxCount2 counter is used for placing the rec byte at correct index place)

  /* USER CODE END USART1_IRQn 1 */
}

/**
  * @brief This function handles USART2 global interrupt.
  */
void USART2_IRQHandler(void)
{
  /* USER CODE BEGIN USART2_IRQn 0 */
	TimingDelay4 = 10; //initilizing timingDelay with 10 & decremening this delay.
				  	if(flag4==0)     //if flag was previous 0,it means that 1byte is being rec(fresh msg) if not goes to else part
				  {
				  RxCount4 = 0 ; //initilizing the count of recieved array with 0,means that it is the first byte(0 is used bcoz indexing in array is done from 0th index)
				  flag4=1;   		//UART is active in process of receiving a messege
				//	msgTime = 0 ;
				  }
					else // if it is not a fresh msg than incrementing RxCount2(RxCount2 shows the number of bytes being rec)
						RxCount4++;

					if (RxCount4>150)
					{
						flag4=0 ;
						RxCount4 = 0 ;
				//		comCount=2;
				//				comCount=3;
				//		comCount=1;
				//		comCount=2;

				  }
  /* USER CODE END USART2_IRQn 0 */
  HAL_UART_IRQHandler(&huart2);
  /* USER CODE BEGIN USART2_IRQn 1 */
  RecMsg4[RxCount4]=aRxBuffer4[0]; //after every byte is rec it is transferred to RecMsg2 array(here RxCount2 counter is used for placing the rec byte at correct index place)

  /* USER CODE END USART2_IRQn 1 */
}

/**
  * @brief This function handles USART3 global interrupt.
  */
void USART3_IRQHandler(void)
{
  /* USER CODE BEGIN USART3_IRQn 0 */
	TimingDelay3 = 10; //initilizing timingDelay with 10 & decremening this delay.
			  	if(flag3==0)     //if flag was previous 0,it means that 1byte is being rec(fresh msg) if not goes to else part
			  {
			  RxCount3 = 0 ; //initilizing the count of recieved array with 0,means that it is the first byte(0 is used bcoz indexing in array is done from 0th index)
			  flag3=1;   		//UART is active in process of receiving a messege
			//	msgTime = 0 ;
			  }
				else // if it is not a fresh msg than incrementing RxCount2(RxCount2 shows the number of bytes being rec)
					RxCount3++;

				if (RxCount3>50)
				{
					flag3=0 ;
					RxCount3 = 0 ;
			//		comCount=2;
			//				comCount=3;
			//		comCount=1;
			//		comCount=2;

			  }
  /* USER CODE END USART3_IRQn 0 */
  HAL_UART_IRQHandler(&huart3);
  /* USER CODE BEGIN USART3_IRQn 1 */
  RecMsg3[RxCount3]=aRxBuffer3[0]; //after every byte is rec it is transferred to RecMsg2 array(here RxCount2 counter is used for placing the rec byte at correct index place)

  /* USER CODE END USART3_IRQn 1 */
}

/**
  * @brief This function handles USART6 global interrupt.
  */
void USART6_IRQHandler(void)
{
  /* USER CODE BEGIN USART6_IRQn 0 */
	TimingDelay = 10; //initilizing timingDelay with 10 & decremening this delay.
					  	if(flag2==0)     //if flag was previous 0,it means that 1byte is being rec(fresh msg) if not goes to else part
					  {
					  RxCount2 = 0 ; //initilizing the count of recieved array with 0,means that it is the first byte(0 is used bcoz indexing in array is done from 0th index)
					  flag2=1;   		//UART is active in process of receiving a messege
					//	msgTime = 0 ;
					  }
						else // if it is not a fresh msg than incrementing RxCount2(RxCount2 shows the number of bytes being rec)
							RxCount2++;

						if (RxCount2>50)
						{
							flag2=0 ;
							RxCount2 = 0 ;
					//		comCount=2;
					//				comCount=3;
					//		comCount=1;
					//		comCount=2;

					  }
  /* USER CODE END USART6_IRQn 0 */
  HAL_UART_IRQHandler(&huart6);
  /* USER CODE BEGIN USART6_IRQn 1 */
  RecMsg2[RxCount2]=aRxBuffer[0]; //after every byte is rec it is transferred to RecMsg2 array(here RxCount2 counter is used for placing the rec byte at correct index place)

  /* USER CODE END USART6_IRQn 1 */
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
