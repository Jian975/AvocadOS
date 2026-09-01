#ifndef _KERNEL_TTY_H
#define _KERNEL_TTY_H

#include <stddef.h>
#include <stdint.h>

//VGA terminal
void terminal_initialize(void);
void terminal_putchar(char c);
void terminal_write(const char * data, size_t size);
void terminal_writestring(const char * data);

//VGA cursor
void enable_cursor(uint8_t cursor_start, uint8_t cursor_end);
void disable_cursor(void);
void update_cursor(int x, int y);
uint16_t get_cursor_position(void);
static inline void outb(uint16_t port, uint8_t value) {
     asm volatile ("outb %0, %1" : : "a"(value), "Nd"(port));
}
static inline uint8_t inb(uint16_t port) {
     uint8_t value;
     asm volatile ("inb %1, %0" : "=a"(value) : "Nd"(port));
     return value;
}

#endif
