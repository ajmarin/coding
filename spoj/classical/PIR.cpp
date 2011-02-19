#include <cmath>
#include <cstdio>
long long sqr(long long a){ return a * a; }
int main(void){
	long long s, u, v, w, U, V, W;
	int t; scanf("%d", &t);
	while(t--){
		scanf("%lld %lld %lld %lld %lld %lld", &W, &U, &v, &V, &u, &w);
		u = sqr(u); v = sqr(v); w = sqr(w);
		U = sqr(U); V = sqr(V); W = sqr(W);
		s = 4*u*v*w - u*sqr(v+w-U) - v*sqr(u+w-V) - w*sqr(u+v-W);
		s += (u+v-W)*(u+w-V)*(v+w-U);
		printf("%.4lf\n", sqrt(s) / 12);
	}
	return 0;
}

