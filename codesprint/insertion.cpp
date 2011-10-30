#include <cstdio>

#define FOR(i,n) for(int i = 0; i < n; ++i)
const int MAXN = 100000, MAXV = 1048577;
int cnt[MAXV];

void add(int x, int d){ for( ; x < MAXV; x += (x & -x)) cnt[x] += d; }
int read(int x){ int r = 0; for(; x; x -= (x & -x)) r += cnt[x]; return r; }
int main(void){
	int t; scanf("%d", &t);
	for(int n, z; t-- && scanf("%d", &n) == 1; ){
		long long ans = n;
		FOR(i, MAXV) cnt[i] = 0;
		FOR(i, n){
			scanf("%d", &z);
			add(z, 1);
			ans += i - read(z);
		}
		printf("%lld\n", ans);
	}
	return 0;
}

