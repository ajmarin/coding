#include <cstdio>

#define FORI(i,s,n) for(int i = s; i < n; ++i)
long long dp[64][64];
int main(void){
	for(int n, k, m; scanf("%d %d %d", &n, &k, &m) == 3; ){
		FORI(i, 0, n+1) FORI(j, 0, k+1) dp[i][j] = 0;
		dp[0][0] = 1;
		FORI(i, 0, n+1) FORI(j, 1, k+1)
			for(int v = 1; v <= i && v <= m; ++v)
				dp[i][j] += dp[i - v][j - 1];
		printf("%lld\n", dp[n][k]);
	}
	return 0;
}

