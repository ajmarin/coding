#include <cstdio>

int main(void){
	int t; scanf("%d", &t);
	for(long long n; t-- && scanf("%lld", &n) == 1; printf("%lld\n", n >> 1));
	return 0;
}

