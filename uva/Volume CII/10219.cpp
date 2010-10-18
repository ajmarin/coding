#include <cstdio>
#include <cmath>
long long max(long long a, long long b){ return a > b ? a : b; }
int main(void){
	for(long long k, n; scanf("%lld %lld", &n, &k) == 2; ){
		double r = 0;
		k = max(k, n - k);
		for(long long i = 1, j = k + 1; j <= n; ++j, ++i)
			r += log10(j) - log10(i);
		printf("%.0lf\n", floor(r) + 1);
	}
	return 0;
}
