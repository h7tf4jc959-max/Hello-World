#ifndef __IR_H
#define __IR_H

#include "platform.h"

// NEC协议时间参数 (单位: us)
#define IR_LEAD_CODE_MIN    8500
#define IR_LEAD_CODE_MAX    9500
#define IR_LEAD_SPACE_MIN   4000
#define IR_LEAD_SPACE_MAX   5000
#define IR_DATA_0_MIN       1000
#define IR_DATA_0_MAX       1200
#define IR_DATA_1_MIN       2000
#define IR_DATA_1_MAX       2300

// 解码状态
#define IR_STATE_IDLE       0
#define IR_STATE_LEAD       1
#define IR_STATE_DATA       2
#define IR_STATE_REPEAT     3

// 外部变量
extern volatile unsigned char ir_key_value;
extern volatile unsigned char ir_key_pressed;

void ir_init(void);
void ir_decode(unsigned int pulse_width);

#endif