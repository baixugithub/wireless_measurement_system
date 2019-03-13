/***#include**************************/
#include "led.h"
#include "delay.h"
#include "key.h"
#include "system.h"
#include "usart.h"
#include "lcd.h"
#include "spi.h"
#include "flash.h"
#include "mmc_sd.h"
#include "ff.h"
#include "integer.h"
#include "diskio.h"
#include "text.h"
#include "24cxx.h"
#include "fontupd.h"
#include "24l01.h"
/***#include**************************/


int main(void)
{
	u8 c[4]={'0'};	  
	short temp1;
	short temp2;
	short temp3;
	short temp4;

	delay_init(72);			//��ʱ��ʼ��
	uart_init(9600); 	//����1��ʼ��  	  
	LCD_Init();				//��ʼ��Һ��		  
	KEY_Init();				//������ʼ��

	SPI_Flash_Init();		//SPI FLASH��ʼ�� 
	NRF24L01_Init();    	//��ʼ��NRF24L01 		 
	if (font_init())			//�ֿⲻ����,������ֿ�
	{	
		POINT_COLOR=RED;      
		LCD_Clear(WHITE);
		LCD_ShowString(60,50,"Mini STM32");	
		LCD_ShowString(60,70,"Font Updating..."); 	 	 
		LCD_Fill(60,90,240,126,WHITE);//�����ʾ			  
		LCD_Clear(WHITE);
	}  
	while(NRF24L01_Check())//��ⲻ��24L01
	{
		LCD_ShowString(60,130,"24L01 Check Failed!");
		delay_ms(500);
		LCD_ShowString(60,130,"Please Check!      ");
		delay_ms(500);
	}
	RX_Mode();
//	RX_Mode1();

	POINT_COLOR=RED;//��������Ϊ��ɫ
	Show_Str(60,80,"������߲���ϵͳ",16,0);  	   	 					 

	while(1)
	{
//		LCD_ShowString(30,100, "baiu:   . C");		//����ʹ��
		if (NRF24L01_RxPacket(c)==0)
		{  	
//			LCD_ShowString(10,70, "test:   . C");  //����ʹ��
			if (c[0]=='1')						   //�ж����ĸ��㷢����ֵ���ڷ������鸳��ֵ�����
			{
				temp1=c[1]-'0';
				POINT_COLOR=BLUE;//��������Ϊ��ɫ
				Show_Str(60,150,"1����¶�:   . ��",16,0);  	   	 					 
				LCD_ShowNum(148,150,temp1,2,16);//��ʾ�¶�ֵ	 
				LCD_ShowNum(172,150,c[2]%10,1,16);//��ʾ�¶�ֵ
				delay_ms(50);
				LCD_ShowString(30,0,c);
			} 
			if (c[0]=='2')
			{
				temp2=c[1]-'0';
				POINT_COLOR=BLUE;//��������Ϊ��ɫ	   
				Show_Str(60,170,"2����¶�:   . ��",16,0); 					 
				LCD_ShowNum(148,170,temp2,2,16);//��ʾ�¶�ֵ	 
				LCD_ShowNum(172,170,c[2]%10,1,16);//��ʾ�¶�ֵ
				delay_ms(50);
				LCD_ShowString(50,0,c);
			} 
			if (c[0]=='3')
			{
				temp3=c[1]-'0';
				POINT_COLOR=BLUE;//��������Ϊ��ɫ	   
				Show_Str(60,170,"3����¶�:   . ��",16,0); 					 
				LCD_ShowNum(148,190,temp3,2,16);//��ʾ�¶�ֵ	 
				LCD_ShowNum(172,190,c[2]%10,1,16);//��ʾ�¶�ֵ
				delay_ms(50);
				LCD_ShowString(70,0,c);
			} 
			if (c[0]=='4')
			{
				temp4=c[1]-'0';
				POINT_COLOR=BLUE;//��������Ϊ��ɫ	   
				Show_Str(60,170,"4����¶�:   . ��",16,0); 					 
				LCD_ShowNum(148,210,temp4,2,16);//��ʾ�¶�ֵ	 
				LCD_ShowNum(172,210,c[2]%10,1,16);//��ʾ�¶�ֵ
				delay_ms(50);
				LCD_ShowString(90,0,c);
			} 
		}
	};   	      
}


/******************************************END OF FILE*************************/
