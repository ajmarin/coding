#include <cstdio>

int main(void){
	int cnum = 0;
	for(long long n; scanf("%lld", &n) == 1 && n; ){
		if(n & 1) n += 3;
		printf("Case %d: %lld\n", ++cnum, (n*n+24) / 48);
	}
	return 0;
}
