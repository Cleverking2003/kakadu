#include "kconvert.h"
#include "kmath.h"
#include "kstring.h"

char* itoa(int val, unsigned int base){
	char isNeg = 0;
	if (base > 16 || val == 0) return "0";
	if (val < 0) {
		isNeg = 1;
		val = abs(val);
	}
	static char* str;
	int i = 0;
	while(val) {
		str[i++] = "0123456789ABCDEF"[val % base];
		val /= base;
	}
	if(isNeg) str[i++] = '-';
	str[i] = '\0';
	strrev(str);
	return str;
}
