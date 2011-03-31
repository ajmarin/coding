#include <cstdio>

int dp[20][10];
int main(void){
	for(int base, n; scanf("%d %d", &n, &base) == 2; ){
		for(int i = 0; i < base; ++i) dp[0][i] = i>0;
		for(int i = 1; i < n; ++i)
			for(int j = 0; j < base; ++j){
				dp[i][j] = 0;
				for(int k = j == 0; k < base; ++k)
					dp[i][j] += dp[i-1][k];
			}
		int ans = 0;
		for(int i = 0; i < base; ++i) ans += dp[n-1][i];
		printf("%d\n", ans);
	}
	return 0;
}

