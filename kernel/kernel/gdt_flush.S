.intel_syntax noprefix
.code32

.global gdt_flush
.type gdt_flush, @function

gdt_flush:
     mov        eax, [esp + 4]  #eax = pointer to GDT
     lgdt       [eax]           #load GDT into LGDT

     mov        ax, 0x10        #kernel data segment selector

     mov        ds, ax
     mov        es, ax
     mov        fs, ax
     mov        gs, ax
     mov        ss, ax

     jmp        0x08, .flush    #reload CS with kernel code selector

.flush:
     ret

.size gdt_flush, .-gdt_flush
