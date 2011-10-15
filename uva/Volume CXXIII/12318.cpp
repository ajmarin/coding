#include <cstdio>

#define FOR(i,n) for(int i = 0; i < n; ++i)

typedef long long int LL;
const int MAXN = 10000048;
LL a[16], N;
int v[MAXN], K, M;

LL p(LL x){
	LL r = 0, y = 1;
	FOR(i, K) {
		if(a[i]) r = (r + a[i] * y) % N;
		y = (y * x) % N;
	}
	return r;
}

int main(void){
	FOR(i, MAXN) v[i] = -1;
	for(int T = 1; scanf("%lld%d", &N, &M) && (N || M); ++T){
		int ans = 0;
		scanf("%d", &K); ++K; ++M; ++N;
		FOR(i, K) scanf("%lld", a + i);
		FOR(i, M){
			LL r = p(i);
			ans += v[r] != T;
			v[r] = T;
		}
		printf("%d\n", ans);
	}
	return 0;
}

