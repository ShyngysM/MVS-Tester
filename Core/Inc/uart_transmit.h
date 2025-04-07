#ifndef INC_UART_TRANSMIT_H_
#define INC_UART_TRANSMIT_H_
#include "main.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

// TODO: add test for the size of buffer
void uart_transmit_msg(char *msg, UART_HandleTypeDef *huart);
void uart_transmit_array(uint16_t *arr, size_t length,
                         UART_HandleTypeDef *huart);
void uart_transmit_table(int *count, int *pulses, int *htime, int *t_vibration,
                         int *t_responce, bool *open_before_vibr,
                         bool *open_after_vibr, bool *bad,
                         UART_HandleTypeDef *huart);

#endif // !INC_UART_TRANSMIT_H
