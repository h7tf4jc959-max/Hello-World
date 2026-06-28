#ifndef __TIMER_H
#define __TIMER_H

#include "platform.h"

void timer_init(void);
void timer0_init(void);
void timer0_start(void);
void timer0_stop(void);
void timer0_reload(unsigned int value);

#endif