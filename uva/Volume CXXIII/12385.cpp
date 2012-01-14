#include <cstdio>

const int NN = 100048;
int dp[NN], last[NN], v[NN];

int max(int a, int b){ return a > b ? a : b; }

int main(void){
	scanf("%*d");
	for(int i = 0; i < NN; ++i) last[i] = -1;
	for(int n; scanf("%d", &n) == 1 && n; ){
		dp[0] = 0;
		for(int i = 0, z; i < n; ++i){
			scanf("%d", &z);
			v[i] = z;
			if(i) dp[i] = dp[i - 1];
			if(last[z] != -1) dp[i] = max(dp[last[z]] + 1, dp[i]);
			last[z] = i;
		}
		printf("%d\n", dp[n-1]);
		while(n--) last[v[n]] = -1;
	}
	return 0;
}

