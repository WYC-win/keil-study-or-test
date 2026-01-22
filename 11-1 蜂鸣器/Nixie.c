#include <REGX52.H>
#include "Delay.h"
unsigned char light_number[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void LED(unsigned char led_position,number)
{
	switch(led_position)
	{
		case 1:P2_4=1,P2_3=1;P2_2=1;break;
		case 2:P2_4=1,P2_3=1;P2_2=0;break;
		case 3:P2_4=1,P2_3=0;P2_2=1;break;
		case 4:P2_4=1,P2_3=0;P2_2=0;break;
		case 5:P2_4=0,P2_3=1;P2_2=1;break;
		case 6:P2_4=0,P2_3=1;P2_2=0;break;
		case 7:P2_4=0,P2_3=0;P2_2=1;break;
		case 8:P2_4=0,P2_3=0;P2_2=0;break;
	}
	P0=light_number[number];
//	Delay(1);
	//P0=0x00;
	//P2=0x1C;//无法使LED模块熄灭！！！
}