#include <cstdio>
#define FORI(a,b,c)	for(int a = b; a < c; ++a)
#define FOR(a,b)	FORI(a,0,b)

int w[128][128];
int min(int x, int y){ return x < y ? x : y; }
int max(int x, int y){ return x > y ? x : y; }
int main(void){
	for(int cs = 0, m, n, q; scanf("%d %d %d", &n, &m, &q) && (n || m || q); ){
		int a, b, c;
		FOR(i, n) FOR(j, n) w[i][j] = 0x3fffffff;
		FOR(i, m){
			scanf("%d %d %d", &a, &b, &c);
			if(c < w[--a][--b]) w[a][b] = w[b][a] = c;
		}
		FOR(k, n) FOR(i, n) FOR(j, n)
			w[i][j] = min(w[i][j], max(w[i][k], w[k][j]));
		if(cs) putc(10, stdout);
		printf("Case #%d\n", ++cs);
		FOR(i, q){
			scanf("%d %d", &a, &b);
			if(w[--a][--b] != 0x3fffffff) printf("%d\n", w[a][b]);
			else puts("no path");
		}
	}
	return 0;
}

