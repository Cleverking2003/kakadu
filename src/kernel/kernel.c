#include "kconsole.h"
#include "kconvert.h"

void kmain(void) {
	kClearScr();
	init_idt();
	enable_cursor(0, SCR_HEIGHT-1);
	kputs("Kakadu OS booted sucessfully!\n");
	kputs("DEVELOPMENT VERSION!!!\n");
	while(1) ;
}
