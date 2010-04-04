#include <cmath>
#include <cstdio>
#include <ctime>

int sq(int x){ return (x * x); }
bool sum_of_digits_as_5th_powers(int k){
	int n = k, sum = 0;
	while(k){
		int digit = k % 10;
		sum += sq(sq(digit)) * digit;
		k /= 10;
	}
	return sum == n;
}
	
int main(void){
	clock_t ini = clock();
	int ans = 0;
	for(int i = 2; i < 1000000; ++i)
		if(sum_of_digits_as_5th_powers(i)) ans += i;
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}

