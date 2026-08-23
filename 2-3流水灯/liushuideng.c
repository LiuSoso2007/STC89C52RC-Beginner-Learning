#include<reg52.h>
#include<intrins.h>
#define uint unsigned int
#define uchar unsigned char

uchar temp;
unsigned int x,y;

void delay(uint z)
{
    for(x = z; x > 0; x--) 
        for(y = 114; y > 0; y--);
}

void main()
{
    temp = 0xFE;  
    P1 = temp;
    delay(1000);
    
    while(1)
    {
        temp = _crol_(temp, 1);
        P1 = temp;
        delay(1000);
    }
}