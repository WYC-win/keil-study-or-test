#include <REGX52.H>

sbit DS1302_sclk=P3^6;
sbit DS1302_io=P3^4;
sbit DS1302_ce=P3^5;

#define DS1302_SECOND		0x80
#define DS1302_MINUTE		0x82
#define DS1302_HOUR			0x84
#define DS1302_DATE			0x86
#define DS1302_MONTH		0x88
#define DS1302_DAY			0x8A
#define DS1302_YEAR			0x8C
#define DS1302_WP			0x8E

char DS1302_Time[]={19,11,16,12,59,55,6};

void DS1302_init()
{
	//DS1302_writebyte(0x8E,0x00);
	//DS1302_io=0;
	DS1302_ce=0;
	DS1302_sclk=0;
}

void DS1302_writebyte(unsigned char command,Data)
{
	unsigned char i;
	DS1302_ce=1;
	for(i=0;i<8;i++)
	{
		DS1302_io=command&(0x01<<i);
		DS1302_sclk=1;
		DS1302_sclk=0;
	}
	for(i=0;i<8;i++)
	{
		DS1302_io=Data&(0x01<<i);
		DS1302_sclk=1;
		DS1302_sclk=0;
	}
	DS1302_ce=0;
}

unsigned char DS1302_readbyte(unsigned char command)
{
	unsigned char i,Data=0x00;
	//DS1302_writebyte(0x8E,0x00);
	DS1302_ce=1;
	for(i=0;i<8;i++)
	{
		DS1302_io=command&(0x01<<i);
		DS1302_sclk=0;
		DS1302_sclk=1;
	}
	
	for(i=0;i<8;i++)
	{
		DS1302_sclk=1;
		DS1302_sclk=0;
		if(DS1302_io){Data|=(0x01<<i);}
	}
	DS1302_io=0;
	DS1302_ce=0;
	return Data;
}

void DS1302_SetTime(void)
{
	DS1302_writebyte(DS1302_WP,0x00);
	DS1302_writebyte(DS1302_YEAR,DS1302_Time[0]/10*16+DS1302_Time[0]%10);//十进制转BCD码后写入
	DS1302_writebyte(DS1302_MONTH,DS1302_Time[1]/10*16+DS1302_Time[1]%10);
	DS1302_writebyte(DS1302_DATE,DS1302_Time[2]/10*16+DS1302_Time[2]%10);
	DS1302_writebyte(DS1302_HOUR,DS1302_Time[3]/10*16+DS1302_Time[3]%10);
	DS1302_writebyte(DS1302_MINUTE,DS1302_Time[4]/10*16+DS1302_Time[4]%10);
	DS1302_writebyte(DS1302_SECOND,DS1302_Time[5]/10*16+DS1302_Time[5]%10);
	DS1302_writebyte(DS1302_DAY,DS1302_Time[6]/10*16+DS1302_Time[6]%10);
	DS1302_writebyte(DS1302_WP,0x80);
}

void DS1302_ReadTime(void)
{
	unsigned char Temp;
	Temp=DS1302_readbyte(DS1302_YEAR);
	DS1302_Time[0]=Temp/16*10+Temp%16;//BCD码转十进制后读取
	Temp=DS1302_readbyte(DS1302_MONTH);
	DS1302_Time[1]=Temp/16*10+Temp%16;
	Temp=DS1302_readbyte(DS1302_DATE);
	DS1302_Time[2]=Temp/16*10+Temp%16;
	Temp=DS1302_readbyte(DS1302_HOUR);
	DS1302_Time[3]=Temp/16*10+Temp%16;
	Temp=DS1302_readbyte(DS1302_MINUTE);
	DS1302_Time[4]=Temp/16*10+Temp%16;
	Temp=DS1302_readbyte(DS1302_SECOND);
	DS1302_Time[5]=Temp/16*10+Temp%16;
	Temp=DS1302_readbyte(DS1302_DAY);
	DS1302_Time[6]=Temp/16*10+Temp%16;
}
