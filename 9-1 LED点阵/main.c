#include <REGX52.H>
#include "Delay.h"

sbit RCK=P3^5;
sbit SCK=P3^6;
sbit SER=P3^4;

/**
 * @brief  74hc595写入一个字节
 * @param  Byte
 * @retval 无
 */

	
void _74HC595_WriteByte(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		SER=Byte&(0x80>>i);//利用位对齐
		SCK=1;
		SCK=0;
	}
	RCK=1;
	RCK=0;
}


/**
* @brief  Led点阵屏显示一列数据
 *@param  自己看吧，懒得打字
* @retval 同上
 */
void matrixled_showcolumn(unsigned char column,Data)
{
	_74HC595_WriteByte(Data);
	P0=~(0x80>>column);
	Delay(1);
	P0=0xFF;
}

void main()
{
	unsigned char p;
	SER=0;
	SCK=0;
	RCK=0; 
	while(1)
	{
		for(p=0;p<8;p++)
		{
			matrixled_showcolumn(p,0xFF);
			Delay(30);
		}
	}
	//matrixled_showcolumn(1,0xFF);
	while(1)
	{
//		_74HC595_WriteByte(0x00);
//		P0=0xFF;
	}
}