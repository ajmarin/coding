#include <cmath>
#include <cstdio>
#include <ctime>

int main(void){
	clock_t ini = clock();
	int ans = 0;
	for(int i = 23; i < 101; ++i)
		for(int d = 1, n = i, v = 1; n > i / 2; n--, d++)
			if((v = v*n/d) > 1000000){ ans += (i + 1) - (d << 1); break; }
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}

