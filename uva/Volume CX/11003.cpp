#include <algorithm>
#include <cstdio>
using namespace std;
#define NN 1024
#define WW 3024
#define FORI(a,b,c) for(int a = b; a < c; ++a)
#define FOR(a,b) for(int a = 0; a < b; ++a)
int ml[NN], w[NN];
int dp[NN][WW];
int main(void){
	for(int n; scanf("%d", &n) == 1 && n; ){
		int maxl = 0;
		FOR(i, n) FOR(j, WW) dp[i][j] = 0;
		FOR(i, n) scanf("%d %d", &w[i], &ml[i]), dp[i][ml[i]] = 1;
		FORI(i, 1, n)
			FOR(j, WW){
				if(j >= w[i] && dp[i - 1][j]){
					int k = min(ml[i], j - w[i]);
					dp[i][k] = max(dp[i][k], dp[i - 1][j] + 1);
				}
				dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			}
		FOR(i, WW) maxl = max(dp[n - 1][i], maxl);
		printf("%d\n", maxl);
	}
	return 0;
}

