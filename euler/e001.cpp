#include <cstdio>
#include <ctime>

int main(void){
	clock_t ini = clock();
	int sum = 0;
	for(int i = 3; i < 1000; ++i) sum += (!(i % 3) || !(i % 5) ? i : 0);
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", sum);
	return 0;
}
