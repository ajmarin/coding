#include <cmath>
#include <cstdio>
int main(void){
	int cs = 1;
	for(long long k; scanf("%lld", &k) && k; ++cs)
		printf("Case %d: %.0lf\n", cs, ceil(1.5 + sqrt(9 + (k << 3))/2));
	return 0;
}

