#include "platform.h"

void platform_init(void)
{
    // 系统时钟配置
    // TODO: 配置IHRC 16MHz
    
    // 端口初始化
    P5DIR = 0x00;  // P5全部输出
    P6DIR = 0x00;  // P6全部输出
    P7DIR = 0x00;  // P7全部输出
}
