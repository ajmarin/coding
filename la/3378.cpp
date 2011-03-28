#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1024;
template <class _T> _T gcd(_T a, _T b)	{ return b ? gcd(b, a %b) : a;	}
int x[N], y[N];
struct frac {
	int num, den;
	frac(int _num = 0, int _den = 0){
		int g = 1;
		if(den) g = gcd(_num, _den);
		num = _num / g;
		den = _den / g;
	}
	bool operator<(const frac &f) const {
		return den < f.den || (den == f.den && num < f.num);
	}
	bool operator==(const frac &f) const {
		return (num == f.num && den == f.den) || (!den && !f.den);
	}
} f[1024];
	
int main(void){
	for(int n, pn = 0; scanf("%d", &n) && n; ){
		int ans = 0;
		for(int i = 0; i < n; ++i) scanf("%d %d", x + i, y + i);
		for(int i = 0; i < n; ++i){
			int fc = 0;
			if(n - i + 1 < ans) break;
			for(int j = i + 1; j < n; ++j)
				f[fc++] = frac(y[j] - y[i], x[j] - x[i]);
			sort(f, f + fc);
			for(int k = 0, l = 0; k < fc; k = l){
				while(l < fc && f[l] == f[k]) ++l;
				ans = max(ans, l - k);
			}
		}
		printf("Photo %d: %d points eliminated\n", ++pn, ++ans > 3 ? ans : 0);
	}
	return 0;
}

