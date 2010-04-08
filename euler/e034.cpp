#include <cmath>
#include <cstdio>
#include <ctime>

int f[10] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
bool curious(int x){
	int sum = 0, k = x;
	while(x) sum += f[x % 10], x /= 10;
	return sum == k;
}
int main(void){
	clock_t ini = clock();
	int ans = 0;
	for(int i = 3; i < 2540160; ++i)
		if(curious(i)) ans += i;
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}

