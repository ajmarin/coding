#include <cmath>
#include <cstdio>
#include <ctime>

char d[20];
bool f(int k){
	int p = 0, x = k;
	while(k) d[p++] = k % 10 + '0', k /= 10;
	for(int i = 0; i < p/2; ++i) if(d[i] != d[p-i-1]) return 0;
	p = 0;
	while(x) d[p++] = (x & 1) + '0', x >>= 1;
	for(int i = 0; i < p/2; ++i) if(d[i] != d[p-i-1]) return 0;
	return 1;
}

int main(void){
	clock_t ini = clock();
	int ans = 0;
	for(int i = 0; i < 1000000; ++i)
		if(f(i)) ans += i;
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}

