#include <stdio.h>

#include <kernel/tty.h>
#include <kernel/gdt.h>
#include <kernel/idt.h>
#include <kernel/keyboard.h>

void init_tables() {
     init_gdt();
     printf("GDT Initialized\n");
     init_idt();
     printf("IDT Initialized\n");

}

void kernel_main(void) {
     terminal_initialize();
     init_tables();
     keyboard_install();
     printf("Hello from AvocadOS!\n");
     //printf("Triggering divide-by-zero exception...\n");
     //asm volatile ("divl %0" : : "r"(0U) : "eax", "edx", "cc");
     //keep the kernel running
     for (;;)
          asm volatile ("sti; hlt" ::: "memory");
}
