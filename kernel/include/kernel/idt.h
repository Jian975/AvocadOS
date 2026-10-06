#ifndef _IDT_H
#define _IDT_H

#include <stdint.h>

#define OFFSET_1_MASK 0b1111111111111111
#define OFFSET_2_MASK 0b11111111111111110000000000000000

struct IDTEntry {
   uint16_t offset_1;        // offset bits 0..15
   uint16_t selector;        // a code segment selector in GDT or LDT
   uint8_t  zero;            // unused, set to 0
   uint8_t  type_attributes; // gate type, dpl, and p fields
   uint16_t offset_2;        // offset bits 16..31
};

struct IDT {
     uint16_t size;
     uint32_t address;
} __attribute((packed));

//in asm
extern void idt_flush(struct IDT * idt);

extern void isrs_install();

void idt_set_gate(uint8_t, uint32_t, uint16_t, uint8_t);
void init_idt(void);
#endif
