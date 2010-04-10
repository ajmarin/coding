#include <cmath>
#include <cstdio>
#include <ctime>

long long ans = 0;
bool is_pentagonal(long long k){
	long long t = 1 + 24 * k, r = (long long)sqrt(t);
	return r * r == t && !((r + 1) % 6);
}
bool is_triangle(long long k){
	long long t = 1 + (k << 3), r = (long long)sqrt(t);
	return r * r == t;
}
int main(void){
	clock_t ini = clock();
	for(int k = 286; !ans; ++k){
		long long a = k, x = 2 * a * a - a;
		if(is_pentagonal(x) && is_triangle(x)) ans = x;
	}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %lld\n", ans);
	return 0;
}

