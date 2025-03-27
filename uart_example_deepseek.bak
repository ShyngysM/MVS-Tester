
void uart_transmit_msg(char *msg, UART_HandleTypeDef *huart) {
    if (msg == NULL || huart == NULL) {
        return;
    }

    // Adjust buffer size based on your needs and expected message length
    const uint16_t max_len = 256;
    char uart_buf[max_len];

    // Clear the buffer explicitly
    memset(uart_buf, 0, sizeof(uart_buf));

    // Format the message into the buffer and check for errors
    int uart_buf_len = snprintf(uart_buf, max_len, "%s\r\n", msg);
    if (uart_buf_len < 0 || uart_buf_len >= max_len) {
        // Handle error or truncate message
        return;
    }

    // Transmit the formatted message with a timeout for safety
    HAL_StatusTypeDef status = HAL_UART_Transmit(huart, (uint8_t *)uart_buf, uart_buf_len, 100);
    if (status != HAL_OK) {
        // Handle transmission error
    }
}


#include <string.h> // For memset and snprintf
#include "stm32f4xx_hal.h" // Assuming this is for STM32, adjust accordingly

void uart_transmit_msg(char *msg, UART_HandleTypeDef *huart) {
    if (msg == NULL || huart == NULL) {
        return;
    }

    const uint16_t max_len = 256; // Adjust buffer size based on your needs
    char uart_buf[max_len];

    memset(uart_buf, 0, sizeof(uart_buf));

    int uart_buf_len = snprintf(uart_buf, max_len, "%s\r\n", msg);
    if (uart_buf_len < 0 || uart_buf_len >= max_len) {
        // Handle truncation error by truncating the message or logging it
        uart_buf_len = sizeof(uart_buf) - 1; // Truncate to fit in buffer
        memcpy(uart_buf, msg, uart_buf_len); // Copy truncated message to buffer
    }

    HAL_StatusTypeDef status = HAL_UART_Transmit(huart, (uint8_t *)uart_buf, uart_buf_len, 100);
    if (status != HAL_OK) {
        // Handle transmission error by logging it or taking appropriate recovery actions
        // You might also want to re-initialize the UART peripheral or notify a higher-level system
    }
}
