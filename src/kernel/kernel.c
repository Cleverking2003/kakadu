#include "kconsole.h"
#include "kconvert.h"

void kmain(void) {
	kClearScr();
	enable_cursor(0, SCR_HEIGHT);
	kputs("Kakadu OS booted sucessfully!\n");
	kputs("DEVELOPMENT VERSION!!!\n");
	while(1);
}
