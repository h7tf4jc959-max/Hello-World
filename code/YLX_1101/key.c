#include "key.h"

static unsigned char key_last_state[8] = {1,1,1,1,1,1,1,1};
static unsigned char key_current_state[8];

void key_init(void)
{
    // 设置按键引脚为输入
    // TODO: 配置具体引脚
}

void key_scan(void)
{
    // TODO: 实现按键扫描
}

unsigned char key_get_value(void)
{
    return 0;
}