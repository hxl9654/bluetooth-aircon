/*//////////////////////////GPL开源许可证////////////////////////////////////////////////
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

	文件名：ir.c
	作者：何相龙
	邮箱：qwgg9654@gmail.com
		  admin@hxlxz.com
	功能描述：红外遥控信号发出
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
	AUXR |= 0x40;		//定时器时钟1T模式
	TMOD &= 0x0F;		//设置定时器模式
	TL1 = 0x70;		//设置定时初值
	TH1 = 0xFF;		//设置定时初值
	TF1 = 0;		//清除TF1标志
	TR1 = 1;		//定时器1开始计时
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
	AUXR |= 0x80;		//定时器时钟1T模式
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0x9A;		//设置定时初值
	TH0 = 0x3D;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
}
void Timer0Init_565(void)		//565微秒@11.0592MHz
{
	TR0 = 0;
	AUXR |= 0x80;		//定时器时钟1T模式
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0x98;		//设置定时初值
	TH0 = 0xE7;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
}
void Timer0Init_1685(void)		//1685微秒@11.0592MHz
{
	TR0 = 0;
	AUXR |= 0x80;		//定时器时钟1T模式
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0x35;		//设置定时初值
	TH0 = 0xB7;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
}
