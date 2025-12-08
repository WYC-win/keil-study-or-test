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
	unsigned char LEDNum=0;
	while(1)
	{
		if(P3_1==0)
		{
			Delay(20);
			while(P3_1==0);//test if open
			Delay(20);
			
			LEDNum++;//1111 1111    0000 0000    0000 0001   0000 0010   0000 0011
			P2=~LEDNum;//           1111 1111    1111 1110
		}
	}
}