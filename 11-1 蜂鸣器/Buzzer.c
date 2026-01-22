#include <REGX52.H>
#include <INTRINS.h>
sbit Buzzer=P1^5;
unsigned int i;

void Delay500us(void)	//@11.0592MHz
{
	unsigned char data i;

	_nop_();
	i = 227;
	while (--i);
}

void buzzer_time(unsigned int ms)
{
	for(i=0;i<ms*2;i++)
	{
		Buzzer=!Buzzer;
		Delay500us();
	}
}
