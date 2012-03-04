#include <cstdio>
char w[128];
char lower(char x){ return x + ((x >= 'A' && x <= 'Z') << 5); }
char upper(char x){ return x - ((x >= 'a' && x <= 'z') << 5); }
int main(void){
	int l = 0, u = 0;
	while(1){
		char c = w[u + l] = getc(stdin);
		if(!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) break;
		l += c >= 'a' && c <= 'z';
		u += c >= 'A' && c <= 'Z';
	}
	w[u + l] = 0;
	for(char *p = w; *p; ++p) putc(u > l ? upper(*p) : lower(*p), stdout);
	putc(10, stdout);
	return 0;
}
