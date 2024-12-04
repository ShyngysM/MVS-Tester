#ifndef INC_PHOTOSENSOR_H_
#define INC_PHOTOSENSOR_H_
#include "main.h"
#include "stdint.h"
#include <stdbool.h>

// typedef struct {
//   // uint16_t laser_signal[10];
//   bool state;
//   int trigger;
// } photosensor_instance;
// extern bool ph_state;

bool photosence(int trigger_value, ADC_HandleTypeDef *hadc);

#endif // !INC_PHOTOSENSOR_H
