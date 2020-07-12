#include "kconsole.h"
#include "kports.h"

#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64

unsigned char keyboard_map[128] =
{
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8',	
  '9', '0', '-', '=', '\b',	
  '\t',			
  'q', 'w', 'e', 'r',	
  't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',	
    0,			
  'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',	
 '\'', '`',   0,		
 '\\', 'z', 'x', 'c', 'v', 'b', 'n',			
  'm', ',', '.', '/',   0,				
  '*',
    0,	/* Alt */
  ' ',	/* Space bar */
    0,	/* Caps lock */
    0,	/* 59 - F1  ... > */
    0,   0,   0,   0,   0,   0,   0,   0,
    0,	/* < ... F10 */
    0,	/* 69 - Num lock*/
    0,	/* Scroll Lock */
    0,	/* Home  */
    0,	/* Up Arrow */
    0,	/* Page Up */
  '-',
    0,	/* Left Arrow */
    0,
    0,	/* Right Arrow */
  '+',
    0,	/* 79 - End */
    0,	/* Down Arrow */
    0,	/* Page Down */
    0,	/* Insert  */
    0,	/* Delete  */
    0,   0,   0,
    0,	/* F11  */
    0,	/* F12 */
    0,	
};

void irq0_handler(void) {
    outb(0x20, 0x20);
}

void irq1_handler(void) {
    unsigned char status;
	char keycode;

	outb(0x20, 0x20);

	status = inb(KEYBOARD_STATUS_PORT);
	if (status & 0x01) {
		keycode = inb(KEYBOARD_DATA_PORT);
		if(keycode < 0)
			return;

		if(keycode == 0x1c) {
			kputc('\n');
			return;
		}

		kputc(keyboard_map[(unsigned char) keycode]);
	}
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
