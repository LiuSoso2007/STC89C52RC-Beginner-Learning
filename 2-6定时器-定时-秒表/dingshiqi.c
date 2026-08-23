#include<reg52.h>
#include<intrins.h>

#define uint unsigned int
#define uchar unsigned char

sbit du = P2^6;//段选，哪个形状
sbit we = P2^7;//位选，哪个数码管亮

//段选0-9
uchar code tabel[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

void delay(uint z)
{
	uint x,y;
	for(x = z; x > 0; x--) 
  for(y = 114; y > 0; y--);
}
void display(uchar i)
{
	uchar shi,ge;
	shi = i %100 /10;
	ge = i % 10;
	
	//第一位数码管
	P0 = 0xff;
	we = 1;
	P0 = 0xfe;
	we = 0;

	du = 1;
	P0 = tabel[shi];
	du = 0;
	delay(5);
	
	
	//第二位数码管
	P0 = 0xff;
	we = 1;
	P0 = 0xfd;
	we = 0;

	du = 1;
	P0 = tabel[ge];
	du = 0;
	delay(5);
	//数码管
	 
}
//定时器初始化
void timer0Init()
{
	TR0 = 1;//启动定时器0
	TMOD = 0x01;//工作模式1,16位定时器计数模式
	TH0 = 0x4b;//(65535-50000)/256
	TL0 = 0xfd;//(66535-50000%256
	//设置初值，以达到定时50000us（50ms）
}
void main()
{
	uchar msec, sec;
	timer0Init();
	while(1)
	{
		if(TF0 == 1)
		{
			TF0 =0;
			TH0 = 0x4b;
			TL0 = 0xfd;
			msec++;//50ms到，并重新加载初值，msec加 1
			if(msec == 20)
			{
			msec = 0;//重新记一直到20，循环
				sec++;//1s到，sec+1s
			}
		}	
		display(sec);//显示数字
		if(sec > 18)
		sec = 0;//秒清零
	}
}
