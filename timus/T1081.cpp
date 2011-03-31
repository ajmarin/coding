#include <cstdio>

int dp[44][2];
int main(void){
	dp[1][0] = dp[1][1] = 1;
	for(int i = 2; i < 44; ++i){
		dp[i][0] = dp[i-1][0] + dp[i-1][1];
		dp[i][1] = dp[i-1][0];
	}
	for(int n, k; scanf("%d %d", &n, &k) == 2; ){
		if(k > dp[n][0] + dp[n][1]) puts("-1");
		else {
			for(int i = n; i; --i){
				if(dp[i][0] >= k) putc('0', stdout);
				else {
					k -= dp[i][0];
					putc('1', stdout);
				}
			}
			puts("");
		}
	}
	return 0;
}

