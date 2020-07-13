#include "kconsole.h"
#include "kports.h"

//Coords of cursor
char cur_x = 0, cur_y = 0;
// Default color
char def_color = VGA_COLOR(VGA_BLACK, VGA_WHITE);
// Is the cursor enabled?
char cursor_enabled = 0;

// Displays a char
void kputc(char c) {
    if (c == '\0') return;
    if (c == '\n') {
        kputc('\r');
        cur_y++;
    }
    else if (c == '\r') {
        cur_x = 0;
    }
    else if (c == '\b') {
        if (cur_x == 0) {
            cur_x = SCR_WIDTH - 1;
            cur_y--;
        }
        else cur_x--;
        int position = cur_y * SCR_WIDTH + cur_x;
        vgamem[position * 2] = ' ';
        vgamem[position * 2 + 1] = def_color;
    }
    else {
        int position = cur_y * SCR_WIDTH + cur_x++;
        vgamem[position * 2] = c;
        vgamem[position * 2 + 1] = def_color;
    }

    if (cur_x >= SCR_WIDTH) {
        cur_x %= SCR_WIDTH;
        cur_y++;
    }
    if (cur_y >= SCR_HEIGHT) cur_y = 0;
    if(cursor_enabled) update_cursor(cur_x, cur_y);
}

// Displays string
void kputs(char* string){
    for(int i = 0; i < strlen(string); i++){
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

// Enable the cursor
void enable_cursor(char cursor_start, char cursor_end) {
    outb(0x3D4, 0x0A);
    outb(0x3D5, (inb(0x3D5) & 0xC0) | cursor_start);
 
    outb(0x3D4, 0x0B);
    outb(0x3D5, (inb(0x3D5) & 0xE0) | cursor_end);
    cursor_enabled = 1;
}

// Disable the cursor
void disable_cursor(void) {
    outb(0x3D4, 0x0A);
    outb(0x3D5, 0x20);
    cursor_enabled = 0;
}

// Update the cursor
void update_cursor(char x, char y) {
    short pos = y * SCR_WIDTH + x;
    outb(0x3D4, 0x0F);
    outb(0x3D5, (char) (pos & 0xFF));
    outb(0x3D4, 0x0E);
    outb(0x3D5, (char) ((pos >> 8) & 0xFF));
}
