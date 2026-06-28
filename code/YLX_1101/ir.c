#include "ir.h"

// NEC协议解码状态
static unsigned char ir_state = IR_STATE_IDLE;
static unsigned char ir_bit_count = 0;
static unsigned char ir_byte_count = 0;
static unsigned char ir_data[4];

volatile unsigned char ir_key_value = 0;
volatile unsigned char ir_key_pressed = 0;

// IR初始化
void ir_init(void)
{
    // TODO: 配置外部中断引脚接收红外信号
    ir_state = IR_STATE_IDLE;
    ir_key_value = 0;
    ir_key_pressed = 0;
}

// 红外解码 (由定时器中断调用)
void ir_decode(unsigned int pulse_width)
{
    switch(ir_state)
    {
        case IR_STATE_IDLE:
            if(pulse_width > IR_LEAD_CODE_MIN && pulse_width < IR_LEAD_CODE_MAX)
            {
                ir_state = IR_STATE_LEAD;
                ir_bit_count = 0;
                ir_byte_count = 0;
            }
            break;
            
        case IR_STATE_LEAD:
            // 等待9ms引导码结束
            if(pulse_width > IR_LEAD_SPACE_MIN && pulse_width < IR_LEAD_SPACE_MAX)
            {
                ir_state = IR_STATE_DATA;
            }
            else
            {
                ir_state = IR_STATE_IDLE;
            }
            break;
            
        case IR_STATE_DATA:
            if(pulse_width > IR_DATA_1_MIN && pulse_width < IR_DATA_1_MAX)
            {
                // 数据位 1
                ir_data[ir_byte_count] |= (1 << ir_bit_count);
            }
            else if(pulse_width > IR_DATA_0_MIN && pulse_width < IR_DATA_0_MAX)
            {
                // 数据位 0
                ir_data[ir_byte_count] &= ~(1 << ir_bit_count);
            }
            else
            {
                ir_state = IR_STATE_IDLE;
                break;
            }
            
            ir_bit_count++;
            if(ir_bit_count >= 8)
            {
                ir_bit_count = 0;
                ir_byte_count++;
                if(ir_byte_count >= 4)
                {
                    // 检查是否重复码
                    if(ir_data[0] == 0x00 && ir_data[1] == 0xFF)
                    {
                        // 重复码, 使用上次的键值
                    }
                    else
                    {
                        ir_key_value = ir_data[2];
                    }
                    ir_key_pressed = 1;
                    ir_state = IR_STATE_IDLE;
                }
            }
            break;
    }
}