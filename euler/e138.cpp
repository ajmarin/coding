#include <cmath>
#include <cstdio>
#include <ctime>

long long sqr(long long x){ return ((long long)x) * x; }
int main(void){
	clock_t ini = clock();
	long long ans = 0, a = 0, b = 1;
	for(int c = 0, g = 2; c < 12; ++g){
		b ^= a ^= b ^= a += b;
		if(g > 3 && g % 6 == 3) ans += b >> 1, ++c;
	}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %lld\n", ans);
	return 0;
}
