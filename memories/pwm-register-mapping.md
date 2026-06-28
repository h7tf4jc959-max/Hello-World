# PWM Register Mapping for XC8M6600 (Ver1.2)

## 系统时钟
- IHRC = 16MHz (高速), ILRC = 低速
- TC1CKS=0 → 系统时钟; TC1CKS=1 → 低速时钟

## PWM 输出选择 (PWMCON1 bit4~6, PWMCON2 bit4~6, PWM7CON bit5)
| S 位 | =0 | =1 | 所属 |
|------|-----|-----|------|
| PWM1S | P60 | **P66** | PWMCON1 bit4 |
| PWM2S | P61 | **P67** | PWMCON1 bit5 |
| PWM3S | **P65** | P55 | PWMCON1 bit6 |
| PWM4S | P62 | P51 | PWMCON2 bit4 |
| PWM5S | P63 | P52 | PWMCON2 bit5 |
| PWM6S | P64 | P50 | PWMCON2 bit6 |
| PWM7S | P57 | P54 | PWM7CON bit5 |

## PWMCON1 (0x1B7) 复位值 0x00
| bit7 | bit6 | bit5 | bit4 | bit3 | bit2 | bit1 | bit0 |
|------|------|------|------|------|------|------|------|
| BZ1EN | PWM3S | PWM2S | PWM1S | IPWM1EN | PWM3EN | PWM2EN | PWM1EN |

## PWMCON2 (0x1BF) 复位值 0x00
| bit7 | bit6 | bit5 | bit4 | bit3 | bit2 | bit1 | bit0 |
|------|------|------|------|------|------|------|------|
| BZ2EN | PWM6S | PWM5S | PWM4S | IPWM4EN | PWM6EN | PWM5EN | PWM4EN |

## PWM7CON (0x1C3) 复位值 0x00
| bit7 | bit6 | bit5 | bit4 | bit3 | bit2 | bit1 | bit0 |
|------|------|------|------|------|------|------|------|
| CMPGATE | PWM_PULSE_EN | PWM7S | PWM7EN | PWM7DTH<11:8> |

---

## ⚠️ 重点：占空比/周期高位寄存器布局

**规律：一律 [7:4]=周期高位, [3:0]=占空比高位（TC1和TC2相同）**

| 寄存器 | 地址 | [7:4] | [3:0] |
|--------|------|-------|-------|
| **TC1PRDTH** | 0x1B5 | **TC1PRD**<11:8> | **PWM3DT**<11:8> |
| **TC2PRDTH** | 0x1BD | **TC2PRD**<11:8> | **PWM6DT**<11:8> |
| **PWM21DTH** | 0x1B6 | **PWM2DT**<11:8> | **PWM1DT**<11:8> |
| **PWM54DTH** | 0x1BE | **PWM5DT**<11:8> | **PWM4DT**<11:8> |

## PWM 占空比寄存器完整列表
| 通道 | 低8位 | 高4位 |
|------|-------|-------|
| PWM1 | PWM1DTL (0x1B2) | PWM21DTH[3:0] |
| PWM2 | PWM2DTL (0x1B3) | PWM21DTH[7:4] |
| PWM3 | PWM3DTL (0x1B4) | TC1PRDTH[7:4] |
| PWM4 | PWM4DTL (0x1BA) | PWM54DTH[3:0] |
| PWM5 | PWM5DTL (0x1BB) | PWM54DTH[7:4] |
| PWM6 | PWM6DTL (0x1BC) | TC2PRDTH[7:4] |
| PWM7 | PWM7DTL (0x1C2) | PWM7CON[3:0] |

## 周期寄存器
| 定时器 | 低8位 | 高4位 | 适用PWM |
|--------|-------|-------|---------|
| TC1 | TC1PRDL (0x1B1) | TC1PRDTH[3:0] | PWM1~3 |
| TC2 | TC2PRDL (0x1B9) | TC2PRDTH[3:0] | PWM4~7 |

## 预分频系数 (TC1CON/TC2CON bits[3:0])
| TCxPTEN | TCxPSR[2] | TCxPSR[1] | TCxPSR[0] | 分频 |
|---------|-----------|-----------|-----------|------|
| 0 | 0 | 0 | 0 | 1:1 |
| 1 | 0 | 0 | 0 | 1:2 |
| 1 | 0 | 0 | 1 | 1:4 |
| 1 | 0 | 1 | 0 | 1:8 |
| 1 | 0 | 1 | 1 | 1:16 |
| 1 | 1 | 0 | 0 | 1:32 |
| 1 | 1 | 0 | 1 | 1:64 |
| 1 | 1 | 1 | 0 | 1:128 |
| 1 | 1 | 1 | 1 | 1:256 |

### TC1CON (0x1B0)
