#include <cstdio>
#include <ctime>

int main(void){
	clock_t ini = clock();
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", 2*2*2*2*3*3*5*7*11*13*17*19);
	return 0;
}
