#include "../Inc/uart_transmit.h"

// void uart_transmit_msg(char *msg, char uart_buf[], UART_HandleTypeDef
// *huart){
//   int uart_buf_len = 0;
//   uart_buf_len = sprintf(uart_buf, msg);
//   HAL_UART_Transmit(huart, (uint8_t *)uart_buf, uart_buf_len, 100); // 100 is
//   a timeout in ms or s?
// }

// void send_uart(char * buffer)
// {
//    char msg[2+tx_buffer_size+2+1] = "";	// 'CR' 'LF' "data" 'CR' 'LF'
//    '\0'
//    // The "-1" here guarantees that there is room for snprintf() to append
//    // the trailing NULL
//    snprintf(msg, sizeof(msg)-1, "\r\n%s\r\n", buffer);
//    HAL_UART_Transmit(&huart3, (uint8_t *)msg, strlen(msg)); // No need to
//    transmit the null terminator
// }

void uart_transmit_msg(char *msg, UART_HandleTypeDef *huart) {
  if (msg == NULL || huart == NULL) {
    return;
  }

  // Static buffer to avoid dynamic memory allocation
  char uart_buf[256]; // Adjust size if needed
                      // Clear the buffer explicitly
  memset(uart_buf, 0, sizeof(uart_buf));

  // Format the message into the buffer
  int uart_buf_len = snprintf(uart_buf, sizeof(uart_buf), "%s\r\n", msg);
  if (uart_buf_len < 0 || uart_buf_len >= sizeof(uart_buf)) {
    return; // Handle error or truncate message
  }

  // Transmit the formatted message
  HAL_UART_Transmit(huart, (uint8_t *)uart_buf, uart_buf_len, 100);
}

void uart_transmit_table(int *count, int *pulses, int *htime, int *t_vibration,
                         int *t_responce, bool *open_before_vibr,
                         bool *open_after_vibr, bool *bad,
                         UART_HandleTypeDef *huart) {
  if ((*count) == 1) {
    uart_transmit_msg("MeasurementNr., Pulses, Hightime[ms], t_vibration[ms], "
                      "t_responce[ms], open_before_vibr[bool], "
                      "open_after_vibr[bool], bad[bool]",
                      huart);
  }

  //
  // Static buffer to avoid dynamic memory allocation
  char uart_buf[256]; // Adjust size if needed
                      // Clear the buffer explicitly
  memset(uart_buf, 0, sizeof(uart_buf));

  // Format the message into the buffer
  int uart_buf_len =
      snprintf(uart_buf, sizeof(uart_buf), "%d, %d, %d, %d, %d, %d, %d, %d\r\n",
               *count, *pulses, *htime, *t_vibration, *t_responce,
               *open_before_vibr, *open_after_vibr, *bad);
  if (uart_buf_len < 0 || uart_buf_len >= sizeof(uart_buf)) {
    return; // Handle error or truncate message
  }

  // Transmit the formatted message
  HAL_UART_Transmit(huart, (uint8_t *)uart_buf, uart_buf_len, 100);
}

void uart_transmit_array(uint16_t *arr, size_t length,
                         UART_HandleTypeDef *huart) {
  if (arr == NULL || huart == NULL || length == 0) {
    return; // Validate inputs
  }

  // Static buffer for formatted message
  char uart_buf[512]; // Adjust size as needed

  // Clear the buffer
  memset(uart_buf, 0, sizeof(uart_buf));

  // Format the array into the buffer
  size_t pos = 0; // Tracks current position in the buffer
  for (size_t i = 0; i < length; i++) {
    int bytes_written =
        snprintf(uart_buf + pos, sizeof(uart_buf) - pos, "%d ", arr[i]);
    if (bytes_written < 0 || (pos + bytes_written) >= sizeof(uart_buf)) {
      break; // Handle buffer overflow or formatting error
    }
    pos += bytes_written; // Update position
  }

  // Add newline for clarity
  if (pos < sizeof(uart_buf)) {
    snprintf(uart_buf + pos, sizeof(uart_buf) - pos, "\r\n");
  }

  // Transmit the formatted array
  HAL_UART_Transmit(huart, (uint8_t *)uart_buf, strlen(uart_buf), 100);
}
