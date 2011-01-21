#include <cmath>
#include <cstdio>
#include <ctime>
int getk(int n){
	for(int x = 1, k = 1; ; x = (x * 10 + 1) % n, ++k)
		if(!x) return k;
}
int main(void){
	clock_t ini = clock();
	int ans = -1;
	for(int i = 1000001; ; i += 2)
		if((i % 5) && getk(i) > 1000000){ ans = i; break; }
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}
