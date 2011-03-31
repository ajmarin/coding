#include <cstdio>

int dp[45][2];
int main(void){
	dp[0][0] = dp[0][1] = dp[1][0] = dp[1][1] = 1;
	for(int i = 2; i < 45; ++i){
		dp[i][0] = dp[i - 1][1] + dp[i - 2][1];
		dp[i][1] = dp[i - 1][0] + dp[i - 2][0];
	}
	for(int n; scanf("%d", &n) == 1; )
		printf("%u\n", dp[n-1][0] + dp[n-1][1]);
	return 0;
}

