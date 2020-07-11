#include "kconsole.h"
#include "kports.h"

void irq0_handler(void) {
    outb(0x20, 0x20);
}

void irq1_handler(void) {
    outb(0x20, 0x20);
    kputs("key pressed\n");
}

void irq2_handler(void) {
    outb(0x20, 0x20);
}

void irq3_handler(void) {
    outb(0x20, 0x20);
}

void irq4_handler(void) {
    outb(0x20, 0x20);
}

void irq5_handler(void) {
    outb(0x20, 0x20);
}

void irq6_handler(void) {
    outb(0x20, 0x20);
}

void irq7_handler(void) {
    outb(0x20, 0x20);
}

void irq8_handler(void) {
    outb(0x20, 0x20);
}

void irq9_handler(void) {
    outb(0x20, 0x20);
}

void irq10_handler(void) {
    outb(0x20, 0x20);
}

void irq11_handler(void) {
    outb(0x20, 0x20);
}

void irq12_handler(void) {
    outb(0x20, 0x20);
}

void irq13_handler(void) {
    outb(0x20, 0x20);
}

void irq14_handler(void) {
    outb(0x20, 0x20);
}

void irq15_handler(void) {
    outb(0x20, 0x20);
}
