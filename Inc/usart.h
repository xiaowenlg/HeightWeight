/**
  ******************************************************************************
  * File Name          : USART.h
  * Description        : This file provides code for the configuration
  *                      of the USART instances.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __usart_H
#define __usart_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */
#include "FreeRTOS.h"
#include <stdio.h>
#include "queue.h"
#include "semphr.h"
/* USER CODE END Includes */

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;

/* USER CODE BEGIN Private defines */
#define SETUARTMAXLEN(n)            256*n                //串口接收最大数据长度
/* USER CODE END Private defines */

void MX_USART1_UART_Init(void);
void MX_USART2_UART_Init(void);
void MX_USART3_UART_Init(void);

/* USER CODE BEGIN Prototypes */
typedef struct UartInfo
{
	_Bool   reover;             //接收完毕标志
	uint8_t datalen;            //鎺ユ敹鍒扮殑鏁版嵁闀垮害
	uint8_t dataIndex;          //鎺ユ敹鏁扮粍鐨勭储寮?
	uint8_t redata[SETUARTMAXLEN(1)];        //鎺ユ敹缂撳啿鍖?鏁扮粍)
}ReceMessage;
HAL_StatusTypeDef MY_USART_SendData(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef MY_USART_SendByte(UART_HandleTypeDef *huart, uint8_t byt);
HAL_StatusTypeDef MY_USART_chars(UART_HandleTypeDef *huart, uint8_t *pData);
void sendstring(unsigned char *string, UART_HandleTypeDef *huart);
void Uart_printf(UART_HandleTypeDef *huart, const char *fmt, ...);
void Uartx_printf(UART_HandleTypeDef * huart, char * fmt, ...);
void MX_USART_UART_Init(UART_HandleTypeDef *huart, USART_TypeDef *uart, uint32_t baud);
extern ReceMessage uart1_rec;
extern ReceMessage uart2_rec;
extern ReceMessage uart3_rec;
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ usart_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
