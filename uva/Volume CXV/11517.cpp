#include <cstdio>

#define FOR(a,b)	for(int a = 0; a < b; ++a)
#define FORI(a,b,c)	for(int a = b; a < c; ++a)
int dp[20001], v[64];
int min(int x, int y){ return x < y ? x : y; }
int max(int x, int y){ return x > y ? x : y; }
int main(void){
	int n; scanf("%d", &n);
	for(int m, s; n-- && scanf("%d %d", &s, &m) == 2; ){
		int maxv = 0;
		FOR(i, m) scanf("%d", &v[i]), maxv = max(maxv, v[i]);
		FOR(i, s + maxv) dp[i] = 0x3fffffff;
		dp[0] = 0;
		FOR(i, m) for(int j = s + maxv; j >= v[i]; --j)
			dp[j] = min(dp[j], dp[j - v[i]] + 1);
		FORI(i, s, s + maxv + 1)
			if(dp[i] < 0x3fffffff){
				printf("%d %d\n", i, dp[i]);
				break;
			}
	}
	return 0;
}

