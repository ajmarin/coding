#include <cassert>
#include <cstdio>

template <class _T> _T abs(_T a)		{ return a < 0 ? -a : a;		}
template <class _T> _T gcd(_T a, _T b)	{ return b ? gcd(b, a %b) : a;	}
template <class _T> _T max(_T a, _T b)	{ return a > b ? a : b;			}
template <class _T> _T min(_T a, _T b)	{ return a < b ? a : b;			}
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
template <class _T> _T dgs(_T a){				// returns sum of digits (a)
	for(_T r = 0; ; a /= 10)
		if(a) r = r + (a % 10);
		else return r;
}
template <class _T> _T pwr(_T b, _T e){			// returns b^e
	for(_T r = 1; ; b = sqr(b)){
		if(e & 1) r = r * b;
		if(!(e >>= 1)) return r;
	}
}
template <class _T> _T reverse(_T a){
	for(_T r = 0; ; a /= 10)
		if(a) r = r * 10 + (a % 10);
		else return r;
}
template <class _T> bool palindrome(_T a){ return reverse(a) == a; }
template <class _T> void reduce(_T &n, _T d, _T &r, bool nod){
	// Requires: pwr
	_T c = 0;
	if(n % d) return;
	do { n /= d; ++c; } while(!(n % d));
	if(nod) r = r * (c + 1);
	else r = (r * (pwr(d, c + 1) - 1)) / (d - 1);
}
template <class _T>	_T nod(_T a){				// returns number of divisors
	// Requires: reduce
	_T r = 1;
	reduce(a, (_T)2, r, true);
	reduce(a, (_T)3, r, true);
	for(_T i = 6; ; i += 6){
		_T t1 = i + 1, t2 = i - 1;
		reduce(a, t1, r, true);
		reduce(a, t2, r, true);
		if(sqr(t2) > a) break;
	}
	if(a != 1) r <<= 1;
	return r;
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
	assert(gcd(30, 42) == 6);
	assert(gcd(1007, 101) == 1);
	assert(gcd(1LL<<35, 3*(1LL<<35)) == 1LL << 35);
	assert(bigmod(2LL, 15LL, 10007LL) == 2747LL);
	assert(pwr(3LL, 30LL) == 205891132094649LL);
	assert(nod(1512) == 32);
	assert(pwr(7,1) == 7);
	assert(pwr(9,2) == 81);
	assert(pwr(11,3) == 1331);
	assert(pwr(7077,0) == 1);
	assert(sod(28) == 28);
	assert(sod(284) == sod(sod(220))); // 220 and 284 are amicable
	assert(dgs(123456789) == dgs(137458926));
	assert(!palindrome(1232));
	assert(palindrome(1234567654321LL));
	assert(sqr(30) == 900);
	assert(sqr(1LL<<26) == 1LL<<52);
	assert(max(10, 11) == 11);
	assert(min(10, 11) == 10);
	assert(max(1LL<<54, 1LL<<55) == 1LL<<55);
	assert(min(1LL<<63, 1LL<<63) == 1LL<<63);
	assert(abs(1LL<<62) == 1LL<<62);
	assert(abs(-1) == 1);
	printf("TEST SUCCEEDED\n");
	return 0;
}
