#include <cstdio>

int main(void){
	int cn = 0;
	for(long long a, b; scanf("%lld%lld", &a, &b) == 2 && (a || b); )
		printf("Case %d: %lld\n", ++cn, (a*a - a) * (b*b - b) >> 2);
	return 0;
}

