#include <cstdio>

#define IN getc ( stdin )
#define OUT(x) putc(x, stdout)
#define FORI(a,b,c) for(int a = b; a < c; ++a)
#define FOR(a,b) FORI(a,0,b)
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define ONES(x) __builtin_popcount(x)

const int C = 15, R = 15;
int p2[32];
char m[R][C];
int main(void){
	register char c;
	p2[0] = 1;
	FORI(i, 1, 16) p2[i] = p2[i-1]<<1;
	while((c = IN) != 'E'){
		int ans = 16, __MMAX = 1<<15;
		ungetc(c, stdin);
		char *p = *m;
		FOR(i, R) {
			FOR(j, C) *p++ = IN;
			IN;
		} 
		FOR(mask, __MMAX){
			int om = ONES(mask);
			if(om >= ans) continue;
			int cc = 0;
			FOR(i, R) if(!(p2[i] & mask))
				FOR(j, C) cc |= (p2[j] * (m[i][j] == '#')); 
			ans = MIN(ans, MAX(ONES(cc), om));
		}
		printf("%d\n",ans);
	}
	return 0;
}

