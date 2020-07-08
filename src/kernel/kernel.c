int kStrlen(char* str){
    int i;
    for (i = 0; str[i] != '\0'; ++i);
	return i;
}
void kPrintStr(int position, char* string, char attribs){
	char* vgamode = (char*)0xB8000;
	for(int i = 0; i < position*2; i++) *vgamode++;
	for(int i = 0; i < kStrlen(string); i++){
		*vgamode++ = string[i];
		*vgamode++ = attribs;

	}
}
void kClearScr(){
	for(int i = 0; i < 132*60; i++){
		kPrintStr(i," ",0);
	}
}
void kmain(void)
{
	kClearScr();
	kPrintStr(0, "Kakadu OS booted successfully!", 0b00000111);

	while(1);
}
