#ifndef __PWM_H
#define __PWM_H

#include "platform.h"

void pwm_init(void);
void pwm1_set_duty(unsigned int duty);
void pwm2_set_duty(unsigned int duty);
void pwm3_set_duty(unsigned int duty);

#endif