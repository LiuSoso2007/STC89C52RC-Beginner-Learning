#include <reg51.h>
#include <string.h>  

sbit LED0 = P1^0;        

unsigned char uart_buf[16]; //存储接收字符 
unsigned char temp = 0;        
bit receive = 0; //初始化，接收待处理


void uart_init()//串口初始化
{
    EA  = 1;       
    ES  = 1;//串口模式1  
    TR1 = 1; //启动定时器1
		REN = 1;
		TMOD |= 0x20;  //定时器1工作模式2,8位自动重装
		TH1 = 0xfd;
		TL1 = 0xfd;//9600波特率
    SCON = 0x50;   
         
}

void uart_send_char(unsigned char ch)
{
    SBUF = ch;     
    while(!TI);//当 TI 为 0 时，一直循环等待，直到 TI 变为 1（即发送完成）退出循环。    
    TI = 0; //手动复位TI为0，为下一次发送做准备       
}

void uart_send_str(unsigned char *str)//指针，串口发送字符串
{
    while(*str != '\0')  
    {
        uart_send_char(*str);
        str++;
    }
}

void uart_isr() interrupt 4//串口中断
{
    if(RI)  
    {
        RI = 0;//清除接收标志
        if(temp < 16 - 1)  
        {
            uart_buf[temp] = SBUF;//接收  
            if(uart_buf[temp] == '\r') //判断是否为结束标志
            {
                uart_buf[temp] = '\0';  //
                receive = 1; //接收完成
                temp = 0; //准备下一次接收             
            }
            else
            {
                temp++;  
            }
        }
        else  
        {
            temp = 0;  
        }
    }
}

void main()
{
    LED0 = 1;          
    uart_init();  
		memset(uart_buf, 0, 16);  // 初始化缓冲区
    while(1)           
    {
        if(receive)  
        {
            receive = 0;  
            
            if(strcmp(uart_buf, "LED_on") == 0)//判断uart_buf中的字符与LED_on是否相同
            {
                LED0 = 0;                  
                uart_send_str("LED_on_ok\r\n");  
            }
            else if(strcmp(uart_buf, "LED_off") == 0)//判断uart_buf中的字符与LED_off是否相同
            {
                LED0 = 1;                  
                uart_send_str("LED_off_ok\n");
            }
            else
            {
                uart_send_str("unknown\r\n");  
            }
            
            memset(uart_buf, 0, 16);  
        }
    }
}