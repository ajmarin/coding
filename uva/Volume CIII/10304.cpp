#include <cstdio>

#define FOR(i,s,n) for(int i(s); i <= n; ++i)
const int N = 256;
int acc[N], c[N], dp[N][N], r[N][N];

inline int min(int a, int b){ return a < b ? a : b; }

int main(void){
	acc[0] = 0;
	for(int n; scanf("%d", &n) == 1; ){
		FOR(i, 1, n){
			scanf("%d", c + i);
			acc[i] = c[i] + acc[i - 1];
			r[i][i] = i;
		}
		FOR(i, 1, n) FOR(j, 1, n) dp[i][j] = 1048576;
		FOR(i, 1, n) dp[i][i - 1] = dp[i][i] = 0;
		FOR(L, 1, n) FOR(i, 1, n - L){
			int j = i + L, t, tc = acc[j] - acc[i - 1];
			FOR(k, r[i][j - 1], r[i + 1][j]){
				t = dp[i][k - 1] + tc - c[k] + dp[k + 1][j];
				if(t < dp[i][j]){
					r[i][j] = k;
					dp[i][j] = t;
				}
			}
		}
		printf("%d\n", dp[1][n]);
	}
	return 0;
}

