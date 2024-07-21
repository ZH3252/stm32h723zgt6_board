#include "main.h"
#include "FreeRTOS.h"
#include "task.h"
#include "bsp.h"
/*任务函数声明*/
static void led_task(void *args);
static void lvgl_timer_task(void *args);
static void key_task(void *args);
static void lvgl_task(void *args);
void lvgl_ui_init(void);

//LVGL控件
lv_obj_t * ui_Bar1;


void create_task(void)
{
	taskENTER_CRITICAL();           //进入临界区

	xTaskCreate(led_task, "led_task", 128, NULL, 2, NULL );
	xTaskCreate(key_task, "key_task", 128, NULL, 3, NULL );
	xTaskCreate(lvgl_timer_task, "lvgl_timer_task", 512, NULL, 4, NULL );
	xTaskCreate(lvgl_task, "lvgl_timer_task", 512, NULL, 4, NULL );
	
	taskEXIT_CRITICAL();            //退出临界区
	
}
static void led_task(void *args) 
{
  while (1)
  {
		led_on(GPIOC,GPIO_PIN_2|GPIO_PIN_3);
		vTaskDelay(1000);
		led_off(GPIOC,GPIO_PIN_2|GPIO_PIN_3);
		vTaskDelay(1000);
  }
}


static void lvgl_timer_task(void *args) 
{
	//demo运行
	//lv_demo_benchmark();
	while(1)
	{ 
		lv_timer_handler();
		vTaskDelay(5);
	}
}


static void key_task(void *args)
{
	while(1)
	{
		if(key_read() == 1)
		{
			printf("key 1!!!!\r\n");
		}
		if(key_read() == 2)
		{
			printf("key 2!!!!\r\n");
		}
		vTaskDelay(5);
	}
}	


void lvgl_ui_init(void)
{
	//进度条初始化
	ui_Bar1 = lv_bar_create(lv_scr_act());
	lv_bar_set_start_value(ui_Bar1, 0, LV_ANIM_OFF);
	lv_obj_set_width(ui_Bar1, 200);
	lv_obj_set_height(ui_Bar1, 20);
	lv_bar_set_range(ui_Bar1,1,100);
	lv_obj_set_align(ui_Bar1, LV_ALIGN_CENTER);
}

static void lvgl_task(void *args)
{
	lvgl_ui_init();
	int count=0;
	while(1)
	{
		lv_bar_set_value(ui_Bar1,count%100,LV_ANIM_ON);
		count++;
		if(count >100)
		{
			count =0 ;
		}
		vTaskDelay(10);
	}
}

