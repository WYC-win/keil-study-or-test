#include <REGX52.H>
#include "LCD1602.h"
void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"CUGB  SGG  WYC");
	LCD_ShowString(2,1,"ID:");
	LCD_ShowNum(2,5,10112,5);
	LCD_ShowNum(2,10,41110,5);
	while(1)
	{
	
	}
}
