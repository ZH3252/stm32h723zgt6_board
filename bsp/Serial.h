#ifndef __SERIAL_H
#define __SERIAL_H
#include "stm32h7xx_hal.h"
#include "usart.h"
#include "stdio.h"
int fputc(int ch,FILE *f);
int fgetc(FILE *f);
#endif

