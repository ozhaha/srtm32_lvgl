//
// Created by ozcom on 2022/4/10.
//

#ifndef STM32F407VE_DEMO3_DEBUG_H
#define STM32F407VE_DEMO3_DEBUG_H

#include "usart.h"

#define DEBUG_RX_BUFF_SIZE 10
#define DEBUG_RX_FUN_POLLING 0
#define DEBUG_RX_FUN_IT 1
#define DEBUG_RX_FUN_DMA 2
#define DEBUG_RX_FUN DEBUG_RX_FUN_IT

extern uint8_t g_DEBUG_RX_BUFF[DEBUG_RX_BUFF_SIZE];

void DEBUG_RxCpltCallback(UART_HandleTypeDef *UartHandle);

void DEBUG_ErrorCallback(UART_HandleTypeDef *UartHandle);

void DEBUG_TxCpltCallback(UART_HandleTypeDef *UartHandle);

void DEBUG_UARTEx_RxEventCallback(UART_HandleTypeDef *UartHandle, uint16_t Size);

void DEBUG_Start_Receiver();

void DEBUG_XferCpltCallback(DMA_HandleTypeDef *hdma);

void DEBUG_XferErrorCallback(DMA_HandleTypeDef *hdma);

#endif //STM32F407VE_DEMO3_DEBUG_H
