#ifndef IDT_H
#define IDT_H

#define IRQ_INSTALL(n) \
        unsigned long irq##n##_addr = (unsigned long) irq##n; \
        idt[0x20 + n].offset_lowerbits = irq##n##_addr & 0xffff; \
        idt[0x20 + n].offset_higherbits = (irq##n##_addr >> 16) & 0xffff; \
        idt[0x20 + n].zero = 0; \
        idt[0x20 + n].selector = 8; \
        idt[0x20 + n].type_attr = 0x8e; \

struct idt_entry{
    unsigned short offset_lowerbits;
    unsigned short selector;
    unsigned char zero;
    unsigned char type_attr;
    unsigned short offset_higherbits;
};
 
static struct idt_entry idt[256];

void idt_init(void);
extern void irq0(void);
extern void irq1(void);
extern void irq2(void);
extern void irq3(void);
extern void irq4(void);
extern void irq5(void);
extern void irq6(void);
extern void irq7(void);
extern void irq8(void);
extern void irq9(void);
extern void irq10(void);
extern void irq11(void);
extern void irq12(void);
extern void irq13(void);
extern void irq14(void);
extern void irq15(void);
extern void load_idt(unsigned long* ptr);

#endif
