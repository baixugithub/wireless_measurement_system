#ifndef __FONTUPD_H__
#define __FONTUPD_H__	 
#include "system.h"

														   
 
#define FONTINFOADDR	0	//������Ϣ�����ַ,ռ25���ֽ�,��24���ֽ����ڱ���ֿ��Ƿ����.
//��ť�ṹ�嶨��
__packed typedef struct 
{
	const u32 ugbkaddr; 	//unigbk�ĵ�ַ
	u32 f16addr;			//gbk16��ַ
	u32 f12addr;			//gbk12��ַ	
	u32 ugbksize;			//unigbk�Ĵ�С	 
}_font_info;

extern _font_info ftinfo;	//�ֿ���Ϣ�ṹ��


u8 update_font(void);//�����ֿ�   
u8 font_init(void);//��ʼ���ֿ�
#endif





















