#include "main.h"
int key_read(void)
{
	if(HAL_GPIO_ReadPin(GPIOE,SW1_Pin) == GPIO_PIN_RESET)
	{
		return 1;
	}
		
	if(HAL_GPIO_ReadPin(GPIOE,SW2_Pin) == GPIO_PIN_RESET)
	{
		return 2;	
	}
	return 0;
}


