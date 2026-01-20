#include <REGX52.H>
// Header:模块化编程
// File Name: UART.c
// Author:WYC-win
// Date:2026-1-19


/**
 * @brief  串口初始化
 * @param  无
 * @retval 无
 */

void UART_Init(void)	//4800bps@11.0592MHz
{
	PCON &= 0x7F;		//波特率不倍速
	SCON = 0x50;		//8位数据,可变波特率
//	AUXR &= 0xBF;		//定时器时钟12T模式
//	AUXR &= 0xFE;		//串口1选择定时器1为波特率发生器
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x20;		//设置定时器模式
	TL1 = 0xFA;			//设置定时初始值
	TH1 = 0xFA;			//设置定时重载值
	ET1 = 0;			//禁止定时器中断
	TR1 = 1;			//定时器1开始计时
	ES=1;
	EA=1;
}


/**
 * @brief  串口发送一个字节数据
 * @param  字节数据
 * @retval 无
 */
void UART_SendByte(unsigned char Byte)
{
	SBUF=Byte;
	while(TI==0);
	//Delay(1)
	TI=0;
}

/**
 * @brief  串口中断模板
 * @param  无
 * @retval 无
 */
//void UART_Routine() interrupt 4
//{
//	if(RI==1)
//	{
//		P2=~SBUF;
//		UART_SendByte(SBUF);
//	}
//	RI=0;
//}