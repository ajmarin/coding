#include <cmath>
#include <cstdio>
#include <ctime>

#define LIM 1001
int main(void){
	clock_t ini = clock();
	int ans = 1, n = 1, inc = 2;
	for(int i = 3; i <= LIM; i += 2, inc += 2)
		for(int c = 0; c < 4; ++c)
			ans += (n += inc);
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}

