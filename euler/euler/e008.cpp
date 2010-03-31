#include <cstdio>
#include <ctime>

int v[1000];
int main(void){
	clock_t ini = clock();
	int ans = 0;
	for(int i = 0; i < 1000; ++i) scanf("%1d", &v[i]);
	for(int i = 0; i < 996; ++i){
		int p = v[i] * v[i + 1] * v[i + 2] * v[i + 3] * v[i + 4];
		if(p > ans) ans = p;
	}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}
