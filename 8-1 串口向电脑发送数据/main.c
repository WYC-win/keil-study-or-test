#include <REGX52.H>
#include "Delay.h"
#include "UART.h"
//void UART_Init(void)	//4800bps@11.0592MHz
//{
//	PCON &= 0x7F;		//波特率不倍速
//	SCON = 0x50;		//8位数据,可变波特率
////	AUXR &= 0xBF;		//定时器时钟12T模式
////	AUXR &= 0xFE;		//串口1选择定时器1为波特率发生器
//	TMOD &= 0x0F;		//设置定时器模式
//	TMOD |= 0x20;		//设置定时器模式
//	TL1 = 0xFA;			//设置定时初始值
//	TH1 = 0xFA;			//设置定时重载值
//	ET1 = 0;			//禁止定时器中断
//	TR1 = 1;			//定时器1开始计时
//}

//void UART_Init()
//{
//	SCON=0x40;
//	PCON=0;
//	TMOD &= 0x0F;			//设置定时器模式
//	TMOD |= 0x20;			//设置定时器模式
//	TL0 = 0x66;				//设置定时初始值
//	TH0 = 0xFC;				//设置定时初始值
//	TF0 = 0;				//清除TF0标志
//	TR0 = 1;				//定时器0开始计时
//	ET0=1;
//	EA=1;
//	PT0=0;
//}

//void UART_SendByte(unsigned char Byte)
//{
//	SBUF=Byte;
//	while(TI==0);
//	//Delay(1)
//	TI=0;
//}
unsigned char SEC;
void main()
{
	UART_Init();
	
	while(1)
	{
		UART_SendByte(SEC);
		Delay(1000);
		SEC++;
		//Delay(1);
	}
}