#include "adc.h"

// ADC 初始化
void adc_init(void)
{
    // ADEN=1, ADRUN=0, VREF=101(VDD), ADPSR=00(Fosc/16)
    ADCON1 = 0b01000101;  // 使能ADC, VREF=VDD, Fosc/16
    ADCON0 = 0b00000000;  // AIN0/P50, VCMPS=VREF, EXTVS=VDD
}

// 读取ADC值 (指定通道)
unsigned int adc_read(unsigned char channel)
{
    unsigned int adc_value;
    
    // 选择通道
    ADCON0 = (ADCON0 & 0x07) | (channel << 3);
    
    // 开始转换
    ADCON1 |= 0x80;  // ADRUN=1
    
    // 等待转换完成
    while(ADCON1 & 0x80);
    
    // 读取结果 (12位)
    adc_value = ((unsigned int)(DACON & 0x0F) << 8) | ADATL;
    
    return adc_value;
}