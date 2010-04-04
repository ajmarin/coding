#include <cmath>
#include <cstdio>
#include <ctime>

int c[8] = { 1, 2, 5, 10, 20, 50, 100, 200 };
int ways[201] = {0};
int main(void){
	clock_t ini = clock();
	ways[0] = 1;
	for(int i = 0; i < 8; ++i)
		for(int j = c[i]; j < 201; ++j)
			ways[j] += ways[j - c[i]];
	int ans = ways[200];
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}

