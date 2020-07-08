#include "../lib/include/kconsole.h"
#include "../lib/include/kconvert.h"
#include "../lib/include/kmemory.h"
void kmain(void)
{
	kClearScr(1);
	for(int i = 0; i<3;i++){
		char* n = itoa(i,10);
		kPrintStr(n);
	}

	while(1);
}
