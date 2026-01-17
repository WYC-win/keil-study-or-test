#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include <math.h>

unsigned char MatrixKey()
{
	unsigned char KeyNumber=0;
	
	P1=0xFF;
	P1_3=0;
	if(P1_7==0){Delay(20);while(P1_7==0);Delay(20);KeyNumber=1;}
	if(P1_6==0){Delay(20);while(P1_6==0);Delay(20);KeyNumber=4;}
	if(P1_5==0){Delay(20);while(P1_5==0);Delay(20);KeyNumber=7;}
	if(P1_4==0){Delay(20);while(P1_4==0);Delay(20);KeyNumber=11;}
	
	P1=0xFF;
	P1_2=0;
	if(P1_7==0){Delay(20);while(P1_7==0);Delay(20);KeyNumber=2;}
	if(P1_6==0){Delay(20);while(P1_6==0);Delay(20);KeyNumber=5;}
	if(P1_5==0){Delay(20);while(P1_5==0);Delay(20);KeyNumber=8;}
	if(P1_4==0){Delay(20);while(P1_4==0);Delay(20);KeyNumber=10;}
	
	P1=0xFF;
	P1_1=0;
	if(P1_7==0){Delay(20);while(P1_7==0);Delay(20);KeyNumber=3;}
	if(P1_6==0){Delay(20);while(P1_6==0);Delay(20);KeyNumber=6;}
	if(P1_5==0){Delay(20);while(P1_5==0);Delay(20);KeyNumber=9;}
	if(P1_4==0){Delay(20);while(P1_4==0);Delay(20);KeyNumber=12;}
	
	P1=0xFF;
	P1_0=0;
	if(P1_7==0){Delay(20);while(P1_7==0);Delay(20);KeyNumber=0;}
	if(P1_6==0){Delay(20);while(P1_6==0);Delay(20);KeyNumber=0;}
	if(P1_5==0){Delay(20);while(P1_5==0);Delay(20);KeyNumber=0;}
	if(P1_4==0){Delay(20);while(P1_4==0);Delay(20);KeyNumber=0;}
	
	return KeyNumber;

}
unsigned char KeyNum;
unsigned int Password,count;
unsigned long tem,tem1;
void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"ID Password");
	count=1;
	tem=0;
	tem1=0;
	while(1)
	{
		KeyNum=MatrixKey();
		if(KeyNum)
		{
			if(KeyNum<=10)//密码数字区
			{
				if(count<=10)
				{
					/*Password*=10;
					Password+=KeyNum%10;//获取一位密码*/
					Password=KeyNum%10;
					//tem1=pow (10,count-1);
					//tem=tem+(Password*(1000000000/tem1));
					tem*=10;
					tem+=Password;
					count++;
				}
				LCD_ShowNum(2,count-1,Password,1);
			}
			
			if(KeyNum==11)
			{
				LCD_ShowString(2,1,"             ");
				Delay(500);
				LCD_ShowString(2,1,"verifying");
				Delay(500);
				LCD_ShowString(2,10,".");
				Delay(500);
				LCD_ShowString(2,11,".");
				Delay(500);
				LCD_ShowString(2,12,".");
				Delay(500);
				LCD_ShowString(2,13,".");
				Delay(500);
				LCD_ShowString(2,14,".");
				Delay(500);
				LCD_ShowString(2,15,".");
				Delay(500);
				LCD_ShowString(2,16,".");
				Delay(2500);
				if(tem==1011241110)
				{
					LCD_ShowString(2,1,"                  ");
					LCD_ShowString(2,1,"verify success");
					Delay(2500);
					LCD_ShowString(1,14,"   ");
					LCD_ShowString(2,1,"              ");
					LCD_ShowString(1,1,"              ");
					LCD_ShowString(1,1,"WYC:SGI of CUGB");
					LCD_ShowString(2,1,"ID : 1011241110");
					Password=0;
					count=1;
					tem=0;
					//LCD_ShowNum(2,1,Password,4);
				}
				else
				{
					LCD_ShowString(2,1,"                ");
					LCD_ShowString(2,1,"Password Error!");
					Delay(3500);
					LCD_ShowString(1,1,"               ");
					LCD_ShowString(2,1,"               ");
					LCD_ShowString(1,1,"Please wait");
					Delay(1500);
					LCD_ShowString(2,1,"Reseting");
					Delay(500);
					LCD_ShowString(2,10,".");
					Delay(500);
					LCD_ShowString(2,11,".");
					Delay(500);
					LCD_ShowString(2,12,".");
					Delay(500);
					LCD_ShowString(2,13,".");
					Delay(500);
					LCD_ShowString(2,14,".");
					Delay(500);
					LCD_ShowString(2,15,".");
					Delay(500);
					LCD_ShowString(2,16,".");
					Delay(2500);
					LCD_ShowString(1,1,"               ");
					//LCD_ShowString(1,1,"ID Password");
					LCD_ShowString(2,1,"                ");
					LCD_ShowString(1,1,"Try again");
					//LCD_ShowString(1,14,"   ");
					//LCD_ShowString(2,1,"          ");
					Password=0;
					count=1;
					tem=0;
					//LCD_ShowNum(2,1,Password,4);
				}
				
			}
			if(KeyNum==12)
			{
				LCD_ShowString(1,1,"               ");
				LCD_ShowString(2,1,"               ");
				Delay(500);
				LCD_ShowString(1,1,"Please wait");
				Delay(1500);
				LCD_ShowString(2,1,"Reseting");
				Delay(500);
				LCD_ShowString(2,10,".");
				Delay(500);
				LCD_ShowString(2,11,".");
				Delay(500);
				LCD_ShowString(2,12,".");
				Delay(500);
				LCD_ShowString(2,13,".");
				Delay(500);
				LCD_ShowString(2,14,".");
				Delay(500);
				LCD_ShowString(2,15,".");
				Delay(500);
				LCD_ShowString(2,16,".");
				Delay(2500);
				LCD_ShowString(1,1,"               ");
				LCD_ShowString(1,1,"ID Password");
				LCD_ShowString(2,1,"                ");
				Password=0;
				count=1;
				tem=0;
			}
		}
	}
}
