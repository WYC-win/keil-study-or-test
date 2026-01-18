#include <REGX52.H>
#include "Timer0.h"
#include "Key.h"
#include <INTRINS.H>

/*void Timer0_Init(void)		//1毫秒@11.0592MHz
{
	//AUXR &= 0x7F;			//定时器时钟12T模式
	TMOD &= 0xF0;			//设置定时器模式
	TMOD |= 0x01;			//设置定时器模式
	TL0 = 0x66;				//设置定时初始值
	TH0 = 0xFC;				//设置定时初始值
	TF0 = 0;				//清除TF0标志
	TR0 = 1;				//定时器0开始计时
	ET0=1;
	EA=1;
	PT0=0;
}*/

unsigned char keynum,LEDmode;
void main()
{
	LEDmode=0;
	keynum=0;
	P2=0xFE;
	Timer0_Init();
	while(1)
	{
		keynum=Key();
		if(keynum)
		{
			if(keynum==1)
			{
				LEDmode++;
				if(LEDmode>=2)LEDmode=0;
			}
//			LEDmode++;
//			if(keynum==1)P2_1=~P2_1;
//			if(keynum==2)P2_1=~P2_1;
//			if(keynum==3)P2_1=~P2_1;
//			if(keynum==4)P2_1=~P2_1;
		}
	}
}

//unsigned int T0Count;
void Timer0_rontine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0x66;				
	TH0 = 0xFC;
	T0Count++;
	if(T0Count>=500)
	{
		T0Count=0;
//		P2_0=~P2_0;
		if(LEDmode==0)
			P2=_crol_(P2,1);
		if(LEDmode==1)
			P2=_cror_(P2,1);
	}

}