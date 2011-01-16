#include <cstdio>
#include <ctime>
#define n 100

int main(void){
	clock_t ini = clock();
	int sqsum = (n * (n + 1) * (2 * n + 1)) / 6, sumsq = (1 + n) * n / 2;
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", sumsq*sumsq - sqsum);
	return 0;
}
