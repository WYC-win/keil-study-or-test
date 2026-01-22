#include <REGX52.H>
#include "Delay.h"
#include "Key.h"
#include "Nixie.h"
#include "Buzzer.h"
unsigned char keynum;

void main()
{
	LED(1,0);
	while(1)
	{
		keynum=Key();
		if(keynum)
		{
			buzzer_time(500);
			LED(1,keynum);
		}
	}
}