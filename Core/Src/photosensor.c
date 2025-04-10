#include "../Inc/photosensor.h"

bool photosence(int trigger, ADC_HandleTypeDef *hadc) {
  // uint16_t arr[10];
  int raw = 0;
  bool state;
  // NOTE: basically the code is bad, bsc. you don't know how long it measures
  // the signal from photosensor, probably it is better to use timer instead ...
  for (int i = 0; i < 100; i++) {
    // ADC routine
    HAL_ADC_Start(hadc);
    HAL_ADC_PollForConversion(hadc, HAL_MAX_DELAY);
    raw = HAL_ADC_GetValue(hadc);
    if (raw > trigger) {
      state = false; // Nothing on laser path!
      break;
    } else {
      state = true; // MVS is on laser path!
    }
  }
  return state;
}
