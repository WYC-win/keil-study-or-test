#ifndef __DS1302_H__
#define __DS1302_H__
unsigned char DS1302_readbyte(unsigned char command);
void DS1302_writebyte(unsigned char command,Data);
void DS1302_init();
void DS1302_SetTime(void);
void DS1302_ReadTime(void);
extern char DS1302_Time[];
#endif