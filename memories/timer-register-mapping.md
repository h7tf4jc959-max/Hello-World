# XC8M6600 Timer/Counter Register Mapping

## TC0 - 定时器/计数器0 (8位)

### TC0CON (0x1A8) - TC0控制寄存器 复位值 0x00
| bit7 | bit6 | bit5 | bit4 | bit3 | bit2~0 |
|------|------|------|------|------|--------|
| T0RUN | T0EN | - | T0CAP | T0GATE | T0PSR<2:0> |

- T0RUN: 0=停止, 1=启动计数
- T0EN: TC0使能
- T0CAP: 0=定时器模式, 1=捕获模式
- T0GATE: 0=软件门控, 1=CMPOUT门控

**T0PSR<2:0> 预分频:**
| T0PSR | 分频比 |
|-------|--------|
| 000 | 1:1 |
| 001 | 1:2 |
| 010 | 1:4 |
| 011 | 1:8 |
| 100 | 1:16 |
| 101 | 1:32 |
| 110 | 1:64 |
| 111 | 1:128 |

### T0CL (0x1A9) - TC0计数低8位 复位值 0x00
### T0CH (0x1AA) - TC0计数高8位 复位值 0x00
### T0PRDL (0x1AD) - TC0周期低8位 复位值 0xFF
### T0PRDH (0x1AE) - TC0周期高8位 复位值 0xFF

## TC1/TC2 - 定时器1/2 (12位, 用于PWM)

### TC1CON (0x1B0) / TC2CON (0x1B8) 复位值 0x00
| bit7 | bit6 | bit5 | bit4 | bit3~0 |
|------|------|------|------|--------|
| TCxRUN | TCxEN | TCxCKS | TCxCAP | TCxPSR<3:0> |

- TCxRUN: 0=停止, 1=启动
- TCxEN: 使能
- TCxCKS: 0=系统时钟(IHRC), 1=低速时钟(ILRC)
- TCxCAP: 0=PWM模式, 1=捕获模式
- TCxPSR<3:0>: 预分频 (见PWM文档)
