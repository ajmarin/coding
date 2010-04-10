#include <cmath>
#include <cstdio>
#include <ctime>

#define MAX 1000000
#define SQMAX 1000

bool p[MAX];
int p10[6] = { 1, 10, 100, 1000, 10000, 100000 };

bool circular_prime(int x){
	int k = x, d = 0;
	while(x) x /= 10, d++;
	for(int i = 0; i < d; ++i){
		if(!p[k]) return 0;
		k = (k % 10) * p10[d - 1] + k / 10;
	}
	return p[k];
}
int main(void){
	clock_t ini = clock();
	int ans = 1;
	for(int i = 0; i < MAX; ++i) p[i] = 1;
	for(int i = 4; i < MAX; i += 2) p[i] = 0;
	for(int i = 3; i < SQMAX; i += 2)
		if(p[i]) for(int j = i * i; j < MAX; j += i) p[j] = 0;
	for(int i = 3; i < MAX; i += 2) ans += circular_prime(i);
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}

