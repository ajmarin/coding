#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
typedef unsigned int uint;
typedef long long LL;
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
bool is_prime(int p){
	if(p < 2 || (p != 2 && !(p & 1))) return false;
	int s = p - 1;
	while(!(s & 1)) s >>= 1;
	for(int i = 0; i < 10; ++i){
		int a = rand() % (p - 1) + 1, temp = s;
		int mod = int(bigmod(LL(a), LL(temp), LL(p)));
		while(temp != p - 1 && mod != 1 && mod != p - 1){
			mod = (LL(mod) * mod) % p;
			temp <<= 1;
		}
		if(mod != p - 1 && !(temp & 1)) return false;
	}
	return true;
}
int max(int a, int b){ return a > b ? a : b; }
int main(void){
	srand(time(NULL));
	clock_t ini = clock();
	uint a, b, l, t, u; scanf("%d", &t);
	while(t--){		
		scanf("%d %d", &l, &u);
		int start = max((l / 6) * 6, 6);
		if(l < 3) puts("2");
		if(l < 4) puts("3");
		for(uint i = start; i <= u + 1; i += 6){
			a = i - 1; b = i + 1;
			if(a >= l && is_prime(a)) printf("%u\n", a);
			if(b >= l && b <= u && is_prime(b)) printf("%u\n", b);
		}
		if(t) puts("");
	}
	return 0;
}
