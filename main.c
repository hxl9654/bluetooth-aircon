#include<stc15.h>
void IR_Send(char *dat, int len);

char statu[35] = {0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,1,0};
int main()
{
	while(1)
	{

	}
}
void UART_Action(unsigned char *dat, unsigned char len)
{
	if(len < 2)return;
	else if(len == 2)
	{
		if(dat[0] == 'm' || dat[0] == 'M')
		{
			if(dat[1] == '0')
			{
				statu[0] = 0;
				statu[1] = 0;
				statu[2] = 0;
			}
			else if(dat[1] == '1')
			{
				statu[0] = 1;
				statu[1] = 0;
				statu[2] = 0;
			}
			else if(dat[1] == '2')
			{
				statu[0] = 0;
				statu[1] = 1;
				statu[2] = 0;
			}
			else if(dat[1] == '3')
			{
				statu[0] = 1;
				statu[1] = 1;
				statu[2] = 0;
			}
			else if(dat[1] == '4')
			{
				statu[0] = 0;
				statu[1] = 0;
				statu[2] = 1;
			}
		}
		else if(dat[0] == 'o' || dat[0] == 'O')
		{
			if(dat[1] == 'n' || dat[1] == 'N' || dat[1] == '1')
				statu[3] = 1;
			else if(dat[1] == 'f' || dat[1] == 'F' || dat[1] == '0')
				statu[3] = 0;
		}
		else if(dat[0] == 'w' || dat[0] == 'W')
		{
			if(dat[1] == '0')
			{
				statu[4] = 0;
				statu[5] = 0;
			}
			else if(dat[1] == '1')
			{
				statu[4] = 1;
				statu[5] = 0;
			}
			else if(dat[1] == '2')
			{
				statu[4] = 0;
				statu[5] = 1;
			}
			else if(dat[1] == '3')
			{
				statu[4] = 1;
				statu[5] = 1;
			}
		}
		else if(dat[0] == 'D' || dat[0] == 'd')
		{
			if(dat[1] == '1')
				statu[6] = 1;
			else if(dat[1] == '0')
				statu[6] = 0;
		}
		else if(dat[0] == 's' || dat[0] == 'S')
		{
			if(dat[1] == '1')
				statu[7] = 1;
			else if(dat[1] == '0')
				statu[7] = 0;
		}
		else if(dat[0] == 'h' || dat[0] == 'H')
		{
			if(dat[1] == '1')
				statu[20] = 1;
			else if(dat[1] == '0')
				statu[20] = 0;
		}
		else if(dat[0] == 'l' || dat[0] == 'L')
		{
			if(dat[1] == '1')
				statu[21] = 1;
			else if(dat[1] == '0')
				statu[21] = 0;
		}
		else if(dat[0] == 'f' || dat[0] == 'F')
		{
			if(dat[1] == '1')
				statu[22] = 1;
			else if(dat[1] == '0')
				statu[22] = 0;
		}
		else if(dat[0] == 'E' || dat[0] == 'e')
		{
			if(dat[1] == '1')
				statu[23] = 1;
			else if(dat[1] == '0')
				statu[23] = 0;
		}
		else if(dat[0] == 'c' || dat[0] == 'C')
		{
			if(dat[1] == '0')
			{
				statu[24] = 0;
				statu[25] = 0;
			}
			else if(dat[1] == '1')
			{
				statu[24] = 1;
				statu[25] = 0;
			}
			else if(dat[1] == '2')
			{
				statu[24] = 0;
				statu[25] = 1;
			}
		}
	}
	else if(len == 3)
	{
		if((dat[0] == 'o' || dat[0] == 'O') && (dat[1] == 'f' || dat[1] == 'F') && (dat[2] == 'f' || dat[2] == 'F'))
			statu[3] = 0;
		else if(dat[0] == 't' || dat[0]== 'T')
		{
			if(dat[1] == '1' || dat[1] == '2' || dat[1] == '3')
				if(dat[2] >= '0' && dat[2] <= '9')
				{
					temp = (dat[1] - '0') * 10 + dat[2] - '0';
					if(temp >= 16 && temp <=30)
					{
						temp -= 16;
						statu[8] = temp & 0x01;
						statu[9] = temp & 0x02;
						statu[10] = temp & 0x04;
						statu[11] = temp & 0x08;
					}
				}
		}
	}
	else if(len == 4)
	{
		if(dat[0] == 'b' || dat[0] == 'B')
		{
			statu[12] = 0;
			statu[13] = 0;
			statu[14] = 0;
			statu[15] = 0;
			statu[16] = 0;
			statu[17] = 0;
			statu[18] = 0;
			statu[19] = 0;

			if(dat[1] == '1')
				statu[13] = 1;
			else if(dat[1] == '2')
				statu[14] = 1;
			if(dat[3] == 5)
				statu[12] = 1;
			if(dat[2] >= '0' && dat[2] <= '9')
			{
				temp = dat[2] - '0';
				statu[13] = temp & 0x01;
				statu[14] = temp & 0x02;
				statu[15] = temp & 0x04;
				statu[16] = temp & 0x08;
			}
			if(dat[1] != '0' || dat[2] != '0' || dat[3] != '0')
				statu[15] = 1;
			else statu[15] = 0;
		}
	}
	IR_Send(statu, 35);
}
