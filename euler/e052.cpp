#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>

bool perm(int a, int b){
	char d[2][11] = { "0000000000", "0000000000" };
	while(a) d[0][a % 10]++, a /= 10;
	while(b) d[1][b % 10]++, b /= 10;
	return strcmp(d[0], d[1]) == 0;
}
int main(void){
	clock_t ini = clock();
	int ans = 0;
	for(int i = 1, j; !ans; ++i){
		for(j = 2; j < 7; ++j) if(!perm(i, i * j)) break;
		if(j == 7) ans = i;
	}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}

