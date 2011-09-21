#include <cstdio>
const int N = 1024;
char s[N], t[N], *ss = s - 1, *tt  = t - 1;
int dp[N][N], w[N][N];
int max(int a, int b){ return a > b ? a : b; }
int main(void){
	for(int l1, l2, k; scanf("%d", &k) && k; ){
		scanf("%s %s", s, t);
		for(l1 = -1; s[++l1]; );
		for(l2 = -1; t[++l2]; );
		w[0][0] = 0;
		for(int i = 0; i < N; ++i) dp[i][0] = dp[0][i] = 0;
		for(int i = 1; i <= l1; ++i)
			for(int j = 1; j <= l2; ++j){
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				w[i][j] = ss[i] == tt[j] ? w[i - 1][j - 1] + 1 : 0;
				if(w[i][j] >= k) for(int z = k; z <= w[i][j]; ++z)
					dp[i][j] = max(dp[i][j], dp[i - z][j - z] + z);
			}
		printf("%d\n", dp[l1][l2]);
	}
	return 0;
}

