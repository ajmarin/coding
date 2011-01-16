#include <cstdio>
#include <cstring>
#include <ctime>

#define MAX_MEM 524288
int v[MAX_MEM];
int collatz(long long k){
	if(k < MAX_MEM && v[k]) return v[k];
	int x = k;
	int c = 1;
	while(k > 1){
		if(k & 1) k = (k + (k << 1) + 1) >> 1, c += 2;
		else k >>= 1, ++c;
		if(k < MAX_MEM && v[k]){
			c += v[k] - 1;
			break;
		}
	}
	if(x < MAX_MEM) v[x] = c;
	return c;
}
int main(void){
	clock_t ini = clock();	
	int maxc = 0, num;
	memset(v, 0, sizeof(v));
	for(int i = 1; i < 1000000; ++i){
		int chain = collatz(i);
		if(chain > maxc) {
			maxc = chain;
			num = i;
		}
	}
	printf("Time elapsed: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", num);
	return 0;
}
