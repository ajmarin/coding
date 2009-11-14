#include <cctype>
#include <cstdio>

#define IN getc( stdin )

void fastint( register int *n ){
	register char c = IN;
	*n = 0;
	while(!isdigit(c)) c = IN;
	while(isdigit(c)) (*n) = (*n) * 10 + (c - '0'), c = IN;
}

struct CALL { int e, s; } c[10000];

int main(void){
	int a, b, m, n;
	while(scanf("%d %d", &n, &m) && n){
		for(int i = 0; i < n; ++i){
			fastint(&a), fastint(&b);
			fastint(&c[i].s), fastint(&c[i].e);
			c[i].e += c[i].s;
		}
		for(int i = 0; i < m; ++i){
			fastint(&a), fastint(&b);
			b += a;
			int ans = 0;
			for(int j = 0; j < n; ++j) ans += (a < c[j].e && b > c[j].s);
			printf("%d\n", ans);
		}
	}
	return 0;
}

