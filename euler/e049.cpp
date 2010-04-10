#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>

#define MAX 10000
#define SQMAX 100
bool p[MAX];
bool perm(int a, int b){
	char d[2][11] = { "0000000000", "0000000000" };
	while(a) d[0][a % 10]++, a /= 10;
	while(b) d[1][b % 10]++, b /= 10;
	return strcmp(d[0], d[1]) == 0;
}
int main(void){
	clock_t ini = clock();
	int ans = 0, r = 0;
	for(int i = 0; i < MAX; ++i) p[i] = 1;
	p[0] = p[1] = 0;
	for(int i = 4; i < MAX; i += 2) p[i] = 0;
	for(int i = 3; i < SQMAX; i += 2)
		if(p[i]) for(int j = i * i; j < MAX; j += i) p[j] = 0;
	for(int i = 1489; !ans; i += 2){
		int lim = (10000 - i) >> 1;
		if(p[i]) for(int j = 2; !ans && j < lim; j += 2)
			if(p[i + j] && perm(i, i + j) &&
			   p[i+2*j] && perm(i, i+2*j))
				ans = i, r = j;
	}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d%d%d\n", ans, ans + r, ans + 2 * r);
	return 0;
}

