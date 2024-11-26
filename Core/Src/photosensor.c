#include "../Inc/photosensor.h"

// bool photosence(int trigger, ADC_HandleTypeDef hadc){
//   uint16_t arr[10];
//   for (int i = 0; i < 10; i++) {
//     // ADC routine
//     HAL_ADC_Start(&hadc1);
//     HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
//     arr[i] = HAL_ADC_GetValue(&hadc1);
//   }
//   
//   for (int j = 0; j < 10; j++) {
//     if (arr[j] < trigger) {
//       state = true;
//       break;
//     }
//     else {
//       state = false;
//     }
//   }
//   return state;
// }
