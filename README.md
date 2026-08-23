# 2-2 LED 闪烁

本实验使用软件空循环延时，控制连接在 P1.2 和 P1.4 上的两个 LED 改变状态。

## 学习内容

- 使用 `sbit` 访问单个 GPIO
- 使用无符号整数递减实现简单延时
- 理解高、低电平与 LED 亮灭的关系

当前源码演示一次由低电平到高电平的状态变化；如需持续闪烁，可在后续学习中将状态切换放入无限循环。

## 主要文件

- `2-2闪烁LEd/LED_flash.c`：实验源码
- `2-2闪烁LEd/LED_flash.uvproj`：Keil 工程
- `2-2闪烁LEd/Objects/LED_flash.hex`：可烧录固件

工程已通过 Keil C51 完整重编译，结果为 `0 Error(s), 0 Warning(s)`。

[返回课程索引](../../tree/main)
