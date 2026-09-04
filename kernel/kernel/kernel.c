#include <stdio.h>

#include <kernel/tty.h>
#include <kernel/gdt.h>

void kernel_main(void) {
     terminal_initialize();
     init_gdt();
     printf("Hello from AvocadOS!\n");
     printf("I'm on a new line :O\n");
     printf("Wow is that a cursor below me?!?\n");
}
