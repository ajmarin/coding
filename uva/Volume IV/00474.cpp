#include <cmath>
#include <cstdio>

const long double log10_2 = log10(2);
int main(void){
	for(int n; scanf("%d", &n) == 1; ){
		long double t = - log10_2 * n;
		int e = int(floor(t));
		printf("2^-%d = %.3lfe%d\n", n, pow(10, t  - e), e);
	}
	return 0;
}

