#include <kernel/idt.h>
#include <kernel/irq.h>
#include <stdint.h>
#include <string.h>

struct IDTEntry idt[256];
struct IDT idt_ptr;

void idt_set_gate(uint8_t num, uint32_t offset, uint16_t selector, uint8_t flags) {
     struct IDTEntry * entry = &idt[num];
     entry -> offset_1 = offset & OFFSET_1_MASK;
     entry -> selector = selector;
     entry -> zero = 0;
     entry -> type_attributes = flags;
     entry -> offset_2 = (offset & OFFSET_2_MASK) >> 16;
}

void init_idt() {
     idt_ptr.size = (sizeof(struct IDTEntry) * 256) - 1;
     idt_ptr.address = (uint32_t) &idt;

     //clear out IDT
     memset(&idt, 0, sizeof(struct IDTEntry) * 256);

     //add interrupt service routines
     isrs_install();
     irq_install();

     //store to register
     idt_flush(&idt_ptr);
}
