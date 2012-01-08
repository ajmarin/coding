#include <cstdio>
#include <ctime>

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

int main(void){
	clock_t s = clock();
	long long ans = 1855;
	for(int i = ans; i--; ) ans = BigMod(1777LL, ans, 100000000LL); 
	printf("Answer: %lld\n", ans);
	printf("Time spent: %.3lfs\n", (clock() - s) / double(CLOCKS_PER_SEC));
	return 0;
}

