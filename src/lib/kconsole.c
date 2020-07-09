#include "include/kconsole.h"

//Coords of cursor
char cur_x = 0, cur_y = 0;

// Displays string
void kDisplayStr(char* string, char fg_color, char bg_color){
	int position;
	for(int i = 0; i < strlen(string); i++){
		if (string[i] == '\n') {
			cur_y++;
			cur_x = 0;
		}
		else {
			position = cur_y * SCR_WIDTH + cur_x++;
			vgamem[position * 2] = string[i];
			vgamem[position * 2 + 1] = VGA_COLOR(bg_color, fg_color);
			if (cur_x >= SCR_WIDTH) {
				cur_x %= SCR_WIDTH;
				cur_y++;
			}
			if (cur_y >= SCR_HEIGHT) cur_y = 0;
		}
	}
}

void kPrintStr(char* string){
	kDisplayStr(string, VGA_WHITE, VGA_BLACK);
}

void kClearScr(void){
	for(int i = 0; i < SCR_WIDTH*SCR_HEIGHT*2; i++){
		vgamem[i] = 0;
	}
	cur_x = 0;
	cur_y = 0;
}
