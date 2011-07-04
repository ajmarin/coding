#include <cstdio>
#include <ctime>

const int MAXP = 40000000, ROOT = 6325;

int phi[MAXP];
int chain[MAXP];
int main(void){
	clock_t begin = clock();
	long long ans = 0;
	chain[0] = chain[1] = 1;
	for(int i = 0; i < MAXP; ++i) phi[i] = i;
	for(int i = 2; i < MAXP; i += 2) phi[i] >>= 1;
	for(int i = 3; i < MAXP; i += 2)
		if(phi[i] == i) for(int j = i; j < MAXP; j += i)
			phi[j] -= phi[j]/i;
	for(int i = 2; i < MAXP; ++i)
		if((chain[i] = 1 + chain[phi[i]]) == 25 && phi[i] == i - 1)
			ans += i;
	printf("Answer: %lld\n", ans);
	printf("Time spent: %.3lfs\n", (double)(clock() - begin)/CLOCKS_PER_SEC);
	return 0;
}

