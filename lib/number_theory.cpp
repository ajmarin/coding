#include <cassert>
#include <cstdio>

template <typename _T> _T Abs(_T a) { return a < 0 ? -a : a;		}
template <typename _T> _T GCD(_T a, _T b) { return b ? GCD(b, a %b) : a;	}
template <typename _T> _T Max(_T a, _T b) { return a > b ? a : b;			}
template <typename _T> _T Min(_T a, _T b) { return a < b ? a : b;			}
template <typename _T> _T Square(_T a) { return a * a;					}
template <typename _T> _T BigMod(_T b, _T e, _T m){ // returns b^e mod m
	// Depends: Square
	_T r = 1;
	for( ; e; e >>= 1){
		if(e & 1) r = (r * b) % m;
		b = Square(b) % m;
	}
	return r;
}
template <typename _T> _T SumOfDigits(_T a){
	for(_T r = 0; ; a /= 10)
		if(a) r = r + (a % 10);
		else return r;
}
template <typename _T> _T Power(_T b, _T e){ // returns b^e
	// Depends: Square
	for(_T r = 1; ; b = Square(b)){
		if(e & 1) r = r * b;
		if(!(e >>= 1)) return r;
	}
}
template <typename _T> _T Reverse(_T a){
	for(_T r = 0; ; a /= 10)
		if(a) r = r * 10 + (a % 10);
		else return r;
}
template <typename _T> bool Palindrome(_T a){ return Reverse(a) == a; }
template <typename _T> void Reduce(_T &n, _T d, _T &r, bool NumberOfDivisors){
	// Depends: Power
	_T c = 0;
	if(n % d) return;
	do { n /= d; ++c; } while(!(n % d));
	if(NumberOfDivisors) r = r * (c + 1);
	else r = (r * (Power(d, c + 1) - 1)) / (d - 1);
}
template <typename _T>	_T NumberOfDivisors(_T a){
	// Depends: Reduce, Square
	_T r = 1;
	Reduce(a, (_T)2, r, true);
	Reduce(a, (_T)3, r, true);
	for(_T i = 6; ; i += 6){
		_T t1 = i + 1, t2 = i - 1;
		Reduce(a, t1, r, true);
		Reduce(a, t2, r, true);
		if(Square(t2) > a) break;
	}
	if(a != 1) r <<= 1;
	return r;
}
template <typename _T> _T SumOfDivisors(_T a){
	// Depends: Reduce, Square
	_T n = a, r = 1;
	Reduce(a, (_T)2, r, false);
	Reduce(a, (_T)3, r, false);
	for(_T i = 6; ; i += 6){
		_T t1 = i + 1, t2 = i - 1;
		Reduce(a, t1, r, false);
		Reduce(a, t2, r, false);
		if(Square(t2) > a) break;
	}
	if(a != 1) r *= (a + 1);
	return r - n;
}

int main(void){
	assert(GCD(30, 42) == 6);
	assert(GCD(1007, 101) == 1);
	assert(GCD(1LL<<35, 3*(1LL<<35)) == 1LL << 35);
	assert(BigMod(2LL, 15LL, 10007LL) == 2747LL);
	assert(Power(3LL, 30LL) == 205891132094649LL);
	assert(NumberOfDivisors(1512) == 32);
	assert(Power(7,1) == 7);
	assert(Power(9,2) == 81);
	assert(Power(11,3) == 1331);
	assert(Power(7077,0) == 1);
	assert(SumOfDivisors(28) == 28);
	assert(SumOfDivisors(284) == SumOfDivisors(SumOfDivisors(220))); // 220 and 284 are amicable
	assert(SumOfDigits(123456789) == SumOfDigits(137458926));
	assert(!Palindrome(1232));
	assert(Palindrome(1234567654321LL));
	assert(Square(30) == 900);
	assert(Square(1LL<<26) == 1LL<<52);
	assert(Max(10, 11) == 11);
	assert(Min(10, 11) == 10);
	assert(Max(1LL<<54, 1LL<<55) == 1LL<<55);
	assert(Min(1LL<<63, 1LL<<63) == 1LL<<63);
	assert(Abs(1LL<<62) == 1LL<<62);
	assert(Abs(-1) == 1);
	printf("TEST SUCCEEDED\n");
	return 0;
}

