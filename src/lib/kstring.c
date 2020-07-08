#include "include/kstring.h"

void strcpy(char *s, char *t) {

    while (*t) {
        *s = *t;
        s++;
        t++;
        }
    *s = *t;
}