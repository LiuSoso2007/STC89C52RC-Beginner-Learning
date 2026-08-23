# STC89C52RC 入门学习

这是我的 STC89C52RC（8051 内核）入门练习仓库，记录从 LED、数码管、定时器到矩阵键盘和串口通信的基础实验。

为便于按课程独立查看，每个实验放在单独的 Git 分支中；`main` 分支只提供索引。

## 实验目录

| 序号 | 实验内容 | 分支 |
| --- | --- | --- |
| 2-1 | 点亮 LED | [`lesson-2-1-led-on`](../../tree/lesson-2-1-led-on) |
| 2-2 | LED 闪烁 | [`lesson-2-2-led-flash`](../../tree/lesson-2-2-led-flash) |
| 2-3 | 流水灯 | [`lesson-2-3-running-led`](../../tree/lesson-2-3-running-led) |
| 2-4 | 数码管静态显示 | [`lesson-2-4-seven-segment-static`](../../tree/lesson-2-4-seven-segment-static) |
| 2-5 | 封装数码管显示函数 | [`lesson-2-5-seven-segment-function`](../../tree/lesson-2-5-seven-segment-function) |
| 2-6 | 定时器秒表 | [`lesson-2-6-timer-stopwatch`](../../tree/lesson-2-6-timer-stopwatch) |
| 2-7 | 矩阵键盘 | [`lesson-2-7-matrix-keypad`](../../tree/lesson-2-7-matrix-keypad) |
| 2-8 | 软件 PWM 呼吸灯 | [`lesson-2-8-pwm-breathing-led`](../../tree/lesson-2-8-pwm-breathing-led) |
| 2-9 | 串口控制 LED | [`lesson-2-9-uart-led-control`](../../tree/lesson-2-9-uart-led-control) |

## 开发环境

- MCU：STC89C52RC 或兼容 8051 单片机
- IDE：Keil μVision 5
- 编译器：Keil C51
- 晶振：工程配置为 24 MHz

9 个工程均已使用 Keil C51 完整重编译，结果为 `0 Error(s), 0 Warning(s)`。各实验的引脚连接和现象说明见对应分支 README。

## 使用方法

1. 切换到需要学习的实验分支。
2. 使用 Keil μVision 打开该分支中的 `.uvproj` 工程。
3. 执行 Rebuild，生成的固件位于 `Objects` 目录。
4. 使用 STC-ISP 将 `.hex` 文件下载到单片机。

> 这些代码用于入门学习。不同开发板的 LED、数码管和按键电平可能不同，烧录前请核对原理图。
