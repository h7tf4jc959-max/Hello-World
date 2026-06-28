// XC8M6600 平台定义
#ifndef __PLATFORM_H
#define __PLATFORM_H

// 系统时钟定义
#define FOSC        16000000UL  // 16MHz IHRC

// 数据类型定义
typedef unsigned char  u8;
typedef unsigned int   u16;
typedef unsigned long  u32;

// 特殊功能寄存器声明
volatile unsigned char ADATH     @ 0x1A3;
volatile unsigned char ADATL     @ 0x1A4;
volatile unsigned char DACON     @ 0x1A5;
volatile unsigned char ADCON0    @ 0x1A6;
volatile unsigned char ADCON1    @ 0x1A7;
volatile unsigned char TC0CON    @ 0x1A8;
volatile unsigned char TC1CON    @ 0x1B0;
volatile unsigned char TC1PRDL   @ 0x1B1;
volatile unsigned char TC1PRDTH  @ 0x1B5;
volatile unsigned char PWM1DTL   @ 0x1B2;
volatile unsigned char PWM2DTL   @ 0x1B3;
volatile unsigned char PWM3DTL   @ 0x1B4;
volatile unsigned char PWM21DTH  @ 0x1B6;
volatile unsigned char PWMCON1   @ 0x1B7;
volatile unsigned char TC2CON    @ 0x1B8;
volatile unsigned char TC2PRDL   @ 0x1B9;
volatile unsigned char TC2PRDTH  @ 0x1BD;
volatile unsigned char PWM4DTL   @ 0x1BA;
volatile unsigned char PWM5DTL   @ 0x1BB;
volatile unsigned char PWM6DTL   @ 0x1BC;
volatile unsigned char PWM54DTH  @ 0x1BE;
volatile unsigned char PWMCON2   @ 0x1BF;
volatile unsigned char PWM7DTL   @ 0x1C2;
volatile unsigned char PWM7CON   @ 0x1C3;
volatile unsigned char IEN0      @ 0x1E0;
volatile unsigned char IEN1      @ 0x1E1;
volatile unsigned char IRQ0      @ 0x1E2;
volatile unsigned char IRQ1      @ 0x1E3;
volatile unsigned char CMPCON0   @ 0x1EA;
volatile unsigned char CMPCON1   @ 0x1EB;
volatile unsigned char VREFCAL   @ 0x1AC;
volatile unsigned char P5        @ 0x1F0;
volatile unsigned char P5DIR     @ 0x1F1;
volatile unsigned char P5PU      @ 0x1F2;
volatile unsigned char P5OD      @ 0x1F3;
volatile unsigned char P6        @ 0x1F4;
volatile unsigned char P6DIR     @ 0x1F5;
volatile unsigned char P6PU      @ 0x1F6;
volatile unsigned char P6OD      @ 0x1F7;
volatile unsigned char P7        @ 0x1F8;
volatile unsigned char P7DIR     @ 0x1F9;
volatile unsigned char P7PU      @ 0x1FA;
volatile unsigned char P7OD      @ 0x1FB;

// 位定义
sbit GIE      @ IEN0:7;
sbit ADRUN    @ ADCON1:7;
sbit ADEN     @ ADCON1:6;

#endif