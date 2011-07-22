#include <cstdio>

#define FORS(i,f,s,n)	for(int i = f; i < n; i += s)
#define FORI(i,f,n)		FORS(i,f,1,n)
#define FOR(i,n)		FORS(i,0,1,n)

const int MAXP = 31623, ROOT = 179;
bool p[MAXP];
int pl[MAXP/5], pc = 0;

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
bool is_prime(int x){
	if(x < MAXP) return p[x];
	FOR(i, pc){
		if(!(x % pl[i])) return false;
		if(sqr(pl[i]) > x) break;
	}
	return true;
}
int main(void){
	FOR(i, MAXP) p[i] = i > 1;
	FORS(i, 4, 2, MAXP) p[i] = false;
	pl[pc++] = 2;
	FORS(i, 3, 2, ROOT) if(p[i]) FORS(j, i*i, (i<<1), MAXP) p[j] = false;
	FORS(i, 3, 2, MAXP) if(p[i]) pl[pc++] = i;
	for(long long a, p; scanf("%lld %lld", &p, &a) == 2 && (a || p); )
		puts(is_prime(p) || bigmod(a, p, p) != a ? "no" : "yes");
	return 0;
}

