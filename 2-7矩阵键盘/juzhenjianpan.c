#include <reg52.h>
#include <intrins.h>
#define uint unsigned int
#define uchar unsigned char

sbit DU = P2^6;  // 段选锁存器
sbit WE = P2^7;  // 位选锁存器

uchar code wei[] = {0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};  // 8位位选信号（低电平有效）
uchar code tabel[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x76,0x38,0x37,0x3e,0x40,0x00};  // 段码表

uchar KeyValue = 20;  // 按键值（初始无效）
uint num = 0;         // 存储输入数字
uchar digit[8] = {0}; // 拆分后的8位数字

// 延时函数（ms级）
void delay(uint z) {
    uint x, y;
    for (x = z; x > 0; x--)
        for (y = 114; y > 0; y--);  // 保持原延时参数
}

// 键盘扫描函数（保持原逻辑，确保按键识别正确）
void KeyScan() {
    P3 = 0xf0;  // 高四位输出，低四位输入检测列
    if (P3 != 0xf0) {
        delay(10);  // 消抖
        if (P3 != 0xf0) {
            // 检测列
            switch(P3) {
                case 0xe0: KeyValue = 0; break;
                case 0xd0: KeyValue = 1; break;
                case 0xb0: KeyValue = 2; break;
                case 0x70: KeyValue = 3; break;
            }
            // 检测行
            P3 = 0x0f;
            switch(P3) {
                case 0x0e: KeyValue += 0; break;
                case 0x0d: KeyValue += 4; break;
                case 0x0b: KeyValue += 8; break;
                case 0x07: KeyValue += 12; break;
            }
            // 更新数字（限制8位）
            num = num * 10 + KeyValue;
            if (num > 99999999) num = 0;
            // 等待按键释放
            while (P3 != 0x0f);
            delay(10);  // 释放消抖
        }
    }
    P3 = 0xff;  // 恢复P3口，避免干扰显示
}

// 拆分数字（保持原逻辑：digit[0]千万位，digit[7]个位）
void split_num(uint n) {
    digit[0] = n / 10000000;          // 千万位
    digit[1] = (n % 10000000) / 1000000;  // 百万位
    digit[2] = (n % 1000000) / 100000;    // 十万位
    digit[3] = (n % 100000) / 10000;      // 万位
    digit[4] = (n % 10000) / 1000;        // 千位
    digit[5] = (n % 1000) / 100;          // 百位
    digit[6] = (n % 100) / 10;            // 十位
    digit[7] = n % 10;                    // 个位
}

// 显示函数（优化时序，解决串扰问题）
void display() {
    uchar i;
    split_num(num);  // 只拆分一次数字，避免重复计算
    
    for (i = 0; i < 8; i++) {
        // 1. 先关闭所有位选，防止位切换时串扰
        WE = 1;
        P0 = 0xff;  // 高电平无效，关闭所有位选
        WE = 0;
        
        // 2. 锁存当前位的位选信号
        WE = 1;
        P0 = wei[i];  // 选择第i位数码管
        WE = 0;       // 锁存位选，确保信号稳定
        
        // 3. 清空段选口，避免残留信号干扰
        DU = 1;
        P0 = 0x00;    // 先熄灭段选
        DU = 0;
        
        // 4. 锁存当前位的段选信号
        DU = 1;
        P0 = tabel[digit[i]];  // 输出当前位的段码
        DU = 0;                // 锁存段选
        
        // 5. 维持显示，确保人眼可见
        delay(1);
    }
}

// 主函数
void main() {
    while (1) {
        KeyScan();    // 扫描按键
        display();    // 刷新显示
    }
}