#ifndef __LCD_INIT_H
#define __LCD_INIT_H
#include "stm32h7xx_hal.h"

#define USE_HORIZONTAL 	0  	//设置横屏或者竖屏显示 0或1为竖屏 2或3为横屏
#define LCD_CTRL 				1		//设置软件或硬件控制   0为软件   1为硬件

#define LCD_W 240
#define LCD_H 240

//SPI端口定义
#define LCD_MOSI_PORT	GPIOD
#define LCD_SCK_PORT	GPIOG
#define LCD_RES_PORT	GPIOG
#define LCD_DC_PORT		GPIOG
#define LCD_CS_PORT		GPIOG
#define LCD_BLK_PORT	GPIOG

#define LCD_MOSI_PIN	GPIO_PIN_7
#define LCD_SCK_PIN		GPIO_PIN_11
#define LCD_RES_PIN		GPIO_PIN_3
#define LCD_DC_PIN		GPIO_PIN_4
#define LCD_CS_PIN		GPIO_PIN_5
#define LCD_BLK_PIN		GPIO_PIN_6


//-----------------LCD端口定义---------------- 
#if(LCD_CTRL==0)
#define LCD_MOSI_Clr() HAL_GPIO_WritePin(LCD_MOSI_PORT,LCD_MOSI_PIN,GPIO_PIN_RESET)//SDA=MOSI
#define LCD_MOSI_Set() HAL_GPIO_WritePin(LCD_MOSI_PORT,LCD_MOSI_PIN,GPIO_PIN_SET)

#define LCD_SCLK_Clr() HAL_GPIO_WritePin(LCD_SCK_PORT,LCD_SCK_PIN,GPIO_PIN_RESET)//SCL=SCLK
#define LCD_SCLK_Set() HAL_GPIO_WritePin(LCD_SCK_PORT,LCD_SCK_PIN,GPIO_PIN_SET)
#endif

#define LCD_RES_Clr()  HAL_GPIO_WritePin(LCD_RES_PORT,LCD_RES_PIN,GPIO_PIN_RESET)//RES
#define LCD_RES_Set()  HAL_GPIO_WritePin(LCD_RES_PORT,LCD_RES_PIN,GPIO_PIN_SET)

#define LCD_DC_Clr()   HAL_GPIO_WritePin(LCD_DC_PORT,LCD_DC_PIN,GPIO_PIN_RESET)//DC
#define LCD_DC_Set()   HAL_GPIO_WritePin(LCD_DC_PORT,LCD_DC_PIN,GPIO_PIN_SET)

#define LCD_CS_Clr()  HAL_GPIO_WritePin(LCD_CS_PORT,LCD_CS_PIN,GPIO_PIN_RESET)//BLK
#define LCD_CS_Set()  HAL_GPIO_WritePin(LCD_CS_PORT,LCD_CS_PIN,GPIO_PIN_SET)

#define LCD_BLK_Clr()  HAL_GPIO_WritePin(LCD_BLK_PORT,LCD_BLK_PIN,GPIO_PIN_RESET)//BLK
#define LCD_BLK_Set()  HAL_GPIO_WritePin(LCD_BLK_PORT,LCD_BLK_PIN,GPIO_PIN_SET)




void LCD_GPIO_Init(void);//初始化GPIO
void LCD_Writ_Bus(uint8_t dat);//模拟SPI时序
void LCD_WR_DATA8(uint8_t dat);//写入一个字节
void LCD_WR_DATA(uint16_t dat);//写入两个字节
void LCD_WR_REG(uint8_t dat);//写入一个指令
void LCD_Address_Set(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2);//设置坐标函数
void LCD_Init(void);//LCD初始化
#endif




