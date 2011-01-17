#include <cmath>
#include <cstdio>
#include <ctime>
int main(void){
	clock_t ini = clock();
	long long ans = 0;
	int nx, ny, r;
	for(int x = 7, y = 4; x <= 500000001; x = nx, y = ny){
		// Solving Pell's equation x^2 - 3y^2 = 1
		// perimeter = 6 * a +/- 2 (- if c = 2 * a - 1, + if c = 2 * a + 1)
		ans += (x + 1 - ((x & 1) << 1)) << 1;
		nx = (x << 1) + 3 * y;
		ny = (y << 1) + x;
	}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %lld\n", ans);
	return 0;
}
