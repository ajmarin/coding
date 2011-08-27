#include <cmath>
#include <cstdio>

const int N = 128;
const int K = 16;
double dp[N][K];
int main(void){
	for(int k, n; scanf("%d %d", &k, &n) == 2; ){
		for(int i = 0; i <= k; ++i)
			dp[1][i] = 1.0;
		for(int i = 2; i <= n; ++i)
			for(int j = 0; j <= k; ++j){
				dp[i][j] = dp[i-1][j];
				if(j > 0) dp[i][j] += dp[i-1][j-1];
				if(j < k) dp[i][j] += dp[i-1][j+1];
			}
		double total = 0;
		for(int i = 0; i <= k; ++i)
			total += dp[n][i];
		printf("%.5lf\n", total * 100.0 / pow(k + 1, n));
	}
	return 0;
}

