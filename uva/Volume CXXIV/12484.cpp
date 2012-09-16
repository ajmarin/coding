#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 10010;
#define FOR(i,n) for(int i = 0; i < n; ++i)
long long dp[2][N];
int v[N];

int main(void){
	for(int n; scanf("%d", &n) == 1; ){
		FOR(i, n){
			scanf("%d", v + i);
			dp[0][i] = dp[1][i] = 0;
		}
		FOR(L, n){
			if(!L) continue;
			int c = L & 1, p = 1 - c;
			if(L & 1) FOR(i, n - L) dp[c][i] = max(dp[p][i] + v[i + L], v[i] + dp[p][i + 1]);
			else FOR(i, n - L) dp[c][i] = min(dp[p][i], dp[p][i + 1]);
		}
		printf("%lld\n", dp[(n-1) & 1][0]);
	}
	return 0;
}

