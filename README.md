# 2-1 点亮 LED

本实验通过 STC89C52RC 的 P1 口控制 8 个 LED，适合熟悉 `sbit` 定义和 GPIO 输出。

## 实验现象

程序将 P1.0～P1.7 全部输出低电平。在常见的低电平点亮开发板上，8 个 LED 会同时点亮。

## 主要文件

- `2-1点亮一个led/main.c`：GPIO 控制源码
- `2-1点亮一个led/project led.uvproj`：Keil 工程
- `2-1点亮一个led/Objects/led_on.hex`：可烧录固件

## 编译

使用 Keil μVision 打开 `.uvproj` 文件并执行 Rebuild。该工程已通过 Keil C51 完整重编译，结果为 `0 Error(s), 0 Warning(s)`。

> LED 的有效电平取决于开发板电路，若现象相反，请先核对原理图。

[返回课程索引](../../tree/main)
