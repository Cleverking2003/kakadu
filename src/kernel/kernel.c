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

volatile char* const vgamode = (volatile char* const)0xB8000;

int kStrlen(char* str) {
    int i;
    for (i = 0; str[i] != '\0'; ++i);
	return i;
}

void kPrintStr(char* string, char x, char y, char fg, char bg) {
	int position = y * 80 + x;
	for(int i = 0; i < kStrlen(string); i++){
		vgamode[(position+i) * 2] = string[i];
		vgamode[(position+i) * 2 + 1] = VGA_COLOR(bg, fg);
	}
}

void kClearScr() {
	for(int i = 0; i < 80*25*2; i++){
		vgamode[i] = 0;
	}
}

void kmain(void) {
	kClearScr();
	kPrintStr("Kakadu OS booted successfully!", 0, 0, VGA_WHITE, VGA_BLACK);

	while(1);
}
