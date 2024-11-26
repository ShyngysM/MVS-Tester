#ifndef INC_PHOTOSENSOR_H_
#define INC_PHOTOSENSOR_H_
#include "main.h"
#include "stdint.h"
#include <stdbool.h>

typedef struct {
  uint16_t arr[10];
  bool state;
  int trigger;
} photosensor_instance;

bool photosence(int trigger, ADC_HandleTypeDef *hadc);

#endif // !INC_PHOTOSENSOR_H
