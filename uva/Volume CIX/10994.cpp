#include <cstdio>

typedef long long int LL;
LL f(LL x){
	if(!x) return 0;
	LL m = x % 10;
	return (x / 10) * 45 + (m * m + m) / 2 + f(x / 10); 
}

int main(void){
	for(LL p, q; scanf("%lld%lld", &p, &q) == 2; ){ 
		if(p < 0 && q < 0) break;
		printf("%lld\n", f(q) - f(p - 1));
	}
	return 0;
}

