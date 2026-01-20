#ifndef _matrixled_H__
#define _matrixled_H__
void matrixled_init();
void _74HC595_WriteByte(unsigned char Byte);
void matrixled_showcolumn(unsigned char column,Data);
#endif