.intel_syntax noprefix
.code32

# 0: Divide by Zero Exception
.global isr0
.type isr0, @function
isr0:
     cli
     push        0  #pops dummy err code to keep uniform stack
     push        0
     jmp        isr_common_stub
.size isr0, .-isr0

# 1: Debug Exception
.global isr1
.type isr1, @function
isr1:
     cli
     push        0
     push        1
     jmp        isr_common_stub
.size isr1, .-isr1

# 2: Non Maskable Interrupt Exception
.global isr2
.type isr2, @function
isr2:
     cli
     push        0
     push        2
     jmp        isr_common_stub
.size isr2, .-isr2

# 3: Breakpoint Exception
.global isr3
.type isr3, @function
isr3:
     cli
     push        0
     push        3
     jmp        isr_common_stub
.size isr3, .-isr3

# 4: Into Detected Overflow Exception
.global isr4
.type isr4, @function
isr4:
     cli
     push        0
     push        4
     jmp        isr_common_stub
.size isr4, .-isr4

# 5: Out of Bounds Exception
.global isr5
.type isr5, @function
isr5:
     cli
     push        0
     push        5
     jmp        isr_common_stub
.size isr5, .-isr5

# 6: Invalid Opcode Exception
.global isr6
.type isr6, @function
isr6:
     cli
     push        0
     push        6
     jmp        isr_common_stub
.size isr6, .-isr6

# 7: No Coprocessor Exception
.global isr7
.type isr7, @function
isr7:
     cli
     push        0
     push        7
     jmp        isr_common_stub
.size isr7, .-isr7

# 8: Double Fault Exception
.global isr8
.type isr8, @function
isr8:
     cli
     push        8
     jmp        isr_common_stub
.size isr8, .-isr8

# 9: Coprocessor Segment Overrun Exception
.global isr9
.type isr9, @function
isr9:
     cli
     push        0
     push        9
     jmp        isr_common_stub
.size isr9, .-isr9

# 10: Bad TSS Exception
.global isr10
.type isr10, @function
isr10:
     cli
     push        10
     jmp        isr_common_stub
.size isr10, .-isr10

# 11: Segment Not Present Exception
.global isr11
.type isr11, @function
isr11:
     cli
     push        11
     jmp        isr_common_stub
.size isr11, .-isr11

# 12: Stack Fault Exception
.global isr12
.type isr12, @function
isr12:
     cli
     push        12
     jmp        isr_common_stub
.size isr12, .-isr12

# 13: General Protection Fault Exception
.global isr13
.type isr13, @function
isr13:
     cli
     push        13
     jmp        isr_common_stub
.size isr13, .-isr13

# 14: Page Fault Exception
.global isr14
.type isr14, @function
isr14:
     cli
     push        14
     jmp        isr_common_stub
.size isr14, .-isr14

# 15: Intel Reserved Exception
.global isr15
.type isr15, @function
isr15:
     cli
     push        0
     push        15
     jmp        isr_common_stub
.size isr15, .-isr15

# 16: Floating Point Error (Math Fault)
.global isr16
.type isr16, @function
isr16:
     cli
     push        0
     push        16
     jmp        isr_common_stub
.size isr16, .-isr16

# 17: Alignment Check Exception
.global isr17
.type isr17, @function
isr17:
     cli
     push        0
     push        17
     jmp        isr_common_stub
.size isr17, .-isr17

# 18: Machine Check 
.global isr18
.type isr18, @function
isr18:
     cli
     push        0
     push        18
     jmp        isr_common_stub
.size isr18, .-isr18

# 19: SIMD Floating-Point Exception
.global isr19
.type isr19, @function
isr19:
     cli
     push        0
     push        19
     jmp        isr_common_stub
.size isr19, .-isr19

# 20: Virtualization Exception
.global isr20
.type isr20, @function
isr20:
     cli
     push        0
     push        20
     jmp        isr_common_stub
.size isr20, .-isr20

# 21: Control Protection Exception
.global isr21
.type isr21, @function
isr21:
     cli
     push        21
     jmp        isr_common_stub
.size isr21, .-isr21

# 22-31: Reserved for future use
.global isr22
.type isr22, @function
isr22:
     cli
     push        0
     push        22
     jmp        isr_common_stub
.size isr22, .-isr22

.global isr23
.type isr23, @function
isr23:
     cli
     push        0
     push        23
     jmp        isr_common_stub
.size isr23, .-isr23

.global isr24
.type isr24, @function
isr24:
     cli
     push        0
     push        24
     jmp        isr_common_stub
.size isr24, .-isr24

.global isr25
.type isr25, @function
isr25:
     cli
     push        0
     push        25
     jmp        isr_common_stub
.size isr25, .-isr25

.global isr26
.type isr26, @function
isr26:
     cli
     push        0
     push        26
     jmp        isr_common_stub
.size isr26, .-isr26

.global isr27
.type isr27, @function
isr27:
     cli
     push        0
     push        27
     jmp        isr_common_stub
.size isr27, .-isr27

.global isr28
.type isr28, @function
isr28:
     cli
     push        0
     push        28
     jmp        isr_common_stub
.size isr28, .-isr28

.global isr29
.type isr29, @function
isr29:
     cli
     push        0
     push        29
     jmp        isr_common_stub
.size isr29, .-isr29

.global isr30
.type isr30, @function
isr30:
     cli
     push        0
     push        30
     jmp        isr_common_stub
.size isr30, .-isr30

.global isr31
.type isr31, @function
isr31:
     cli
     push       0
     push       31
     jmp        isr_common_stub
.size isr31, .-isr31

# 32: IRQ0
.global irq0
.type irq0, @function
irq0:
     push       0
     push       32
     jmp        irq_common_stub
.size irq0, .-irq0

# 33: IRQ1
.global irq1
.type irq1, @function
irq1:
     push       0
     push       33
     jmp        irq_common_stub
.size irq1, .-irq1

# 34: IRQ2
.global irq2
.type irq2, @function
irq2:
     push       0
     push       34
     jmp        irq_common_stub
.size irq2, .-irq2

# 35: IRQ3
.global irq3
.type irq3, @function
irq3:
     push       0
     push       35
     jmp        irq_common_stub
.size irq3, .-irq3

# 36: IRQ4
.global irq4
.type irq4, @function
irq4:
     push       0
     push       36
     jmp        irq_common_stub
.size irq4, .-irq4

# 37: IRQ5
.global irq5
.type irq5, @function
irq5:
     push       0
     push       37
     jmp        irq_common_stub
.size irq5, .-irq5

# 38: IRQ6
.global irq6
.type irq6, @function
irq6:
     push       0
     push       38
     jmp        irq_common_stub
.size irq6, .-irq6

# 39: IRQ7
.global irq7
.type irq7, @function
irq7:
     push       0
     push       39
     jmp        irq_common_stub
.size irq7, .-irq7

# 40: IRQ8
.global irq8
.type irq8, @function
irq8:
     push       0
     push       40
     jmp        irq_common_stub
.size irq8, .-irq8

# 41: IRQ9
.global irq9
.type irq9, @function
irq9:
     push       0
     push       41
     jmp        irq_common_stub
.size irq9, .-irq9

# 42: IRQ10
.global irq10
.type irq10, @function
irq10:
     push       0
     push       42
     jmp        irq_common_stub
.size irq10, .-irq10

# 43: IRQ11
.global irq11
.type irq11, @function
irq11:
     push       0
     push       43
     jmp        irq_common_stub
.size irq11, .-irq11

# 44: IRQ12
.global irq12
.type irq12, @function
irq12:
     push       0
     push       44
     jmp        irq_common_stub
.size irq12, .-irq12

# 45: IRQ13
.global irq13
.type irq13, @function
irq13:
     push       0
     push       45
     jmp        irq_common_stub
.size irq13, .-irq13

# 46: IRQ14
.global irq14
.type irq14, @function
irq14:
     push       0
     push       46
     jmp        irq_common_stub
.size irq14, .-irq14

# 47: IRQ15
.global irq15
.type irq15, @function
irq15:
     push       0
     push       47
     jmp        irq_common_stub
.size irq15, .-irq15

.global isr_common_stub
.type isr_common_stub, @function
isr_common_stub:
     pusha
     push       ds
     push       es
     push       fs
     push       gs
     mov        ax, 0x10        # Load the kernel data segment descriptor
     mov        ds, ax
     mov        es, ax
     mov        fs, ax
     mov        gs, ax
     mov        eax, esp
     push       eax
     call       fault_handler      # in C file
     pop        eax
     pop        gs
     pop        fs
     pop        es
     pop        ds
     popa
     add        esp, 8
     iret
.size isr_common_stub, .-isr_common_stub

.global irq_common_stub
.type irq_common_stub, @function
irq_common_stub:
     pusha
     push       ds
     push       es
     push       fs
     push       gs
     mov        ax, 0x10        # Load the kernel data segment descriptor
     mov        ds, ax
     mov        es, ax
     mov        fs, ax
     mov        gs, ax
     mov        eax, esp
     push       eax
     call       irq_handler      # in C file
     pop        eax
     pop        gs
     pop        fs
     pop        es
     pop        ds
     popa
     add        esp, 8
     sti
     iret
.size irq_common_stub, .-irq_common_stub
