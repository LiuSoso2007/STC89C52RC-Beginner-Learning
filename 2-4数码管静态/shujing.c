#include <reg52.h>
#include <intrins.h>

sbit du = P2^6;
sbit we = P2^7;
sbit bee = P2^3;
void delay(unsigned int z)//2025312118
{
    unsigned int x, y;
    for(x = z; x > 0; x--)
        for(y = 114; y > 0; y--);
}

void main()
{
    while(1)
    {
				bee = ~bee;
        // 第一位数码管
        du = 0;       // 先关闭段选，防止干扰
        P0 = 0xFF;    // 清除段选数据
        
				we = 1;
        P0 = 0XFE;    // 位选信号（1111 1110）
        we = 0;
			
        du = 1;
        P0 = 0X3F;    // 段选：0
        du = 0;
        delay(1);

        // 第二位数码管
        du = 0;       // 切换前关闭段选
        P0 = 0xFF;
			
        we = 1;
        P0 = 0XFD;    // 位选信号（1111 1101）
        we = 0;
			
        du = 1;
        P0 = 0X07;    // 段选：7
        du = 0;
        delay(1);

        // 第三位数码管
        du = 0;       // 切换前关闭段选
        P0 = 0xFF;
				
        we = 1;
        P0 = 0XFB;    // 位选信号（1111 1011）
        we = 0;
				
        du = 1;
        P0 = 0X5B;    // 段选：2
        du = 0;
        delay(1);

        // 第四位数码管（最后一位）
        du = 0;       // 切换前关闭段选（重点解决最后位残影）
        P0 = 0xFF;
				
        we = 1;
        P0 = 0XF7;    // 位选信号（1111 0111）
        we = 0;
				
        du = 1;
        P0 = 0X06;    // 段选：1
        du = 0;
        delay(1);

        P0 = 0xff;
    }
}