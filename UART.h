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

	�ļ�����UART.h
	���ߣ�������
	���䣺qwgg9654@gmail.com
		  admin@hxlxz.com
	���������������ַ���ͨ��ģ��-ͷ�ļ�
	��ע������ʹ�÷�װ�õĺ������в���������Ҫʹ��ֱ�ӶԴ��ڽ��в�����
        ʹ�ø�ģ�飬����config.h�ж���UART_BUFF_MAX����Ϊ���ݻ���������󳤶ȡ�
            �� #define UART_BUFF_MAX 64
        ʹ�ø�ģ�飬����config.h�ж���XTAL����Ϊ����Ƶ�ʣ���λ���׺��ȣ���
            �� #define XTAL 11.059200
*////////////////////////////////////////////////////////////////////////////////////////
#ifndef _HEAD_UART_
#define _HEAD_UART_

#include<intrins.h>
#include<config.h>
/*///////////////////////////////////////////////////////////////////////////////////
*��������UART_Conf
*�������ܣ����ô���
*�����б�
*   baud
*       �������ͣ�unsigned char������
*       ����������Ҫ���õĲ�����
*////////////////////////////////////////////////////////////////////////////////////
void UART_Conf(unsigned int baud);
/*///////////////////////////////////////////////////////////////////////////////////
*��������UART_SendString
*�������ܣ��򴮿ڷ���һ���ַ���
*�����б�
*   *dat
*       �������ͣ�unsigned char��ָ��
*       ����������Ҫ���͵��ַ������׵�ַ
*   len
*       �������ͣ�unsigned char������
*       ����������Ҫ���͵��ַ����ĳ���
*////////////////////////////////////////////////////////////////////////////////////
void UART_SendString(unsigned char *dat,unsigned char len);
/*///////////////////////////////////////////////////////////////////////////////////
*��������UART_RxMonitor
*�������ܣ������ַ������ս����жϣ��ڶ�ʱ��0�жϺ����е���
*�����б�
*   ms
*       �������ͣ�unsigned char������
*       ������������ʱ����ʱʱ������λ��ms��
*////////////////////////////////////////////////////////////////////////////////////
void UART_RxMonitor(unsigned char ms);
/*///////////////////////////////////////////////////////////////////////////////////
*��������UART_Driver
*�������ܣ�����ͨ�ż�غ���������ѭ���е��á�
*           ������յ��ַ��������Զ��������б�д��UART_Action(unsigned char *dat,unsigned char len)
*////////////////////////////////////////////////////////////////////////////////////
void UART_Driver();


#endif // _HEAD_UART_
