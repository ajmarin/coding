#include <cstdio>
#include <ctime>

int main(void){
	clock_t ini = clock();
	long long ans = 1;
	for(int c = 40, d = 1; c > 20; c--, d++) ans = (ans * c)/d;
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %lld\n", ans);
	return 0;
}
