#include <kernel/keyboard.h>
#include <kernel/irq.h>
#include <kernel/io.h>
#include <stdio.h>

#define KEYBOARD_CONTROLLER_STATUS_PORT 0x64
#define KEYBOARD_CONTROLLER_DATA_PORT 0x60
#define PIC_MASTER_DATA_PORT 0x21
#define DISABLE_KEYBOARD_CONTROLLER 0xAD
#define ENABLE_KEYBOARD_CONTROLLER 0xAE
#define KEYBOARD_CONTROLLER_READ_COMMAND 0x20
#define KEYBOARD_CONTROLLER_WRITE_COMMAND 0x60
#define KEYBOARD_CONTROLLER_ENABLE_SCANNING 0xF4
#define KEYBOARD_CONTROLLER_ACKNOALEDGE 0xFA

static int wait_input_buffer_clear(void) {
  for (unsigned int timeout = 0; timeout < 100000; timeout++) {
    if (!(inb(KEYBOARD_CONTROLLER_STATUS_PORT) & 0x02))
      return 1;
  }
  return 0;
}

static int wait_output_buffer_full(void) {
  for (unsigned int timeout = 0; timeout < 100000; timeout++) {
    if (inb(KEYBOARD_CONTROLLER_STATUS_PORT) & 0x01)
      return 1;
  }
  return 0;
}

static int keyboard_controller_enable_irq(void) {
  if (!wait_input_buffer_clear())
    return 0;
  outb(KEYBOARD_CONTROLLER_STATUS_PORT, DISABLE_KEYBOARD_CONTROLLER);

  for (unsigned int timeout = 0; timeout < 100000; timeout++) {
    if (!(inb(KEYBOARD_CONTROLLER_STATUS_PORT) & 0x01))
      break;
    inb(KEYBOARD_CONTROLLER_DATA_PORT);
  }

  if (!wait_input_buffer_clear())
    return 0;
  outb(KEYBOARD_CONTROLLER_STATUS_PORT, KEYBOARD_CONTROLLER_READ_COMMAND);
  if (!wait_output_buffer_full())
    return 0;

  unsigned char command_byte = inb(KEYBOARD_CONTROLLER_DATA_PORT);
  command_byte |= 0x40;// Set bit 6, enable scan-code translation
  command_byte &= ~0x11;// Clear bits 0 and 4, disable keyboard IRQ generation and clears keyboard interface disabled flag

  if (!wait_input_buffer_clear())
    return 0;
  outb(KEYBOARD_CONTROLLER_STATUS_PORT, KEYBOARD_CONTROLLER_WRITE_COMMAND);
  if (!wait_input_buffer_clear())
    return 0;
  outb(KEYBOARD_CONTROLLER_DATA_PORT, command_byte);
  if (!wait_input_buffer_clear())
    return 0;
  outb(KEYBOARD_CONTROLLER_STATUS_PORT, ENABLE_KEYBOARD_CONTROLLER);

  if (!wait_input_buffer_clear())
    return 0;
  outb(KEYBOARD_CONTROLLER_DATA_PORT, KEYBOARD_CONTROLLER_ENABLE_SCANNING);
  if (!wait_output_buffer_full())
    return 0;
  if (inb(KEYBOARD_CONTROLLER_DATA_PORT) != KEYBOARD_CONTROLLER_ACKNOALEDGE)
    return 0;

  command_byte |= 0x01;
  if (!wait_input_buffer_clear())
    return 0;
  outb(KEYBOARD_CONTROLLER_STATUS_PORT, KEYBOARD_CONTROLLER_WRITE_COMMAND);
  if (!wait_input_buffer_clear())
    return 0;
  outb(KEYBOARD_CONTROLLER_DATA_PORT, command_byte);
  return 1;
}

//US keyboard, scan code -> char
unsigned char kbdus[128] =
{
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8',	/* 9 */
  '9', '0', '-', '=', '\b',	/* Backspace */
  '\t',			/* Tab */
  'q', 'w', 'e', 'r',	/* 19 */
  't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',	/* Enter key */
    0,			/* 29   - Control */
  'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',	/* 39 */
 '\'', '`',   0,		/* Left shift */
 '\\', 'z', 'x', 'c', 'v', 'b', 'n',			/* 49 */
  'm', ',', '.', '/',   0,				/* Right shift */
  '*',
    0,	/* Alt */
  ' ',	/* Space bar */
    0,	/* Caps lock */
    0,	/* 59 - F1 key ... > */
    0,   0,   0,   0,   0,   0,   0,   0,
    0,	/* < ... F10 */
    0,	/* 69 - Num lock*/
    0,	/* Scroll Lock */
    0,	/* Home key */
    0,	/* Up Arrow */
    0,	/* Page Up */
  '-',
    0,	/* Left Arrow */
    0,
    0,	/* Right Arrow */
  '+',
    0,	/* 79 - End key*/
    0,	/* Down Arrow */
    0,	/* Page Down */
    0,	/* Insert Key */
    0,	/* Delete Key */
    0,   0,   0,
    0,	/* F11 Key */
    0,	/* F12 Key */
    0,	/* All other keys are undefined */
};

void keyboard_handler(struct regs * r) {
     unsigned char scancode = inb(KEYBOARD_CONTROLLER_DATA_PORT);
  if (!(scancode & 0x80) && scancode < sizeof(kbdus) && kbdus[scancode])
    putchar(kbdus[scancode]);
}

void keyboard_install() {
     irq_install_handler(1, keyboard_handler);
  if (keyboard_controller_enable_irq()) {
      outb(PIC_MASTER_DATA_PORT, 0xFD);//unmask IRQ1 (keyboard)
    printf("Keyboard ready\n");
  } else {
    printf("Keyboard init failed\n");
  }
}
