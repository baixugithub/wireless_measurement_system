#ifndef __TEXT_H__
#define __TEXT_H__	 
#include "system.h"	
#include "fontupd.h"

//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//Mini STM32������
//�ı���ʾ���� ��������		   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2010/5/23 
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ����ԭ�� 2009-2019
//All rights reserved
//////////////////////////////////////////////////////////////////////////////////	 

					     
void Get_HzMat(unsigned char *code,unsigned char *mat,u8 size);//�õ����ֵĵ�����
void Show_Font(u8 x,u8 y,u8 *font,u8 size,u8 mode);//��ָ��λ����ʾһ������
void Show_Str(u8 x,u8 y,u8*str,u8 size,u8 mode);//��ָ��λ����ʾһ���ַ��� 
void Show_Str_Mid(u8 x,u16 y,u8*str,u8 size,u8 len);
void Show_PTStr(u8 x,u8 y,u8*str,u8 size,u8 mode,u8 len,u16 offx);//��ʾ�����ַ�
void Str_Scroll(u8 x,u8 y,u8*str,u8 size,u8 mode,u8 len,u8 start);//�����ַ���
void my_stradd(u8*str1,u8*str2);//��str2��str1���,���������str1


#endif
