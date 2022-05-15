//
// Created by ozcom on 2022/4/6.
//

#include "usart.h"

extern UART_HandleTypeDef huart1;

int __io_putchar(int ch) {

    while (HAL_UART_Transmit(&huart1, (uint8_t *) &ch, 1, 0xFFFF) != HAL_OK);

    return ch;
}

int __io_getchar(void) {

    int ch;
    while (HAL_UART_Receive(&huart1, (uint8_t *) &ch, 1, 0xFFFF) != HAL_OK);

    return ch;
}