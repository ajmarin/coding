#include <cstdio>
#include <ctime>

int main(void){
	clock_t ini = clock();
	int ans = 0;
	for(int n = 1; !ans && n < 499; ++n)
		for(int m = n + 1; !ans &&  m < 499; ++m){
			int a = 2 * m * n, b = m * m - n * n, c = m * m + n * n;
			if(a + b + c == 1000) ans = a * b * c;
		}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}
