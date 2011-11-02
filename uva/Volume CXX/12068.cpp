#include <cstdio>

long long n, v[16];

long long gcd(long long a, long long b){ return b ? gcd(b, a % b) : a; }

void simplify(long long &num, long long &den){
	long long g = gcd(num, den);
	num /= g;
	den /= g;
}

int main(void){
	int t; scanf("%d", &t);
	for(int cnum = 0; cnum++ < t && scanf("%lld", &n) == 1; ){
		long long den = 1, num = 0;
		for(int i = 0; i < n; ++i){
			scanf("%lld", v + i);
			den = (den / gcd(den, v[i])) * v[i];
		}
		for(int i = 0; i < n; ++i) num += den / v[i];
		simplify(num, den);
		simplify(num, n);
		printf("Case %d: %lld/%lld\n", cnum, n * den, num);
	}
	return 0;
}

