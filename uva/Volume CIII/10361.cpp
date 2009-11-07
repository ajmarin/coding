#include <cstdio>

char r[4][100], *s[4];
char m[4] = {2, 1, 0, 3};

int main(void){
	register char c;
	int i, T;
	scanf("%d\n",&T);
	while(T--){
		for(i = 0; i < 4; i++) s[i] = r[i];
		while((c = getc( stdin )) != '<') putc(c, stdout);
		while((c = getc( stdin )) != '>') *s[0]++ = c, putc(c, stdout);
		while((c = getc( stdin )) != '<') *s[1]++ = c, putc(c, stdout);
		while((c = getc( stdin )) != '>') *s[2]++ = c, putc(c, stdout);
		while((c = getc( stdin )) != '\n')*s[3]++ = c, putc(c, stdout);
		putc(10, stdout);
		while((c = getc( stdin )) != '.') putc(c, stdout);
		while(getc( stdin ) != '\n');
		*s[0] = *s[1] = *s[2] = *s[3] = 0;
		for(i = 0; i < 4; i++){
			c = m[i];
			s[c] = r[c];
			while(*s[c]) putc(*s[c]++, stdout);
		}
		putc(10, stdout);
	}
	return 0;
}

