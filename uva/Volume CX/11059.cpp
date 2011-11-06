#include <cstdio>

#define FOR(i,n) for(int i = 0; i < n; ++i)
long long p[32];

long long max(long long a, long long b) { return a > b ? a : b; }

int main(void){
	p[0] = 1;
	for(int cnum = 0, n; scanf("%d", &n) == 1; ){
		long long ans = 0;
		FOR(i, n){
			scanf("%lld", p + i);
			for(int j = 0; j <= i; ++j){
				long long r = 1;
				for(int k = j; k <= i; ++k) r *= p[k];
				ans = max(ans, r);
			}
		}
		printf("Case #%d: The maximum product is %lld.\n\n", ++cnum, ans);
	}
	return 0;
}

