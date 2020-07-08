#include "include/kconsole.h"
// Console history
KLinkedList* history;
unsigned historyInitialized = 0;

int kStrlen(char* str){
    int i;
    for (i = 0; str[i] != '\0'; ++i);
	return i;
}
// Displays string
void kDisplayStr(int x, int y, char* string, char attribs){
	int position = y * SCR_WIDTH + x;
	char* vgamode = (char*)0xB8000;
	for(int i = 0; i < position*2; i++) vgamode++;
	for(int i = 0; i < kStrlen(string); i++){
		*vgamode++ = string[i];
		*vgamode++ = attribs;
	}

}
void kPrintStr(char* string){
	if(!historyInitialized){
		history = KLinkedList_Create();
		historyInitialized = 1;
	}

	KLinkedList_Append(history, string);
	
	kClearScr(0);
	for(int i = 0; i < KLinkedList_Length(history); i++) {
		char* toWrite = (char*)KLinkedList_At(history,i);
		kDisplayStr(0,i,toWrite,0b00000111);
	}


}

// Clears screen visually (without history)
void kClearScr(unsigned clearHistory){
	for(int w = 0; w < SCR_WIDTH; w++){
		for(int h = 0; h < SCR_HEIGHT; h++){
			kDisplayStr(w,h," ",0);
		}
	}
	if(clearHistory) KLinkedList_Clear(history);
}
