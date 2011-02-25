#include <cstdio>

int c[128][2];
char s[1024], t[1024];
int main(void){
	while(scanf("%s %s", s, t) == 2){
		for(int i = 'a'; i <= 'z'; ++i) c[i][0] = c[i][1] = 0;
		for(char *p = s; *p; ) ++c[*p++][0];
		for(char *p = t; *p; ) ++c[*p++][1];
		for(int i = 'a'; i <= 'z'; ++i)
			for(int &c0 = c[i][0], &c1 = c[i][1]; c0-- && c1--; )
				putc(i, stdout);
		puts("");
	}
	return 0;
}

