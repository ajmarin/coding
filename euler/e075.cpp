#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#define LIM 1500001
int ans, count[LIM];
int gcd(int a, int b){
	return (b ? gcd(b, a % b) : a);
}
int main(void){
	clock_t ini = clock();
	int sqrt_lim = (int) sqrt(LIM);
	for(int n = 1; n < sqrt_lim; n += 2)
		for(int m = 2; m < sqrt_lim; m += 2){
			if(gcd(n, m) == 1){
				int sum = 2 * m * n + m * m + n * n + abs(m * m - n * n);
				for(int s = sum; s < LIM; s += sum) ++count[s];
			}
		}
	for(int i = 0; i < LIM; ++i) ans += count[i] == 1;
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}

