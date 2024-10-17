#ifndef INC_PHOTOSENSOR_H_
#define INC_PHOTOSENSOR_H_
#include "stdint.h"
#include <stdbool.h>
#include "stm32h7xx_hal.h"

extern uint16_t arr[10];
extern bool state;
bool photosence(int trigger, ADC_HandleTypeDef hadc);

#endif // !INC_PHOTOSENSOR_H
