#include "kconsole.h"
#include "kconvert.h"
#include "gdt.h"

void idt_init(void);

static int test_addr[4] = {0, 1, 2, 3};

void kmain(void) {
    kClearScr();
    enable_cursor(0, SCR_HEIGHT-1);
    paging_init();
    kputs("Paging is initialized\n");
    kputs("DEVELOPMENT VERSION!!!\n");
    gdt_init();
    kputs("GDT is initialized\n");
    idt_init();
    kputs("IDT is initialized\n");
    kputs("Kakadu OS booted sucessfully!\n");
    while(1) ;
}
