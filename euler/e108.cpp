#include <cmath>
#include <cstdio>
#include <ctime>

int cnt(long long n){
	int r = 0;
	for(long long x = n + 1; x <= (n << 1); ++x)
		r += !(n*x % (x - n));
	return r;
}
int main(void){
	clock_t ini = clock();
	int ans = 0;
	/* (1/x) + (1/y) = (1/n)
	** Rephrasing
	** (x + y) / (x * y) = (1 / n)
	** n = xy / (x + y) or
	** y = nx / (x - n)
	** to make solutions unique y >= x
	** border solution is x = y = 2n
	** x > (n + 1) -> (x - n) is positive
	** We have n possible values for x, from n + 1 to 2n
	** and we need nx to be divisible by more than 1000 of (x - n) values
	** Solution: make n itself a product of the smallest primes
	** n = 2 * 3 * 5 * 7 * 11 * 13 * k
	** as x varies we'll have n * k * 4, n * k * 8 etc, which can't be obtained
	** by using only the factors above
	*/
	int k = 2 * 3 * 5 * 7 * 11 * 13;
	for(int c = 0, i = k; c < 1000; i += k){
		int x = cnt(i);
		if(x > c){
			ans = i;
			c = x;
		}
	}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}
