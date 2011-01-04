#include <cmath>
#include <cstdio>
#include <ctime>

const int MAX = 10000000;
int phi[MAX];
bool perm(int a, int b){
	int dc[10] = {0};
	while(a) dc[a % 10]++, a /= 10;
	while(b) dc[b % 10]--, b /= 10;
	for(int i = 0; i < 10; ++i)
		if(dc[i]) return 0;
	return 1;
}
int main(void){
	clock_t ini = clock();
	double minp = MAX, p;
	int ans = 0;
	for(int i = 2; i < MAX; ++i) phi[i] = 1;
	for(int i = 2; i < MAX; ++i)
		if(phi[i] == 1)
			for(int j = i + i; j < MAX; j += i)
				phi[j] *= (i - 1);
		else {
			p = i / (double)phi[i];
			if(p < minp && perm(i, phi[i])) minp = p, ans = i;
		}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}

