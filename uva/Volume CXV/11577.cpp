#include <cstdio>

int f[128];
char text[256];

bool lower(char c){ return c >= 'a' && c <= 'z'; }
bool upper(char c){ return c >= 'A' && c <= 'Z'; }

int main(void){
	int t; scanf("%d", &t); gets(text);
	while(t--){
		int mf = 0;
		for(int i = 'a'; i <= 'z'; ++i) f[i] = 0;
		gets(text);
		for(char *p = text; *p; ++p) if(lower(*p) || upper(*p)){
			*p += upper(*p) << 5;
			if(++f[*p] > mf) mf = f[*p];
		}
		for(int i = 'a'; i <= 'z'; ++i) if(f[i] == mf) putc(i, stdout);
		puts("");
	}
	return 0;
}

