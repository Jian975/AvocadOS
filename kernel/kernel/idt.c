#include <kernel/idt.h>
#include <stdint.h>

void idt_set_gate(uint8_t num, uint32_t offset, uint16_t selector, uint8_t flags) {
     struct IDTEntry * entry = &idt[num];
     idt -> offset_1 = offset & OFFSET_1_MASK;
     idt -> selector = selector;
     idt -> zero = 0;
     idt -> type_attributes = flags;
     idt -> offset_2 = offset & OFFSET_2_MASK;
}

void init_idt() {
     idt_ptr = {
          .size = (sizeof(struct IDTEntry) * 256) - 1;
          .address = &idt;
     }

     //clear out IDT
     memset(&idt, 0, sizeof(struct IDTEntry) * 256);

     idt_flush(&idt);
}
