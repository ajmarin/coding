#include <cstdio>
#include <ctime>
#define DBG

const int MAXP = 1000007, ROOT = 1007;
bool p[MAXP];
int pow10[8] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};

template <class _T> _T sqr(_T a)		{ return a * a;					}
template <class _T> _T bigmod(_T b, _T e, _T m){// returns b^e mod m
	// Requires: sqr
	_T r = 1;
	for( ; e; e >>= 1){
		if(e & 1) r = (r * b) % m;
		b = sqr(b) % m;
	}
	return r;
}
int digits(int x){ return x ? 1+digits(x/10) : 0; }
long long solve(long long p1, long long p2){
	long long d = pow10[digits(p1)];
	long long y = d + p1, z = p2;
	for( ; y != z; ){
		y += d;
		while(z < y) z += p2;
	}
#ifdef DBG
	printf("(%lld, %lld) -> %lld\n", p1, p2, y);
#endif
	return y;
}
long long alt_solve(long long p1, long long p2){
	long long d = pow10[digits(p1)];
	long long dinv = bigmod(d, p2-2, p2);
	long long x = (dinv * (p2 - p1)) % p2;
	return d*x + p1;
}

int main(void){
	clock_t begin = clock();
	int i, j, k, pp;
	long long ans = 0;
	for(i = 0; i < MAXP; ++i) p[i] = 1;
	for(i = 4; i < MAXP; i += 2) p[i] = 0;
	for(i = 3; i < ROOT; i += 2)
		if(p[i])
			for(j = i*i, k = 2*i; j < MAXP; j += k) p[j] = 0;
	for(pp = 5, i = 7; i < MAXP; i += 2)
		if(p[i]) ans += alt_solve(pp, i), pp = i;
	printf("Answer: %lld\n", ans);
	printf("Time spent: %.3lfs\n", (double)(clock() - begin) / CLOCKS_PER_SEC);
	return 0;
}

