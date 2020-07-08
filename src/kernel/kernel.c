#define SCR_WIDTH 80
#define SCR_HEIGHT 60

int kStrlen(char* str){
    int i;
    for (i = 0; str[i] != '\0'; ++i);
	return i;
}
void kPrintStr(int x, int y, char* string, char attribs){
	int position = y * SCR_WIDTH + x;
	char* vgamode = (char*)0xB8000;
	for(int i = 0; i < position*2; i++) *vgamode++;
	for(int i = 0; i < kStrlen(string); i++){
		*vgamode++ = string[i];
		*vgamode++ = attribs;
	}

}
void kClearScr(){
	for(int w = 0; w < SCR_WIDTH; w++){
		for(int h = 0; h < SCR_HEIGHT; h++){
			kPrintStr(w,h," ",0);
		}
	}
}
void kmain(void)
{
	kClearScr();
	kPrintStr(0,0, "Kakadu OS booted successfully!", 0b00000111);

	while(1);
}
