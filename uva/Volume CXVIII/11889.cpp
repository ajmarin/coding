#include <cstdio>

int factors(int c, int a){
	int k = 1, r = 1;
	while(!(c & 1)) c >>= 1, k <<= 1;
	if(a % k) r = k;
	for(int i = 3; i * i <= c; i += 2){
		if(c % i) continue;
		k = 1;
		while(!(c % i)) c /= i, k *= i;
		if(a % k) r *= k;
	}
	if(c > 1 && (a % c)) r *= c;
	return r;
}

int main(void){
	int t; scanf("%d", &t);
	while(t--){
		int a, c;
		scanf("%d %d", &a, &c);
		if(c % a) puts("NO SOLUTION");
		else printf("%d\n", factors(c, a));
	}
	return 0;
}

