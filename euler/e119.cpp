#include <algorithm>
#include <cmath>
#include <cstdio>
#include <ctime>
long long list[1000], ls = 0;
int sod(long long x){
	for(int r = 0; ; x /= 10)
		if(x == 0) return r;
		else r += x % 10;
}
int main(void){
	clock_t ini = clock();
	long long ans = 0;
	list[ls++] = 1;
	for(int base = 2; ; ++base){
		int max_exp = int(ceil(63 * log(2) / log(base)));
		if(max_exp == 4) break;
		for(long long r = base * base, c = 2; c < max_exp; r *= base, ++c)
			if(r > 99 && sod(r) == base){
				printf("%lld = %d^%d\n", r, base, c);
				list[ls++] = r;
			}
	}
	std::sort(list, list + ls);
	ans = list[29];
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %lld\n", ans);
	return 0;
}
