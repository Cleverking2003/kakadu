#include "kports.h"
#include "kconsole.h"
#include "idt.h"

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

    outb(0x21 , 0x00);
    outb(0xA1 , 0x00);

    idt_address = (unsigned long) idt ;
    idt_ptr[0] = (sizeof (struct idt_entry) * 256) + ((idt_address & 0xffff) << 16);
    idt_ptr[1] = idt_address >> 16 ;

    load_idt(idt_ptr);
}
