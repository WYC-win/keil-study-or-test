#include <REGX52.H>
#include "Delay.h"
#include "Nixie.h"
void main()
{
	while (1)
	{
		/*P2_0=1;
		Delay(500);
		P2_0=0;
		Delay(500);*/
		LED(1,1);
		//Delay(1);
		LED(2,2);
		//Delay(1);
		LED(3,3);
		//Delay(1);
		LED(4,4);
		//Delay(1);
		LED(5,5);
		//Delay(1);
		LED(6,6);
		//Delay(1);
		LED(7,7);
		//Delay(1);
		LED(8,8);
		//Delay(1);
		//P2=0x1C;
	}
}