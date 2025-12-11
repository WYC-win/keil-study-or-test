#include <REGX52.H>

void Delay(unsigned int xms)	//@12.000MHz
{
	unsigned char data i, j;
	while(xms--)
	{
		i = 2;
		j = 239;
		do
		{
		while (--j);
		} 
		while (--i);
	}
	
}

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
	Delay(1);
	P0=0x00;
	P2=0x1C;//无法使LED模块熄灭！！！
}

void main()
{
	
	
	while(1)
	{
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