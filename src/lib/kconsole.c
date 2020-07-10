#include "kconsole.h"

//Coords of cursor
char cur_x = 0, cur_y = 0;
// Default color
char def_color = VGA_COLOR(VGA_BLACK, VGA_WHITE);

// Displays a char
void kputc(char c) {
	if (c == '\n') {
		cur_y++;
	}
	else if (c == '\r') {
		cur_x = 0;
	}
	else {
		int position = cur_y * SCR_WIDTH + cur_x++;
		vgamem[position * 2] = c;
		vgamem[position * 2 + 1] = def_color;
		if (cur_x >= SCR_WIDTH) {
			cur_x %= SCR_WIDTH;
			cur_y++;
		}
		if (cur_y >= SCR_HEIGHT) cur_y = 0;
	}
}

// Displays string
void kputs(char* string){
	for(int i = 0; i < strlen(string); i++){
		if (string[i] == '\n') {
			kputc('\r');
		}
		kputc(string[i]);
	}
}

// Clear the screen
void kClearScr(void){
	for(int i = 0; i < SCR_WIDTH*SCR_HEIGHT*2; i++){
		vgamem[i] = 0;
	}
	cur_x = 0;
	cur_y = 0;
	char def_color = VGA_COLOR(VGA_BLACK, VGA_WHITE);
}

// Set the color
void set_color(char fg, char bg) {
	def_color = VGA_COLOR(bg, fg);
}
