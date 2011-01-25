#include <cassert>
#include <cmath>
#include <cstdio>
#include <ctime>

const int M = 1000000, K2 = 2000;
int s[4000001];
void kadane(int start, int step, int end, long long &ans){
	long long sum = 0;
	for(int j = start; j < end; j += step){
		sum = sum + s[j];
		if(sum < 0) sum = 0;
		else if(sum > ans) ans = sum;
	}
}
int cube(int x){ return x * x * x; }
int main(void){
	clock_t ini = clock();
	long long ans = 0;
	for(int i = 0; i < 55; ++i)
		s[i] = ((100003 - 200003LL*(i+1) + 300007LL * cube(i+1)) % M) - 500000;
	for(int i = 55; i < 4000000; ++i)
		s[i] = ((s[i - 24] + s[i - 55] + M) % M) - 500000;
	for(int i = 0; i < 2000; ++i){
		kadane(K2 * i, 1, K2 * (i + 1), ans);	// ROWS
		kadane(i, K2, M << 2, ans);				// COLUMNS
		kadane(K2 * i, 2001, M << 2, ans);		// diagonal
		kadane(i, 2001, M << 2, ans);			// diagonal
		kadane(i, 1999, M << 2, ans);			// anti-diagonal
		kadane(K2*(i+1)-1, 1999, M << 2, ans);	// anti-diagonal
	}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %lld\n", ans);
	return 0;
}
