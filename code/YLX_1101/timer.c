#include "timer.h"

// TC0 初始化 (定时器模式)
void timer0_init(void)
{
    TC0CON = 0b01010000;  // T0EN=1, T0CAP=0(定时器), T0PSR=000(1:1)
    T0PRDL = 0xFF;        // 周期低8位
    T0PRDH = 0xFF;        // 周期高8位
}

// TC0 启动
void timer0_start(void)
{
    TC0CON |= 0x80;  // T0RUN=1
}

// TC0 停止
void timer0_stop(void)
{
    TC0CON &= 0x7F;  // T0RUN=0
}

// TC0 重载计数值
void timer0_reload(unsigned int value)
{
    T0CL = value & 0xFF;
    T0CH = (value >> 8) & 0xFF;
}