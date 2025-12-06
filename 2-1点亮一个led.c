#include <REGX52.H>

void main()
{
		int i=0;
		while(i<100000)
		{
			P2=0xFE;//1111 (15F) 1110(14E)
			i++;
		}
		while(i>=100000)
		{
			P2=0x00;//0000(0)0000(0)
			i++;
		}
}