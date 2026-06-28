#include "main.h"
#include "adc.h"
#include "uart.h"
#include "timer.h"
#include "led.h"
#include "key.h"
#include "ir.h"
#include "pwm.h"
#include "power.h"
#include "buzzer.h"

void main(void)
{
    // 系统初始化
    platform_init();
    
    // 各模块初始化
    led_init();
    key_init();
    uart_init();
    adc_init();
    pwm_init();
    timer_init();
    ir_init();
    buzzer_init();
    
    // 使能全局中断
    GIE = 1;
    
    while(1)
    {
        // 主循环
        key_scan();
        
        // 低功耗处理
        power_manage();
    }
}