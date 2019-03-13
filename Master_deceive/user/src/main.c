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

	delay_init(72);			//延时初始化
	uart_init(9600); 	//串口1初始化  	  
	LCD_Init();				//初始化液晶		  
	KEY_Init();				//按键初始化

	SPI_Flash_Init();		//SPI FLASH初始化 
	NRF24L01_Init();    	//初始化NRF24L01 		 
	if (font_init())			//字库不存在,则更新字库
	{	
		POINT_COLOR=RED;      
		LCD_Clear(WHITE);
		LCD_ShowString(60,50,"Mini STM32");	
		LCD_ShowString(60,70,"Font Updating..."); 	 	 
		LCD_Fill(60,90,240,126,WHITE);//清除显示			  
		LCD_Clear(WHITE);
	}  
	while(NRF24L01_Check())//检测不到24L01
	{
		LCD_ShowString(60,130,"24L01 Check Failed!");
		delay_ms(500);
		LCD_ShowString(60,130,"Please Check!      ");
		delay_ms(500);
	}
	RX_Mode();
//	RX_Mode1();

	POINT_COLOR=RED;//设置字体为红色
	Show_Str(60,80,"多点无线测温系统",16,0);  	   	 					 

	while(1)
	{
//		LCD_ShowString(30,100, "baiu:   . C");		//测试使用
		if (NRF24L01_RxPacket(c)==0)
		{  	
//			LCD_ShowString(10,70, "test:   . C");  //测试使用
			if (c[0]=='1')						   //判断是哪个点发出点值，在发送数组赋初值来检测
			{
				temp1=c[1]-'0';
				POINT_COLOR=BLUE;//设置字体为蓝色
				Show_Str(60,150,"1点的温度:   . 度",16,0);  	   	 					 
				LCD_ShowNum(148,150,temp1,2,16);//显示温度值	 
				LCD_ShowNum(172,150,c[2]%10,1,16);//显示温度值
				delay_ms(50);
				LCD_ShowString(30,0,c);
			} 
			if (c[0]=='2')
			{
				temp2=c[1]-'0';
				POINT_COLOR=BLUE;//设置字体为蓝色	   
				Show_Str(60,170,"2点的温度:   . 度",16,0); 					 
				LCD_ShowNum(148,170,temp2,2,16);//显示温度值	 
				LCD_ShowNum(172,170,c[2]%10,1,16);//显示温度值
				delay_ms(50);
				LCD_ShowString(50,0,c);
			} 
			if (c[0]=='3')
			{
				temp3=c[1]-'0';
				POINT_COLOR=BLUE;//设置字体为蓝色	   
				Show_Str(60,170,"3点的温度:   . 度",16,0); 					 
				LCD_ShowNum(148,190,temp3,2,16);//显示温度值	 
				LCD_ShowNum(172,190,c[2]%10,1,16);//显示温度值
				delay_ms(50);
				LCD_ShowString(70,0,c);
			} 
			if (c[0]=='4')
			{
				temp4=c[1]-'0';
				POINT_COLOR=BLUE;//设置字体为蓝色	   
				Show_Str(60,170,"4点的温度:   . 度",16,0); 					 
				LCD_ShowNum(148,210,temp4,2,16);//显示温度值	 
				LCD_ShowNum(172,210,c[2]%10,1,16);//显示温度值
				delay_ms(50);
				LCD_ShowString(90,0,c);
			} 
		}
	};   	      
}


/******************************************END OF FILE*************************/
