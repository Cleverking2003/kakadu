#define VGA_COLOR(bg, fg) (bg << 4 | fg)

enum vga_colors {
	VGA_BLACK,
	VGA_BLUE,
	VGA_GREEN,
	VGA_CYAN,
	VGA_RED,
	VGA_PURPLE,
	VGA_BROWN,
	VGA_GRAY,
	VGA_DARK_GRAY,
	VGA_LIGHT_BLUE,
	VGA_LIGHT_GREEN,
	VGA_LIGHT_CYAN,
	VGA_LIGHT_RED,
	VGA_LIGHT_PURPLE,
	VGA_YELLOW,
	VGA_WHITE
};

int kStrlen(char* str) {
    int i;
    for (i = 0; str[i] != '\0'; ++i);
	return i;
}

void kPrintStr(int position, char* string, char fg, char bg) {
	char* vgamode = (char*)0xB8000;
	for(int i = 0; i < position*2; i++) *vgamode++;
	for(int i = 0; i < kStrlen(string); i++){
		*vgamode++ = string[i];
		*vgamode++ = VGA_COLOR(bg, fg);

	}
}

void kClearScr() {
	for(int i = 0; i < 132*60; i++){
		kPrintStr(i, " ", VGA_BLACK, VGA_BLACK);
	}
}

void kmain(void) {
	kClearScr();
	kPrintStr(0, "Kakadu OS booted successfully!", VGA_WHITE, VGA_BLACK);

	while(1);
}
