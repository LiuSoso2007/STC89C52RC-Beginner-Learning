# 2-3 流水灯

本实验通过循环左移 P1 口中的低电平位，实现 8 个 LED 依次点亮的流水效果。

## 学习内容

- 使用 `_crol_` 完成循环移位
- 使用 P1 口同时控制 8 路输出
- 编写可复用的软件延时函数

## 主要文件

- `2-3流水灯/liushuideng.c`：流水灯源码
- `2-3流水灯/STARTUP.A51`：8051 启动代码
- `2-3流水灯/liushuideng.uvproj`：Keil 工程
- `2-3流水灯/Objects/liushuideng.hex`：可烧录固件

工程已通过 Keil C51 完整重编译，结果为 `0 Error(s), 0 Warning(s)`。

[返回课程索引](../../tree/main)
