#ifndef INC_UART_TRANSMIT_H_
#define INC_UART_TRANSMIT_H_
#include "main.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

// void uart_transmit_msg(char *msg, char uart_buf[], UART_HandleTypeDef *huart);
// TODO: add test for the size of buffer
void uart_transmit_msg(char *msg, UART_HandleTypeDef *huart);
void uart_transmit_array(uint16_t *arr, size_t length, UART_HandleTypeDef *huart);


#endif // !INC_UART_TRANSMIT_H
