#include <REGX51.H>
#include <INTRINS.h>
void Delay(unsigned int xms)	//@11.030MHz
{
	unsigned char data i, j;
	while(xms)
	{
		_nop_();
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
	while(1)
	{
		/*P2_0=0;
		Delay(500);
		P2_0=1;
		Delay(500);*/
		if(P3_1==0)
		{
			Delay(20);
			while(P3_1==0);//test if open
			Delay(20);
			P2_0=~P2_0;
		}
	}
}
