#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
const int NN = 100048;
long long C[NN], G, TF;

template <typename _T> _T GCD(_T a, _T b) { return b ? GCD(b, a %b) : a;	}

bool valid(int x, int n){
	if(x % n || TF % x || TF / x <= n) return false;
	if( (C[0] % x) % (x / n) ) return false;
	return G % x == 0;
}
int main(void){
	for(int n; scanf("%d", &n) == 1 && n; ){
		long long ans = TF = 0;
		for(int i = 0; i < n; TF += C[i++]) scanf("%lld", C + i);
		sort(C, C + n);
		G = 0;
		for(int i = 1; i < n; ++i){
			C[i] -= C[0];
			if(!G) G = C[i];
			else G = GCD(G, C[i]);
		}
		int limit = int(sqrt(TF) + .5);
		int c0 = C[0];
		for(int p = 2; p < C[0]; ++p){
			if(valid(p, n)) 
				ans += (c0 - p) / p + !!(c0 % p);
			if(p >= limit) break;
			if(valid(TF / p, n))
				ans += (c0 - (TF / p) )/ (TF / p) + !!(c0 % (TF / p));
		}
		printf("%lld\n", ans);
	}
	return 0;
}

