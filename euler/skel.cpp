#include <cmath>
#include <cstdio>
#include <ctime>

int main(void){
	clock_t ini = clock();
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}
