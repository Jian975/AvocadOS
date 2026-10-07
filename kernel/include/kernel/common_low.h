#ifndef _COMMON_LOW_H
#define _COMMON_LOW_H

//What the stack looks like after an ISR was running
struct regs {
     unsigned int gs, fs, es, ds;//Pushed the segs last
     unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax;//pushed by pusha
     unsigned int int_no, err_code;//'push byte #' and encodes do this
     unsigned int eip, cs, eflags, useresp, ss;//Pushed by the processor automatically
};

#endif
