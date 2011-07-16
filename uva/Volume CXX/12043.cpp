#include <cstdio>
#define FORS(i,f,s,n)	for(int i = f; i < n; i += s)
const int MAX = 100001;
int memonod[MAX], memosod[MAX];
template <class _T> _T sqr(_T n){ return n * n; }
template <class _T> _T pwr(_T b, _T e){ // returns b^e
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
template <class _T> _T nod(_T a){ // returns number of divisors
	// Requires: reduce
	if(memonod[a] != -1) return memonod[a];
	_T r = 1, n = a;
	reduce(a, (_T)2, r, true);
	reduce(a, (_T)3, r, true);
	for(_T i = 6; ; i += 6){
		_T t1 = i + 1, t2 = i - 1;
		reduce(a, t1, r, true);
		reduce(a, t2, r, true);
		if(sqr(t2) > a) break;
	}
	if(a != 1) r <<= 1;
	return memonod[n] = r;
}
template <class _T> _T sod(_T a){ // returns sum of divisors
	// Requires: reduce
	if(memosod[a] != -1) return memosod[a];
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
	return memosod[n] = r;
}
int main(void){
	int t; scanf("%d", &t);
	FORS(i, 0, 1, MAX) memonod[i] = memosod[i] = -1;
	for(int a, b, k; t-- && scanf("%d %d %d", &a, &b, &k) == 3; ){
		int start = ((a + k - 1) / k) * k;
		long long int g = 0, h = 0;
		++b;
		FORS(i, start, k, b){
			g += nod(i);
			h += sod(i);
		}
		printf("%lld %lld\n", g, h);
	}
	return 0;
}

