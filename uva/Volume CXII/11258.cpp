#include <algorithm>
#include <cstdio>
using namespace std;

#define FOR(i,n) for(int i = 0; i < n; ++i)
char L[256];
long long dp[256];
int n, y;

long long f(int x){
	if(dp[x] == -1){
		long long z = 0;
		for(int i = 0; L[x + i]; ++i){
			z = z * 10 + L[x + i] - '0';
			if(z >= (1LL << 31)) break;
			dp[x] = max(dp[x], z + f(x + i + 1));
		}
	}
	return dp[x];
}

int main(void){
	for(scanf("%d", &n); n-- && scanf("%s", L) == 1; printf("%lld\n", f(0))){
		int i;
		for(i = 0; L[i]; ++i) dp[i] = -1;
		dp[i] = 0;
	}
	return 0;
}

