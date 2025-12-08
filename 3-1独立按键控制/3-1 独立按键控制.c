#include <REGX52.H>

void main()
{
	P0=0x00;
	/*P2=0xFE;
	P2_0=0;//light
	P2_0=1;//dark*/
	while(1)
	{
		if(P3_1==0)
		{
			P2_0=0;
		}
		else
		{
			P2_0=1;
		}
	}
}