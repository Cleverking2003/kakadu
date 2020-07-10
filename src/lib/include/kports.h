#ifndef KPORTS_H
#define KPORTS_H

static inline char inb(short port) {
    char ret;
    asm volatile ( "inb %1, %0" : "=a"(ret) : "Nd"(port) );
    return ret;
}

static inline void outb(short port, char val) {
    asm volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
}

#endif
