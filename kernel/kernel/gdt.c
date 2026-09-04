#include <kernel/gdt.h>

void set_gdt_entry(GDTEntry * target, uint32_t base, uint32_t limit, uint16_t flag) {
     uint64_t descriptor;

     //Create the high 32 bit segment
     descriptor = limit & 0x000F0000;//set limit bits 19:16
     descriptor |= (flag << 8) & 0x00F0FF00;//set type, p, dpl, s, g, d/b, l, and avl fields
     descriptor |= (base >> 16) & 0x000000FF;//set base bits 23:16
     descriptor |= base & 0xFF000000;//set base bits 31:24

     //Shift by 32 to allow for lower part of segment
     descriptor <<= 32;

     //Create the low 32 bit segment
     descriptor |= base << 16;//set base bits 15:0
     descriptor |= limit & 0x0000FFFF;//set limit bits 15:0

     //write to target
     target -> raw = descriptor;
}

void init_gdt() {
      GDTEntry entries[GDT_ENTRY_COUNT];
      struct GDT gdt = {
         .size = sizeof(entries) - 1,
         .address = (uint32_t) entries,
    };

    set_gdt_entry(&entries[0], 0, 0, 0);
    set_gdt_entry(&entries[1], 0, 0x000FFFFF, (GDT_CODE_PL0));
    set_gdt_entry(&entries[2], 0, 0x000FFFFF, (GDT_DATA_PL0));
    set_gdt_entry(&entries[3], 0, 0x000FFFFF, (GDT_CODE_PL3));
    set_gdt_entry(&entries[4], 0, 0x000FFFFF, (GDT_DATA_PL3));

     gdt_flush(&gdt);
}
