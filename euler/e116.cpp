#include <cmath>
#include <cstdio>
#include <ctime>

long long ans = 0, r[51], g[51], b[51];
int main(void){
	clock_t ini = clock();
	r[0] = g[0] = b[0] = 0;
	r[1] = g[1] = b[1] = 0;
	r[2] = 1; g[2] = b[2] = 0;
	r[3] = 2; g[3] = 1; b[3] = 0;
	r[4] = 4; g[4] = 2; b[4] = 1;
	for(int i = 4; i < 51; ++i){
		r[i] = r[i - 1] + r[i - 2] + 1;
		g[i] = g[i - 1] + g[i - 3] + 1;
		b[i] = b[i - 1] + b[i - 4] + 1;
	}
	ans = r[50] + g[50] + b[50];
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %lld\n", ans);
	return 0;
}
