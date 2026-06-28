#ifndef __UART_H
#define __UART_H

#include "platform.h"

void uart_init(void);
void uart_send_byte(unsigned char data);
void uart_send_string(unsigned char *str);
unsigned char uart_receive_byte(void);

#endif