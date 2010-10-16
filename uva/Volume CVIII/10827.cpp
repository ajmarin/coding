#include <cstdio>
#define FOR(a,b)	for(int a = 0; a < b; ++a)
#define FORD(a,b,c)	for(int a = b; a > c; --a)
#define FORI(a,b,c)	for(int a = b; a < c; ++a)
int m[256][256];
int min(int x, int y){ return x < y ? x : y; }
int max(int x, int y){ return x > y ? x : y; }
int main(void){
	int t; scanf("%d", &t);
	FOR(i, 256) m[0][i] = 0;
	for(int l, maxsum, n; t-- && scanf("%d", &n) == 1; ){
		l = (n << 1) + 1; maxsum = 0;
		FORI(i, 1, n + 1) FOR(j, n){
			scanf("%d", &m[i][j]);
			m[i + n][j] = m[i][j];
			m[i][j] += m[i - 1][j];
		}
		FORI(i, n + 1, l) FOR(j, n) m[i][j] += m[i - 1][j];
		FORI(i, 1, l) FORI(j, i, min(i + n, l)){
			int lmin = 0, lmax = 0, s1 = 0, s2 = 0, total = 0, x = 0;
			FOR(k, n){
				x = m[j][k] - m[i - 1][k];
				s1 += x; s2 += x; total += x;
				lmax = max(s1, lmax);
				lmin = min(s2, lmin);
				s1 = max(0, s1);
				s2 = min(0, s2);
			}
			maxsum = max(maxsum, max(lmax, total - lmin));
		}
		printf("%d\n", maxsum);
	}
	return 0;
}

