# XC8M6600 ADC/DAC/CMP Register Mapping

## ADC 寄存器
### ADATH (0x1A3) - ADC数据高8位 只读
| bit7~0 |
|--------|
| ADAT<11:4> |
复位值: 0x80

### ADATL (0x1A4) - ADC数据低8位 只读
| bit7~0 |
|--------|
| ADAT<7:0> |
复位值: 0x00

### DACON (0x1A5) - DAC控制寄存器 (也含ADC高4位)
| bit7 | bit6 | bit5 | bit4 | bit3~0 |
|------|------|------|------|--------|
| DACEN | DACOUT | CMPOE | - | ADAT<11:8> |
复位值: 0x08
- DACEN: DAC使能
- DACOUT: DAC电压输出使能
- CMPOE: 比较器结果从P61输出使能
- ADAT<11:8>: ADC转换结果高4位 (只读)

### ADCON0 (0x1A6) - ADC控制寄存器0 复位值 0x00
| bit7~3 | bit2 | bit1 | bit0 |
|--------|------|------|------|
| ADIS<4:0> | VCMPS | EXTVS | ADCAP |

**ADIS<4:0> 通道选择:**
| ADIS值 | 通道 |
|--------|------|
| 00000 | AIN0/P50 |
| 00001 | AIN1/P51 |
| 00010 | AIN2/P52 |
| 00011 | AIN3/P53 |
| 00100 | AIN4/P54 |
| 00101 | AIN5/P55 |
| 00110 | AIN6/P56 |
| 00111 | AIN7/P57 |
| 01000 | AIN8/P60 |
| 01001 | AIN9/P61 |
| 01010 | AIN10/P62 |
| 01011 | AIN11/P63 |
| 01100 | AIN12/P64 |
| 01101 | AIN13/P65 |
| 01110 | AIN14/P66 |
| 01111 | AIN15/P67 |
| 10000 | AIN16/P70 |
| 10001 | AIN17/P71 |
| **10010** | **1/4*(VDD或P51)** |
| 10011 | DACVREF |
| 11111 | GND |

- VCMPS: 0=VREF, 1=VDD (ADC比较电压源)
- EXTVS: 0=VDD, 1=P51 (1/4分压源)
- ADCAP: ADC采样通道电容使能

### ADCON1 (0x1A7) - ADC控制寄存器1 复位值 0x07
| bit7 | bit6 | bit5~4 | bit3 | bit2~0 |
|------|------|--------|------|--------|
| ADRUN | ADEN | ADPSR<1:0> | ADCGATE | VREF<2:0> |

**ADPSR<1:0> 时钟分频:**
| ADPSR | ADC时钟 |
|-------|---------|
| 00 | Fosc/16 |
| 01 | Fosc/4 |
| 10 | Fosc/64 |
| 11 | Fosc/1 |

**VREF<2:0> 参考电压:**
| VREF | 参考电压 |
|------|---------|
| 000 | VBG 1.2V |
| 001 | 基准2V |
| 010 | 基准3V |
| 011 | 基准4V |
| 100 | EXVREF |
| 101 | VDD |

- ADRUN: 0=空闲/结束, 1=开始采样
- ADEN: ADC使能
- ADCGATE: 0=软件使能, 1=PWM7下降沿触发

### ADC 转换时间
| 基准/VDD | 工作电压 | 最快分频 | 转换时间 |
|---------|---------|---------|---------|
| VDD | 4.0~5.5V | Fosc/16 | 16us |
| VDD | 2.7~4.0V | Fosc/64 | 64us |

### ADC 采样电压计算
```
ADC采样电压 = 采样值 / 4096 * 参考电压
VDD检测: VDD = (转换结果 / 4096) * 4 * VREF  (ADIS=10010, EXTVS=0)
P51检测: 输入电压 = (采样值 / 4096) * 参考电压 * 4  (ADIS=10010, EXTVS=1)
```

---

## DAC 寄存器
### VREFCAL (0x1AC) - VREF微调寄存器
| bit7~0 |
|--------|
| VREFCAL<7:0> |
复位值: 0x00

---

## CMP 比较器寄存器
### CMPCON0 (0x1EA) - CMP控制寄存器0 复位值 0x00
| bit7 | bit6 | bit5~0 |
|------|------|--------|
| CMPEN | CMPOUT(R) | CMPRS<5:0> |

### CMPCON1 (0x1EB) - CMP控制寄存器1 复位值 0x00
(详见数据手册)

### PWM7CON (0x1C3) bit7 - CMPGATE
- CMPGATE: TC0捕获门控使能, CMPOUT作为捕获源
