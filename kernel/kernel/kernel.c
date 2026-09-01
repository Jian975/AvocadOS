#include <stdio.h>

#include <kernel/tty.h>

void kernel_main(void) {
     terminal_initialize();
     printf("Hello from AvocadOS!\n");
     printf("I'm on a new line :O\n");
}
