#include <cstdio>

int main(void){
	int t; scanf("%d", &t);
	for(long long n; scanf("%lld", &n) == 1; )
		printf("%lld\n", (n * (2*n+1) * (n + 2)) >> 3);
	return 0;
}

