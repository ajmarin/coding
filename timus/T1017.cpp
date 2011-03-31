#include <cstdio>
const int N = 501;
long long dp[32][N][N];
long long ks[N][N];
int main(void){
	/* dp[i][j][s] ways of summing s with i steps
	** being the last one j
	*/
	/*
	for(int i = 0; i < 32; ++i)
		for(int j = 0; j < N; ++j)
			for(int k = 0; k < N; ++k)
				dp[i][j][k] = 0;
	for(int i = 1; i < N; ++i) dp[1][i][i] = 1;
	for(int i = 1; i < 31; ++i)
		for(int j = i; j < N; ++j)
			for(int s = (i*i+i)/2; s < N; ++s)
				for(int k = j+1; k + s < N; ++k)
					dp[i+1][k][s + k] += dp[i][j][s];
	*/
	for(int n; scanf("%d", &n) == 1 && n; ){
		/*
		for(int i = 2; i < 32; ++i)
			for(int j = 2; j < N; ++j)
				ans += dp[i][j][n];
		*/
		for(int i = 0; i <= n; ++i) ks[0][i] = i == 0;
		for(int i = 1; i < n; ++i)
			for(int j = 0; j <= n; ++j)
				ks[i][j] = ks[i-1][j] + (i <= j ? ks[i-1][j-i] : 0);
		printf("%lld\n", ks[n-1][n]);
	}
	return 0;
}

