#include <REGX51.H>
void Delay(unsigned int xms)	//@11.030MHz
{
	unsigned char data i, j;
	while(xms)
	{
		i = 2;
		j = 198;
		do
		{
			while (--j);
		} while (--i);
		xms--;
	}
	
}

void main()
{
	char LEDNum=-1;
	P0=0x00;
	//P2=~0x01;
	while(1)
	{
		if(P3_0==0)
		{
			Delay(20);
			while(P3_0==0);
			Delay(20);
			
			LEDNum++;
			if(LEDNum>=8)
			{
				LEDNum=0;
			}
			P2=~(0x01<<LEDNum);
			
		}
		if(P3_1==0)
		{
			Delay(20);
			while(P3_1==0);
			Delay(20);
			if(LEDNum==0)
			{
				LEDNum=7;
			}
			else if(LEDNum==-1)
			{
				LEDNum=0;
			}
			else
			{
				LEDNum--;
			}
			
			if(LEDNum>=8)
			{
				LEDNum=0;
			}
			P2=~(0x01<<LEDNum);
		}
	}
}