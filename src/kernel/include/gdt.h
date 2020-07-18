#ifndef GDT_H
#define GDT_H

static unsigned int tss[0x64];

struct gdt_entry{
    unsigned int base;
    unsigned int limit;
    unsigned char type;
};

typedef struct gdt_entry gdt_entry;

static gdt_entry gdt[4];
static char gdt_encoded[4*8];

void gdt_init(void);
void encodeGdtEntry(unsigned char *target, gdt_entry source);
extern void load_gdt(char* gdt, unsigned short size);

#endif
