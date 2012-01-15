#include <cstdio>
#include <cmath>

long long T(long long n){
	return (n * (n + 1)) >> 1;
}

int main(void){
	for(long long d, s; scanf("%lld%lld", &s, &d) == 2; ){
		printf("%d\n", int(ceil(-.5 + sqrt(1 + (d + T(s - 1)) * 8) * .5)));
	}
	return 0;
}

