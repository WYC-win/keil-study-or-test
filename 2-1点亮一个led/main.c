#include <REGX52.H>

void main()
{
		long i=0;
		while(i<1000000)
		{
			P2=0xFE;//1111 (15F) 1110(14E)
			i++;
		}
		while(i>=1000000)
		{
			P2=0x00;//0000(0)0000(0)
			i++;
		}
}
/*#include <REGX52.H>

void Delay(unsigned int t){ while(t--); }

void main()
{
    unsigned long i = 0;

    P2 = 0xFE;                   // 单灯（假设低电平点亮）
    while(i < 1000000UL) i++;

    // 一旦到这里，就疯狂闪烁：不可能看不见
    while(1){
        P2 = 0x00;
        Delay(50000);
        P2 = 0xFF;
        Delay(50000);
    }
}*/
