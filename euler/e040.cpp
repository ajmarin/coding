#include <cmath>
#include <cstdio>
#include <ctime>

int nd[10], s[7] = {1, 10, 100, 1000, 10000, 100000, 1000000 };
int main(void){
	clock_t ini = clock();
	int ans = 1, d = 0, si = 0;
	for(int i = 1; d < 1000000; ++i){
		int x = i, p = 0;
		while(x) nd[p++] = x % 10, x /= 10;
		while(p--) if(++d == s[si]) si++, ans *= nd[p];
	}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}

