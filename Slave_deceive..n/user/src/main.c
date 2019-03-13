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
#include "ds18b20.h"

int main(void)
{
	short temp; 
	u8 b[4]={'1'};

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
	while(DS18B20_Init())//初始化DS18B20,兼检测18B20
	{
		LCD_ShowString(60,130,"DS18B20 Check Failed!");
		delay_ms(500);		  
		LCD_ShowString(60,130,"Please Check!        ");
		delay_ms(500);
	}
	TX_Mode(); 
	while(1)
	{	 
	    
		temp=DS18B20_Get_Temp();
		if(temp<0)
		{
			temp=-temp;
			LCD_ShowChar(140,150,'-',16,0);//显示负号	
		}	
    	POINT_COLOR=BLUE;//设置字体为蓝色	   
	    LCD_ShowString(60,150, "Temperate:   . C");	 					 
		LCD_ShowNum(148,150,temp/10,2,16);//显示温度值	  
		LCD_ShowNum(172,150,temp%10,1,16);//显示温度值
		b[1]=temp/10+'0';
		b[2]=temp%10;
		if(NRF24L01_TxPacket(b)==TX_OK)
	    {
         LCD_ShowString(30,270,b);		//数组a对于没有设备不同，前两个用于校验
        
	    }
	//	 LCD_ShowString(30,270,b);
		delay_ms(1000);
		//LED0=!LED0;
	}	
 	      
}


/******************************************END OF FILE*************************/
