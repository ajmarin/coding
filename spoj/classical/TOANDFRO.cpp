#include <cstdio>
int main(void){
	char s[256];
	for(int c; scanf("%d", &c) && c; ){
		int l, t = c << 1;
		scanf("%s", s);
		for(l = -1; s[++l]; );
		for(int i = 0; i < c; ++i){
			int j = 1 + (i << 1);
			for(int p = i; p < l; p += j = t - j)
				putc(s[p], stdout);
		}
		puts("");
	}
	return 0;	
}
