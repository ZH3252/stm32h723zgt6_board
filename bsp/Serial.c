#include "Serial.h"
int fputc(int ch,FILE *f)
{
	HAL_UART_Transmit(&huart1,(uint8_t *)&ch,1,HAL_MAX_DELAY);
	return ch;
}

int fgetc(FILE *f)
{
	uint8_t ch;
	HAL_UART_Receive( &huart1,(uint8_t*)&ch,1, HAL_MAX_DELAY );
	return ch;
}
