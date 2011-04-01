#include <cstdio>

const int N = 60048;
int dp[N];
int min(int a, int b){ return a < b ? a : b; }
int main(void){
	int i, isq, j;
	for(i = 0; i < N; ++i) dp[i] = i;
	for(i = 1; i*i <= N; ++i)
		for(j = isq = i * i; j <= N; ++j)
			dp[j] = min(dp[j], dp[j-isq] + 1);
	for(int n; scanf("%d", &n) == 1; ) printf("%d\n", dp[n]);
	return 0;
}

