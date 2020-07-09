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

char* strcat(char* s1, const char* s2) {
    int i = strlen(s1), j = 0;
    while (s2[j]) {
        s1[i++] = s2[j++];
    }
    s1[i] = '\0';
    return s1;
}

void strrev(char* str) {
    int i;
	int j;
	unsigned char a;
	unsigned len = strlen(str);
	for (i = 0, j = len - 1; i < j; i++, j--)
	{
		a = str[i];
		str[i] = str[j];
		str[j] = a;
	}
}
