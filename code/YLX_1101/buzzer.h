#ifndef __BUZZER_H
#define __BUZZER_H

#include "platform.h"

void buzzer_init(void);
void buzzer_on(void);
void buzzer_off(void);
void buzzer_beep(unsigned int ms);

#endif