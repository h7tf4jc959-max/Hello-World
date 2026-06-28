# XC8M6600 Interrupt Register Mapping

## 中断使能寄存器

### IEN0 (0x1E0) - 中断使能寄存器0 复位值 0x00
| bit7 | bit6 | bit5 | bit4 | bit3 | bit2 | bit1 | bit0 |
|------|------|------|------|------|------|------|------|
| GIE | TC1IE | TC0IE | CMPIE | ADCIE | PWM7IE | PWM2IE | PWM1IE |

- GIE: 全局中断使能
- TC1IE: TC1中断使能
- TC0IE: TC0中断使能
- CMPIE: 比较器中断使能
- ADCIE: ADC中断使能
- PWM7IE: PWM7中断使能

### IEN1 (0x1E1) - 中断使能寄存器1 复位值 0x00
| bit7 | bit6 | bit5 | bit4 | bit3 | bit2 | bit1 | bit0 |
|------|------|------|------|------|------|------|------|
| - | - | - | - | TC2IE | PWM6IE | PWM5IE | PWM4IE |

- TC2IE: TC2中断使能

---

## 中断请求标志寄存器

### IRQ0 (0x1E2) - 中断请求寄存器0 复位值 0x00
| bit7 | bit6 | bit5 | bit4 | bit3 | bit2 | bit1 | bit0 |
|------|------|------|------|------|------|------|------|
| - | TC1IF | TC0IF | CMPIF | ADCIF | PWM7IF | PWM2IF | PWM1IF |

- 写0清除标志位

### IRQ1 (0x1E3) - 中断请求寄存器1 复位值 0x00
| bit7 | bit6 | bit5 | bit4 | bit3 | bit2 | bit1 | bit0 |
|------|------|------|------|------|------|------|------|
| - | - | - | - | TC2IF | PWM6IF | PWM5IF | PWM4IF |

---

## 中断优先级控制

### IP0 (0x1E4) / IP1 (0x1E5)
默认所有中断为低优先级。设置对应位为1可将该中断提升为高优先级。
