#include <cstdio>

typedef unsigned long long ULL;

ULL P(ULL n, int x){
	ULL ret = 1, b = n;
	while(x){
		if(x & 1) ret *= b;
		b *= b;
		x >>= 1;
	}
	return ret;
}

int main(void){
	for(ULL n; scanf("%llu", &n) == 1 && n; )
		printf("%llu\n", (P(n, 6) + 3 * P(n, 4) + 12 * P(n, 3) + 8 * P(n, 2)) / 24);

	return 0;
}

