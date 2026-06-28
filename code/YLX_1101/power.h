#ifndef __POWER_H
#define __POWER_H

#include "platform.h"

void power_init(void);
void power_manage(void);
void power_sleep(void);
void power_wakeup(void);

#endif