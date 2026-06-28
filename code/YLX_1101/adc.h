#ifndef __ADC_H
#define __ADC_H

#include "platform.h"

// ADC 通道定义
#define ADC_AIN0     0   // P50
#define ADC_AIN1     1   // P51
#define ADC_AIN2     2   // P52
#define ADC_AIN3     3   // P53
#define ADC_AIN4     4   // P54
#define ADC_AIN5     5   // P55
#define ADC_AIN6     6   // P56
#define ADC_AIN7     7   // P57
#define ADC_AIN8     8   // P60
#define ADC_AIN9     9   // P61
#define ADC_AIN10   10   // P62
#define ADC_AIN11   11   // P63
#define ADC_AIN12   12   // P64
#define ADC_AIN13   13   // P65
#define ADC_AIN14   14   // P66
#define ADC_AIN15   15   // P67
#define ADC_AIN16   16   // P70
#define ADC_AIN17   17   // P71
#define ADC_VDD_DIV 18   // 1/4 VDD
#define ADC_DACVREF 19   // DACVREF
#define ADC_GND     31   // GND

// ADC参考电压
#define ADC_VREF_VBG     0   // 1.2V
#define ADC_VREF_2V      1   // 2V
#define ADC_VREF_3V      2   // 3V
#define ADC_VREF_4V      3   // 4V
#define ADC_VREF_EXTVREF 4   // 外部参考
#define ADC_VREF_VDD     5   // VDD

// ADC时钟分频
#define ADC_CLK_DIV1   3  // Fosc/1
#define ADC_CLK_DIV4   1  // Fosc/4
#define ADC_CLK_DIV16  0  // Fosc/16
#define ADC_CLK_DIV64  2  // Fosc/64

void adc_init(void);
unsigned int adc_read(unsigned char channel);

#endif