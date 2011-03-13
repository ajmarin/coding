#include <cstdio>

int dp[1048576];
int main(void){
	dp[1] = 0;
	for(int d, i, n; scanf("%d %d", &n, &d) == 2 && (n || d); ){
		for(i = 2; i <= n; ++i) dp[i] = (dp[i - 1] + d) % i;
		printf("%d %d %d\n", n, d, dp[n] + 1);
	}
	return 0;
}

