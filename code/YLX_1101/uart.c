#include "uart.h"
#include "platform.h"

// UART 初始化 (9600bps @ 16MHz)
void uart_init(void)
{
    // TODO: 根据具体芯片配置UART寄存器
}

// 发送一个字节
void uart_send_byte(unsigned char data)
{
    // TODO: 实现UART发送
}

// 发送字符串
void uart_send_string(unsigned char *str)
{
    while(*str)
    {
        uart_send_byte(*str++);
    }
}

// 接收一个字节 (阻塞)
unsigned char uart_receive_byte(void)
{
    // TODO: 实现UART接收
    return 0;
}