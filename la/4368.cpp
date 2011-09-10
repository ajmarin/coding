#include <cstdio>

int dp[1048576];
int main(void){
	for(int n, k; scanf("%d %d", &n, &k) == 2 && (n || k); ){
		dp[1] = 0;
		for(int i = 2; i <= n; ++i)
			dp[i] = (dp[i - 1] + k) % i;
		printf("%d %d %d\n", n, k, 1 + dp[n]);
	}
	return 0;
}

