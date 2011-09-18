#include <cstdio>
#include <cstring>

#define IN getc( stdin )

int c[26];
int main(void){
	register char l = IN, p;
	int down, up;
	while(l != '*'){
		p = 'a';
		memset(c, 0, 104);
		down = up = 0;
		while(l != 10) {
			char k = (l - p + 26) % 26;
			down = down + k;
			++c[k], p = l, l = IN;
		}
		char k = ('a' - p + 26) % 26;
		down = down + k;
		++c[k];
		int ans = 0, d = 25, mindiff = 1 << 15;
		while(down > up){
			while(!c[d]) --d;
			while(c[d] && down > up){
				down = down - d;
				up = up + 26 - d;
				int x = down - up;
				if(x < 0 && x > -mindiff) ans = up;
				if(x >= 0 && x < mindiff) ans = down;
				c[d]--;
			}
		}
		printf("%d\n", ans);
		l = IN;
	}
	return 0;
}

