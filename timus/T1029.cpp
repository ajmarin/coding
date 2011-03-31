#include <cstdio>
#define FOR(i,n)        for(int i = 0; i < n; ++i)
#define FORI(i,b,e)     for(int i = b; i < e; ++i)
#define FORD(i,n)       for(int i = n; i--; )
const int M = 128, N = 512;
int c[M][N], dp[M][N], p[M*N];
int min(int a, int b){ return a < b ? a : b; }
int main(void){
	for(int m, n, x, y; scanf("%d %d", &m, &n) == 2; ){
		FOR(i, m) FOR(j, n) scanf("%d", &c[i][j]), dp[i][j] = 0x7fffffff;
		FOR(j, n) dp[0][j] = c[0][j];
		FORI(i, 1, m) {
			FOR(j, n) dp[i][j] = min(dp[i][j], dp[i-1][j] + c[i][j]);
			FORI(j, 1, n) dp[i][j] = min(dp[i][j], dp[i][j-1] + c[i][j]);
			FORD(j, n-1) dp[i][j] = min(dp[i][j], dp[i][j+1] + c[i][j]);
		}
		int min_cost = 0x7fffffff, ps = 0;
		FOR(j,n) if(dp[m-1][j] < min_cost) x = m-1, y = j, min_cost = dp[m-1][j];
		for(;;){
			p[ps++] = y+1;
			if(x && dp[x][y] == dp[x-1][y] + c[x][y]) --x;
			else if(y && dp[x][y] == dp[x][y-1] + c[x][y]) --y;
			else if(y < n-1 && dp[x][y] == dp[x][y+1] + c[x][y]) ++y;
			else break;
		}
		FORD(i, ps) printf("%d%c", p[i], i ? 32 : 10);
	}
	return 0;
}

