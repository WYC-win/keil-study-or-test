#include <REGX52.H>

unsigned char light_number[10]={0x3F,0x06,0x5B,0x4F,0x55,0x6D,0x7D,0x07,0x7F,0x6F};

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
}

void main()
{
	LED(1,1);
	/*LED(2,2);
	LED(3,3);
	LED(4,4);
	LED(5,5);
	LED(6,6);
	LED(7,7);
	LED(8,8);*/
	
	while(1)
	{
		
	}

}