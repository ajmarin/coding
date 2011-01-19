#include <cmath>
#include <cstdio>
#include <ctime>
bool bouncy(int x){
	bool dec = true, inc = true;
	for(int c = -1, p = -1; x; x /= 10){
		p = c;
		c = x % 10;
		if(p != -1){
			inc &= p >= c;
			dec &= c >= p;
		}
	}
	return !(inc || dec);
}
int main(void){
	clock_t ini = clock();
	int ans = -1, bc = 0;
	for(int i = 1; ; ++i){
		bc += bouncy(i);
		if(100 * bc == 99 * i){
			ans = i;
			break;
		}
	}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}
