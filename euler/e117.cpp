#include <cmath>
#include <cstdio>
#include <ctime>

long long w[51];
int main(void){
	clock_t ini = clock();
	w[0] = w[1] = 1; w[2] = 2; w[3] = 4;
	for(int i = 4; i < 51; ++i)
		w[i] = w[i - 1] + w[i - 2] + w[i - 3] + w[i - 4];
	long long ans = w[50];
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %lld\n", ans);
	return 0;
}
