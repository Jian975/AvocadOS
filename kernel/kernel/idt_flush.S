.intel_syntax noprefix
.code32

.global idt_flush
.type idt_flush, @function

idt_flush:
     mov        eax, [esp + 4]  #eax = pointer to IDT
     lidt       [eax]           #load IDT to LIDT
     ret

.size idt_flush, .-idt_flush
