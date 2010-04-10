
#include <cmath>
#include <cstdio>
#include <ctime>

#define MAX 1000000
#define SQMAX 1000

bool p[MAX];
int p10[6] = { 1, 10, 100, 1000, 10000, 100000 };
int dig[10];

bool truncatable_prime(int x){
	int d = 0;
	while(x){
		if(!p[x]) return 0;
		dig[d++] = x % 10;
		x /= 10;
	}
	for(int i = 0; i < d; ++i){
		x += dig[i] * p10[i];
		if(!p[x]) return 0;
	}
	return 1;
}
int main(void){
	clock_t ini = clock();
	int ans = 0, c = 0;
	for(int i = 0; i < MAX; ++i) p[i] = 1;
	p[0] = p[1] = 0;
	for(int i = 4; i < MAX; i += 2) p[i] = 0;
	for(int i = 3; i < SQMAX; i += 2)
		if(p[i]) for(int j = i * i; j < MAX; j += i) p[j] = 0;
	for(int i = 11; c < 11; i += 2) 
		if(truncatable_prime(i)) ans += i, ++c;
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}

