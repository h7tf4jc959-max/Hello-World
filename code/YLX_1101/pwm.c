#include "pwm.h"

void pwm_init(void)
{
    // TC1用于PWM1~3
    TC1CON = 0b01010000;  // TC1EN=1, TC1CKS=0(系统时钟), TC1CAP=0(PWM模式)
    
    // 设置PWM周期 1KHz (16MHz/16/1000 = 1000)
    TC1PRDL = 0xE8;       // 1000 低8位
    TC1PRDTH = 0x03;      // 1000 高4位 (0x03E8)
    
    // 使能PWM1输出
    PWMCON1 = 0b00001001;  // IPWM1EN=1, PWM1EN=1
}

void pwm1_set_duty(unsigned int duty)
{
    PWM1DTL = duty & 0xFF;
    PWM21DTH = (PWM21DTH & 0xF0) | ((duty >> 8) & 0x0F);
}

void pwm2_set_duty(unsigned int duty)
{
    PWM2DTL = duty & 0xFF;
    PWM21DTH = (PWM21DTH & 0x0F) | ((duty >> 4) & 0xF0);
}

void pwm3_set_duty(unsigned int duty)
{
    PWM3DTL = duty & 0xFF;
    TC1PRDTH = (TC1PRDTH & 0x0F) | ((duty >> 4) & 0xF0);
}