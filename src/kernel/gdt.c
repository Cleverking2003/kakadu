#include "gdt.h"
#include "kconsole.h"

void gdt_init(void) {
    gdt_entry null = {.base = 0, .limit = 0, .type = 0};
    gdt_entry code = {.base=0, .limit=0xffffffff, .type=0x9A};
    gdt_entry data = {.base=0, .limit=0xffffffff, .type=0x92};
    gdt_entry tss_seg = {.base=tss, .limit=sizeof(tss), .type=0x89};
    gdt[0] = null;
    gdt[1] = code;
    gdt[2] = data;
    gdt[3] = tss_seg;
    for (int i = 0; i < 4; i++) {
        encodeGdtEntry(&gdt_encoded[i*8], gdt[i]);
    }
    load_gdt(gdt_encoded, sizeof(gdt_encoded));
}

void encodeGdtEntry(unsigned char *target, gdt_entry source) {
    // Check the limit to make sure that it can be encoded
    if ((source.limit > 65536) && ((source.limit & 0xFFF) != 0xFFF)) {
        kputs("You can't do that!\n");
    }
    if (source.limit > 65536) {
        // Adjust granularity if required
        source.limit = source.limit >> 12;
        target[6] = 0xC0;
    } else {
        target[6] = 0x40;
    }
 
    // Encode the limit
    target[0] = source.limit & 0xFF;
    target[1] = (source.limit >> 8) & 0xFF;
    target[6] |= (source.limit >> 16) & 0xF;
 
    // Encode the base 
    target[2] = source.base & 0xFF;
    target[3] = (source.base >> 8) & 0xFF;
    target[4] = (source.base >> 16) & 0xFF;
    target[7] = (source.base >> 24) & 0xFF;
 
    // And... Type
    target[5] = source.type;
}
