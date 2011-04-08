#include <cstdio>
template <class _T> _T sqr(_T x){ return (x * x); }
template <class _T> _T pwr(_T b, _T e){			// returns b^e
	for(_T r = 1; ; b = sqr(b)){
		if(e & 1) r = r * b;
		if(!(e >>= 1)) return r;
	}
}
template <class _T> void reduce(_T &n, _T d, _T &r, bool nod){
	// Requires: pwr
	_T c = 0;
	if(n % d) return;
	do { n /= d; ++c; } while(!(n % d));
	if(nod) r = r * (c + 1);
	else r = (r * (pwr(d, c + 1) - 1)) / (d - 1);
}
template <class _T> _T sod(_T a){				// returns sum of divisors
	// Requires: reduce
	_T n = a, r = 1;
	reduce(a, (_T)2, r, false);
	reduce(a, (_T)3, r, false);
	for(_T i = 6; ; i += 6){
		_T t1 = i + 1, t2 = i - 1;
		reduce(a, t1, r, false);
		reduce(a, t2, r, false);
		if(sqr(t2) > a) break;
	}
	if(a != 1) r *= (a + 1);
	return r - n;
}

int main(void){
	for(int i, j, n; scanf("%d %d", &i, &j) == 2; ){
		double triv = 1e10;
		for(int a = i; a <= j; ++a){
			int x = sod(a);
			if(x / (double) a < triv) n = a, triv = x / (double) a;
		}
		printf("%d\n", n);
	}
	return 0;
}

