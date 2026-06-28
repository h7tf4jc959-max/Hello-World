#ifndef __LED_H
#define __LED_H

#include "platform.h"

void led_init(void);
void led_on(unsigned char led);
void led_off(unsigned char led);
void led_toggle(unsigned char led);

#endif