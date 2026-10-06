#include <kernel/io.h>
#include <kernel/timer.h>
#include <kernel/isr.h>
#include <kernel/irq.h>
#include <stdio.h>

int timer_ticks = 0;

void timer_phase(int hz) {
     int divisor = 1193180 / hz;
     outb(0x43, 0x36);//set our command byte 0x36
     outb(0x40, divisor & 0xFF);//set low byte of divisor
     outb(0x40, divisor >> 8);//set high byte of divisor
}

//Increment timer_ticks every time the timer fires
//Timer fires 18.222 times per second
void timer_handler(struct regs * r) {
     if (r -> int_no == 32) {
          printf("IRQ: 32\n");
     } else {
          printf("IRQ: not 32\n");
     }
     
     timer_ticks++;
     //Display a message approximately every second
     if (timer_ticks % 18 == 0) {
          int seconds = timer_ticks / 18;
          printf("One second has passed, timer=%ds\n", seconds);
     }
     printf("Tick\n");
}

void timer_install() {
     timer_phase(18);
     irq_install_handler(0, timer_handler);
}
