#include <cmath>
#include <cstdio>
#include <ctime>

long long c[64];
long long count(int n){
	if(c[n]) return c[n];
	long long r = count(n - 1); // add a black block to n-1 length
	for(int x = 3; x < n; ++x)
		r += count(n - x - 1); // black followed by x red
	return c[n] = r + 1; // all prior possibilities plus all red blocks
}
int main(void){
	clock_t ini = clock();
	for(int i = 0; i < 64; ++i) c[i] = 0;
	c[0] = c[1] = c[2] = 1;
	long long ans =  count(50);
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %lld\n", ans);
	return 0;
}
