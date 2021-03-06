#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "rc522.h" 
/************************************************
 ALIENTEK精英STM32开发板    
 作者：唯恋殊雨   
 CSDN博客：https://blog.csdn.net/tichimi3375 
*1--SS  <----->PF0
*2--SCK <----->PB13
*3--MOSI<----->PB15
*4--MISO<----->PB14
*5--悬空
*6--GND <----->GND
*7--RST <----->PF1
*8--VCC <----->VCC
************************************************/
 int main(void)
 {		
	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(115200);	 //串口初始化为115200
 	LED_Init();			     //LED端口初始化
	KEY_Init();          //初始化与按键连接的硬件接口
	InitRc522();				//初始化射频卡模块
 	while(1)
	{
		RC522_Handel();
	}	 
 }

