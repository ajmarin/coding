#include <cstdio>

#define IN getc( stdin )

char map[128];
int main(void){
	int n, o;
	map['E'] = 8; map['H'] = 32; map['Q'] = 16;
	map['S'] = 4; map['T'] = 2; map['W'] = 64;
	map['X'] = 1;
	register char c;
	while(IN != '*'){
		c = IN;
		o = 0;
		while(c != 10){
			n = 0;
			while(c != '/') n += *(map + c), c = IN;
			o += (n == 64);
			c = IN;
		}
		printf("%d\n", o);
	}
	return 0;
}

