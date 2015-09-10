/*//////////////////////////GPL��Դ���֤////////////////////////////////////////////////
    Copyright (C) <2014>  <Xianglong He>
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

	�ļ�����ir.c
	���ߣ�������
	���䣺qwgg9654@gmail.com
		  admin@hxlxz.com
	��������������ң���źŷ���
*////////////////////////////////////////////////////////////////////////////////////////
#include<stc15.h>
void UART_SendString(unsigned char *dat,unsigned char len);
bit IR = 1;
void Timer0Init_1685(void);
void Timer0Init_4500(void);
void Timer0Init_565(void);
void IR_38KEnable();
void IR_Send(char *dat, int len)
{
	int i;
	IR_38KEnable();
	IR = 1;
	Timer0Init_4500();	
	while(!TF0);
	IR = 0;
	Timer0Init_4500();
	while(!TF0);
	Timer0Init_4500();
	while(!TF0);
	IR = 1;
	Timer0Init_4500();
	while(!TF0);	
	for(i = 0; i < len; i++)
	{
		IR = 0;
		Timer0Init_565();
		while(!TF0);
		IR = 1;
		if(*dat == 1)
			Timer0Init_1685();
		else
			Timer0Init_565();
		while(!TF0);
		dat++;
	}
	IR = 0;
	Timer0Init_565();
	while(!TF0);
	IR = 1;
	Timer0Init_4500();while(!TF0);
	Timer0Init_4500();while(!TF0);
	Timer0Init_4500();while(!TF0);
	Timer0Init_4500();while(!TF0);
	Timer0Init_4500();while(!TF0);
	Timer0Init_4500();while(!TF0);
	TR1 = 0;
}		 
void IR_38KEnable()
{
	AUXR |= 0x40;		//��ʱ��ʱ��1Tģʽ
	TMOD &= 0x0F;		//���ö�ʱ��ģʽ
	TL1 = 0x70;		//���ö�ʱ��ֵ
	TH1 = 0xFF;		//���ö�ʱ��ֵ
	TF1 = 0;		//���TF1��־
	TR1 = 1;		//��ʱ��1��ʼ��ʱ
	ET1 = 1;
	EA = 1;
}
void Interrupt_Timer1() interrupt 3
{
	static char i = 0;
	P01 = IR;
	if(IR == 1)
	{
		P00 = 0;
		return ;
	}
	else 
	{
		P00 = i;
		i = 1 - i;
		return ;
	}
}	 
void Timer0Init_4500(void)		//@11.0592MHz
{
	TR0 = 0;
	AUXR |= 0x80;		//��ʱ��ʱ��1Tģʽ
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TMOD |= 0x01;		//���ö�ʱ��ģʽ
	TL0 = 0x9A;		//���ö�ʱ��ֵ
	TH0 = 0x3D;		//���ö�ʱ��ֵ
	TF0 = 0;		//���TF0��־
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
}
void Timer0Init_565(void)		//565΢��@11.0592MHz
{
	TR0 = 0;
	AUXR |= 0x80;		//��ʱ��ʱ��1Tģʽ
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TMOD |= 0x01;		//���ö�ʱ��ģʽ
	TL0 = 0x98;		//���ö�ʱ��ֵ
	TH0 = 0xE7;		//���ö�ʱ��ֵ
	TF0 = 0;		//���TF0��־
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
}
void Timer0Init_1685(void)		//1685΢��@11.0592MHz
{
	TR0 = 0;
	AUXR |= 0x80;		//��ʱ��ʱ��1Tģʽ
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TMOD |= 0x01;		//���ö�ʱ��ģʽ
	TL0 = 0x35;		//���ö�ʱ��ֵ
	TH0 = 0xB7;		//���ö�ʱ��ֵ
	TF0 = 0;		//���TF0��־
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
}
