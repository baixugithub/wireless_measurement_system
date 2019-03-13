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
	while(DS18B20_Init())//��ʼ��DS18B20,����18B20
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
			LCD_ShowChar(140,150,'-',16,0);//��ʾ����	
		}	
    	POINT_COLOR=BLUE;//��������Ϊ��ɫ	   
	    LCD_ShowString(60,150, "Temperate:   . C");	 					 
		LCD_ShowNum(148,150,temp/10,2,16);//��ʾ�¶�ֵ	  
		LCD_ShowNum(172,150,temp%10,1,16);//��ʾ�¶�ֵ
		b[1]=temp/10+'0';
		b[2]=temp%10;
		if(NRF24L01_TxPacket(b)==TX_OK)
	    {
         LCD_ShowString(30,270,b);		//����a����û���豸��ͬ��ǰ��������У��
        
	    }
	//	 LCD_ShowString(30,270,b);
		delay_ms(1000);
		//LED0=!LED0;
	}	
 	      
}


/******************************************END OF FILE*************************/
