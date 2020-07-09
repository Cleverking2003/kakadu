#ifndef KCONSOLE_H
#define KCONSOLE_H

#define SCR_WIDTH 80
#define SCR_HEIGHT 24

#include "kmemory.h"
#include "kstruct.h"
#include "kconvert.h"
#include "kstring.h"

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

static volatile char* const vgamem = (volatile char* const)0xb8000;

void kDisplayStr(char* string, char fg_color, char bg_color);
void kClearScr(void);
void kPrintStr(char* string);

#endif