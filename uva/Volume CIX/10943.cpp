#include <cstdio>

#define FORI(i,s,n) for(int i = s; i < n; ++i)
const int NN = 128;
int dp[NN][NN];
int main(void){
	FORI(i, 0, NN) FORI(j, 0, NN) dp[i][j] = 0;
	dp[0][0] = 1;
	FORI(i, 0, NN) FORI(j, 1, 128){
		for(int k = i; k >= 0; --k) dp[i][j] += dp[i - k][j - 1];
		dp[i][j] %= 1000000;
	}
	for(int a, b; scanf("%d %d", &a, &b) == 2 && (a || b); printf("%d\n", dp[a][b]));
	return 0;
}

