#include <cstdio>

const int M = 1 << 14, N = 1 << 7;

int dp[N][M];

int max(int a, int b){ return a > b ? a : b; }
int min(int a, int b){ return a < b ? a : b; }

int main(void){
	for(int m, n; scanf("%d %d", &m, &n) == 2; ){
		int ans = 0;
		m += 200;
		for(int i = 0; i <= n; ++i) for(int j = 0; j <= m; ++j) dp[i][j] = -16384;
		dp[0][0] = 0;
		for(int i = 1, lim, total_cost = 0, x, y; i <= n; ++i){
			scanf("%d %d", &x, &y);
			lim = min(total_cost += x, m);
			for(int p = 0; p <= lim; ++p){
				dp[i][p] = dp[i - 1][p];
				if(p >= x && dp[i - 1][p - x] + y > dp[i][p]) dp[i][p] = dp[i - 1][p - x] + y;
			}
		}
		m -= 200;
		for(int i = 0; i <= m; ++i) ans = max(ans, dp[n][i]);
		for(int i = 2001; i <= m + 200; ++i) ans = max(ans, dp[n][i]);
		printf("%d\n", ans);
	}
	return 0;
}

