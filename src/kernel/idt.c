#include "kports.h"
#include "kconsole.h"

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

void idt_init(void) {
    unsigned long idt_address;
    unsigned long idt_ptr[2];

    IRQ_INSTALL(0)
    IRQ_INSTALL(1)
    IRQ_INSTALL(2)
    IRQ_INSTALL(3)
    IRQ_INSTALL(4)
    IRQ_INSTALL(5)
    IRQ_INSTALL(6)
    IRQ_INSTALL(7)
    IRQ_INSTALL(8)
    IRQ_INSTALL(9)
    IRQ_INSTALL(10)
    IRQ_INSTALL(11)
    IRQ_INSTALL(12)
    IRQ_INSTALL(13)
    IRQ_INSTALL(14)
    IRQ_INSTALL(15)

    outb(0x20 , 0x11);
    outb(0xA0 , 0x11);

    outb(0x21 , 0x20);
    outb(0xA1 , 0x28);

    outb(0x21 , 0x00);
    outb(0xA1 , 0x00);

    outb(0x21 , 0x01);
    outb(0xA1 , 0x01);

    outb(0x21 , 0);
    outb(0xA1 , 0);

    idt_address = (unsigned long) idt ;
    idt_ptr[0] = (sizeof (struct idt_entry) * 256) + ((idt_address & 0xffff) << 16);
    idt_ptr[1] = idt_address >> 16 ;

    load_idt(idt_ptr);
}
