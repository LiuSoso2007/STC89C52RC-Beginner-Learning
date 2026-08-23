#include<reg52.h>
#include<intrins.h>

#define uint unsigned int
#define uchar unsigned char

sbit du = P2^6;//duanxuan
sbit we = P2^7;//weixuan

//duanxuan0-9
uchar code tabel[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x07,0x7f,0x6f};
uchar x ,y;
void delay(uint z)
{
    for(x = z; x > 0; x--) 
        for(y = 114; y > 0; y--);
}
void display(uchar i)
{
	uchar bai,shi;
	bai = i / 100;
	shi = i %100 /10;
	//diyiweishumaguan
	P0 = 0xff;
	we = 1;
	P0 = 0xfe;
	we = 0;

	du = 1;
	P0 = tabel[1];
	du = 0;
	delay(5);
	
	
	//dierwei
	P0 = 0xff;
	we = 1;
	P0 = 0xfd;
	we = 0;

	du = 1;
	P0 = tabel[8];
	du = 0;
	delay(5);
	
	
}
void main()
{
	while(1)
	{
		display(18);//xianshishuzi
	}
}


       
		
	

			
			
			
	

