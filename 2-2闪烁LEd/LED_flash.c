#include <reg52.h>

unsigned int i;

sbit LED3 = P1^2;
sbit LED5 = P1^4;
void main ()
{
			LED3 = 0;
			LED5 = 0;
			i = 65535;
			while(i--);
			LED3 = 0x2;//1111 1111 0xff
			LED5 = 0x8;
			while(i--);
}	
	