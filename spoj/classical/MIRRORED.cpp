#include <cstdio>

int f[128];
char s[16];
int main(void){
	for(int i = 0; i < 128; ++i) f[i] = 0;
	f['p'] = f['q'] = 1;
	f['b'] = f['d'] = 2;
	puts("Ready");
	while(fgets(s, 16, stdin) && (*s != ' ' || *(s+1) != ' '))
		puts(f[*s] && f[*s] == f[*(s+1)] ? "Mirrored pair" : "Ordinary pair");
	return 0;
}

