#ifndef _TIMER_H
#define _TIMER_H

#include <kernel/common_low.h>

void timer_phase(int);
void timer_handler(struct regs *);
void timer_install();
#endif
