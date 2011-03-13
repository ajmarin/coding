#include <cstdio>

const int M = 1000000007, N = 1048576;
char s[N];
int dp[N], last[128];
int main(void){
	int i, t; scanf("%d", &t);
	dp[0] = 1;
	while(t--){
		for(int c = 0; c < 128; ++c) last[c] = 0;
		scanf("%s", s + 1);
		for(i = 1; s[i]; ++i){
			dp[i] = dp[i - 1] << 1;
			if(last[s[i]]) dp[i] -= dp[last[s[i]] - 1];
			if(dp[i] < 0) dp[i] += M;
			else if(dp[i] >= M) dp[i] -= M;
			last[s[i]] = i;
		}
		printf("%d\n", dp[--i]);
	}
	return 0;
}

