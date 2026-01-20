#include <REGX52.H>

void Delay(unsigned int xms)	//@11.0592MHz
{
	//unsigned int count=0; 
	while(xms--)
	{
		unsigned char data i, j;

		//_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		}	 while (--i);
//		count++;
//		if(count==xms)
//		{break;}
	}
	
}
