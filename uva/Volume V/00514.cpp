#include <cctype>
#include <cstdio>

#define IN getc( stdin )
const char *ans[2] = {"Yes","No"};
void fastint( register int *n ){
	register char c;
	*n = 0;
	while(!isdigit(c = IN));
	do { (*n) = (*n) * 10 + c - '0'; c = IN; } while(isdigit(c));
}
int i, s[1000], st, v[1000], vp, N;
int main(void){
	while(1){
		fastint(&N); if(!N) break;
		while(1){
			fastint(&v[0]); if(!v[0]) break;
			for(i = 1; i < N; ++i) fastint(&v[i]);
			for(vp = 0, i = 1, st = -1; i <= N; ++i){
				s[++st] = i;
				while(st != -1 && s[st] == v[vp]) st--, vp++;
			}
			puts(ans[ st != -1 ]);
		}
		putc( 10, stdout );
	}
	return 0;
}

