#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char KeyNum;
unsigned int pos;
void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"Password");
	pos=1;
	while(1)
	{
		KeyNum=MatrixKey();
		if(KeyNum)
		{
			LCD_ShowNum(2,pos,KeyNum,1);
			pos++;
		}
	}
}
