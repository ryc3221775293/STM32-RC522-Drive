#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "rc522.h" 
/************************************************
 ALIENTEK��ӢSTM32������    
 ���ߣ�Ψ������   
 CSDN���ͣ�https://blog.csdn.net/tichimi3375 
*1--SS  <----->PF0
*2--SCK <----->PB13
*3--MOSI<----->PB15
*4--MISO<----->PB14
*5--����
*6--GND <----->GND
*7--RST <----->PF1
*8--VCC <----->VCC
************************************************/
 int main(void)
 {		
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 //���ڳ�ʼ��Ϊ115200
 	LED_Init();			     //LED�˿ڳ�ʼ��
	KEY_Init();          //��ʼ���밴�����ӵ�Ӳ���ӿ�
	InitRc522();				//��ʼ����Ƶ��ģ��
 	while(1)
	{
		RC522_Handel();
	}	 
 }

