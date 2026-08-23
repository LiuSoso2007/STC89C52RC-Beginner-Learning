# 2-9 串口控制 LED

本实验通过串口中断接收文本命令，控制连接在 P1.0 上的 LED，并向电脑返回执行结果。

## 串口命令

| 命令 | 功能 | 返回内容 |
| --- | --- | --- |
| `LED_on` | 点亮 LED | `LED_on_ok` |
| `LED_off` | 熄灭 LED | `LED_off_ok` |
| 其他文本 | 无匹配命令 | `unknown` |

命令以回车符 `\r` 结束。代码使用 Timer1 模式 2，并以 `TH1 = TL1 = 0xFD` 配置目标波特率；实际波特率取决于晶振和单片机时钟模式，使用前请与电脑串口参数核对。

## 主要文件

- `2-9串口通信-电脑控制LED亮灭-单片机返回文本/chuankoutongxin.c`：串口源码
- `2-9串口通信-电脑控制LED亮灭-单片机返回文本/chuankoutongxin.uvproj`：Keil 工程
- `2-9串口通信-电脑控制LED亮灭-单片机返回文本/Objects/chuankoutongxin.hex`：可烧录固件

工程已通过 Keil C51 完整重编译，结果为 `0 Error(s), 0 Warning(s)`。

[返回课程索引](../../tree/main)
