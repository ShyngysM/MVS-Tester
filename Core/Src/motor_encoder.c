#include "../Inc/motor_encoder.h"

int16_t encoder_velocity = 0;
int32_t encoder_position = 0;
uint16_t timer_counter = 0;

void update_encoder(encoder_instance *encoder_value, TIM_HandleTypeDef *htim) {
  uint32_t temp_counter = __HAL_TIM_GET_COUNTER(htim);
  static uint8_t first_time = 0;
  if (!first_time) {
    encoder_value->velocity = 0;
    first_time = 1;

  } else {
    if (temp_counter == encoder_value->last_counter_value) {
      encoder_value->velocity = 0;

    } else if (temp_counter > encoder_value->last_counter_value) {
      if (__HAL_TIM_IS_TIM_COUNTING_DOWN(htim)) {
        encoder_value->velocity =
            -encoder_value->last_counter_value -
            (__HAL_TIM_GET_AUTORELOAD(htim) - temp_counter);

      } else {
        encoder_value->velocity =
            temp_counter - encoder_value->last_counter_value;
      }

    } else {
      if (__HAL_TIM_IS_TIM_COUNTING_DOWN(htim)) {
        encoder_value->velocity =
            temp_counter - encoder_value->last_counter_value;
      } else {
        encoder_value->velocity =
            temp_counter + (__HAL_TIM_GET_AUTORELOAD(htim) -
                            encoder_value->last_counter_value);
      }
    }
  }
  encoder_value->position += encoder_value->velocity;
  encoder_value->last_counter_value = temp_counter;
}
void reset_encoder(encoder_instance *encoder_value) {
  encoder_value->velocity = 0;
  encoder_value->position = 0;
  encoder_value->last_counter_value = 0;
}

void rotate_motor(int degree, encoder_instance *encoder_value,
                  TIM_HandleTypeDef *htim) {
  bool angle = false;
  while (angle == false) {

    if (encoder_value->position == degree) {
      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
      angle = true;
      break;
    } else if (encoder_value->position > degree) {
      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);

    } else if (encoder_value->position < degree) {
      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
    }
    update_encoder(encoder_value, htim);
  }
}
