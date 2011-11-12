#include <cstdio>

const int NN = 1024;
int dp[NN][NN];

int max(int a, int b){
	return a > b ? a : b;
}

int main(void){
	for(int i = 0; i < 1024; ++i) dp[i][0] = 0;
	for(int n; scanf("%d", &n) == 1 && n; ){
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= i; ++j){
				scanf("%d", &dp[i][j]);
				dp[i][j] += dp[i - 1][j];
			}
		for(int col = 1; col <= n; ++col){
			for(int line = col; line <= n; ++line)
				dp[line][col] += dp[line - 1][col - 1];
			for(int line = n - 1; line >= col; --line)
				dp[line][col] = max(dp[line][col], dp[line + 1][col]);
		}
		int ans = 0;
		for(int line = 1; line <= n; ++line)
			ans = max(ans, dp[line][line]);
		printf("%d\n", ans);
	}
	return 0;
}

