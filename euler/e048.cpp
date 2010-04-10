#include <cmath>
#include <cstdio>
#include <ctime>

int main(void){
	clock_t ini = clock();
	long long ans = 0;
	for(int i = 1; i < 1001; ++i){
		long long c = i, r = i;
		for(int j = 1; j < i; ++j) r = (r * c) % 10000000000LL; 
		ans = (ans + r) % 10000000000LL;
	}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %lld\n", ans);
	return 0;
}

