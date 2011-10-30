#include <cstdio>

long long count(long long x){
	long long count = 0;
	for(int i = 0; ; ++i){
		long long v = 1LL << i;
		if(v > x) break;
		long long intervals = x / v;
		count += (intervals >> 1) * v;
		if(intervals & 1) count += x - intervals * v + 1;
	}
	return count;
}
int main(void){
	int t; scanf("%d", &t);
	for(long long a, b; t-- && scanf("%lld %lld", &a, &b) == 2; ){
		long long ans = 0;
		if(a > b){
			long long t = b;
			b = a;
			a = t;
		}
		if(a < 0 && b < 0){
			ans = 32LL * (b - a + 1) - (count(~a) - count(~b - 1));
		}
		else if(a < 0 && b >= 0) ans = 32LL * -a - count(~a) + count(b);
		else ans = count(b) - count(a - 1);
		printf("%lld\n", ans);
	}
	return 0;
}

