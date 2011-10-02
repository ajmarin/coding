#include <cstdio>

#define FOR(i,n)	for(int i = 0; i < n; ++i)
#define FORI(i,s,n) for(int i = s; i < n; ++i)

int dp[1024][10], w[1024][10];

int min(int a, int b){ return a < b ? a : b; }

int main(void){
	int t; scanf("%d", &t);
	for(int x; t-- && scanf("%d", &x); ){
		int lim = x / 100;
		FOR(i, lim+1) FOR(j, 10) dp[i][j] = 0x3f3f3f3f;
		FOR(j, 10) FOR(i, lim) scanf("%d", &w[i][9-j]);
		dp[0][0] = 0;
		FORI(i, 1, lim + 1) FORI(j, i != lim, 10){
			// Hold altitude, cost 30
			dp[i][j] = min(dp[i][j], dp[i - 1][j] - w[i - 1][j] + 30 );
			// Climb flight, cost 60
			if(j) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] - w[i - 1][j - 1] + 60);
			// Sinking, cost 20
			if(j < 9) dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] - w[i - 1][j + 1] + 20);
		}
		printf("%d\n\n", dp[lim][0]);
	}
	return 0;
}

