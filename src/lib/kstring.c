#include "include/kstring.h"

void strcpy(char *s, char *t) {
    while (*t) {
        *s++ = *t++;
    }
    *s = *t;
}

int strlen(char* str){
    int i;
    for (i = 0; str[i] != '\0'; ++i);
	return i;
}
