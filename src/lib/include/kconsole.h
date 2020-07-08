#ifndef KCONSOLE_H
#define KCONSOLE_H

#define SCR_WIDTH 80
#define SCR_HEIGHT 24

#include "kmemory.h"
#include "kstruct.h"
#include "kconvert.h"
#include "kstring.h"



int kStrlen(char* str);
void kDisplayStr(int x, int y, char* string, char attribs);
void kClearScr(unsigned clearHistory);
void kPrintStr(char* string);
void kPrintHistory();

#endif