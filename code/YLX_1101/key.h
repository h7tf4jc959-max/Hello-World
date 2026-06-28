#ifndef __KEY_H
#define __KEY_H

#include "platform.h"

void key_init(void);
void key_scan(void);
unsigned char key_get_value(void);

#endif