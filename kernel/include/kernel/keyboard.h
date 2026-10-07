#ifndef _KEYBOARD_H
#define _KEYBOARD_H

#include <kernel/common_low.h>

void keyboard_handler(struct regs *);

void keyboard_install();

#endif
