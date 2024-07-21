#ifndef	__LED_H
#define	__LED_H
#include "stm32h7xx_hal.h"

#define LED1_Pin GPIO_PIN_2
#define LED1_GPIO_Port GPIOC
#define LED2_Pin GPIO_PIN_3
#define LED2_GPIO_Port GPIOC
void led_on(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void led_off(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
#endif
