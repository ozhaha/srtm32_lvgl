//
// Created by ozcom on 2022/4/10.
//

#include "debug.h"
#include "log.h"
#include <memory.h>

uint8_t g_DEBUG_RX_BUFF[DEBUG_RX_BUFF_SIZE] = {0};

extern DMA_HandleTypeDef hdma_usart1_rx;
extern DMA_HandleTypeDef hdma_usart1_tx;

void DEBUG_Start_Receiver() {

#if DEBUG_RX_FUN == DEBUG_RX_FUN_IT
    HAL_UART_Receive_IT(&huart1, g_DEBUG_RX_BUFF, DEBUG_RX_BUFF_SIZE);
#elif  DEBUG_RX_FUN == DEBUG_RX_FUN_DMA
    HAL_UART_Receive_DMA(&huart1, g_DEBUG_RX_BUFF, DEBUG_RX_BUFF_SIZE);
#endif

}


void DEBUG_XferCpltCallback(DMA_HandleTypeDef *hdma) {

    if (hdma == &hdma_usart1_rx) {
        DEBUG_Start_Receiver();
    } else if (hdma == &hdma_usart1_tx) {

    }

}

void DEBUG_XferErrorCallback(DMA_HandleTypeDef *hdma) {

    if (hdma == &hdma_usart1_rx) {

    } else if (hdma == &hdma_usart1_tx) {

    }

}


void DEBUG_RxCpltCallback(UART_HandleTypeDef *UartHandle) {

//    LOGD("--->huart1.RxXferCount: %d", huart1.RxXferCount);
//    LOGD("--->huart1.Instance->SR: %lX", huart1.Instance->SR);
//    LOGD("--->huart1.Instance->GTPR: %lX", huart1.Instance->GTPR);
//    LOGD("--->huart1.Instance->DR: %s", (char *) &huart1.Instance->DR);
//    LOGD("--->huart1.Instance->CR3: %lX", huart1.Instance->CR3);
//    LOGD("--->huart1.Instance->CR2: %lX", huart1.Instance->CR2);
//    LOGD("--->huart1.Instance->CR1: %lX", huart1.Instance->CR1);
//    LOGD("--->huart1.Instance->BRR: %lX", huart1.Instance->BRR);
//    LOGD("--->huart1.gState: %u", huart1.gState);
//    LOGD("--->huart1.RxState: %u", huart1.RxState);
//    LOGD("--->huart1.pTxBuffPtr: %s", huart1.pTxBuffPtr);
//    LOGD("--->huart1.pRxBuffPtr: %s", huart1.pRxBuffPtr);
    LOGD("--->g_DEBUG_RX_BUFF: %s", g_DEBUG_RX_BUFF);
    memset(g_DEBUG_RX_BUFF, 0, DEBUG_RX_BUFF_SIZE);

    DEBUG_Start_Receiver();

}


void DEBUG_ErrorCallback(UART_HandleTypeDef *UartHandle) {

    if (UartHandle->ErrorCode == HAL_UART_ERROR_ORE)
        LOGE("--->Error Code:%lu , Overrun error!!!", UartHandle->ErrorCode);
    else if (UartHandle->ErrorCode == HAL_UART_ERROR_FE)
        LOGE("--->Error Code:%lu , Frame error!!!", UartHandle->ErrorCode);
    else if (UartHandle->ErrorCode == HAL_UART_ERROR_NE)
        LOGE("--->Error Code:%lu , Noise error!!!", UartHandle->ErrorCode);
    else if (UartHandle->ErrorCode == HAL_UART_ERROR_DMA)
        LOGE("--->Error Code:%lu , Noise error!!!", UartHandle->ErrorCode);
    else if (UartHandle->ErrorCode == HAL_UART_ERROR_PE)
        LOGE("--->Error Code:%lu , Parity error!!!", UartHandle->ErrorCode);
    else if (UartHandle->ErrorCode == HAL_UART_ERROR_NONE)
        LOGE("--->Error Code:%lu , No error!!!", UartHandle->ErrorCode);

    DEBUG_Start_Receiver();

}


void DEBUG_TxCpltCallback(UART_HandleTypeDef *UartHandle) {

    LOGD("--->UartHandle->pTxBuffPtr: %s", UartHandle->pTxBuffPtr);
    LOGD("--->UartHandle->TxXferSize: %hu", UartHandle->TxXferSize);
    LOGD("--->UartHandle->TxXferCount:  %hu", UartHandle->TxXferCount);

}


void DEBUG_UARTEx_RxEventCallback(UART_HandleTypeDef *UartHandle, uint16_t Size) {

    LOGD("--->UartHandle->Size: %d", Size);

}
