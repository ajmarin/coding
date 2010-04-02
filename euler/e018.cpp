#include <cmath>
#include <cstdio>
#include <ctime>

#define MAX(a,b) ((a) > (b)? (a):(b))
int ans = 0, m[15][15];
int main(void){
	clock_t ini = clock();
	for(int i = 0; i < 15; ++i)
		for(int j = 0; j <= i; ++j) scanf("%d", &m[i][j]);
	for(int i = 1; i < 15; ++i)
		for(int j = 0; j <= i; ++j)
			if(!j) m[i][j] += m[i - 1][j];
			else if(j == i) m[i][j] += m[i - 1][j - 1];
			else m[i][j] += MAX(m[i - 1][j], m[i - 1][j - 1]);
	for(int i = 0; i < 15; ++i) 
		if(m[14][i] > ans) ans = m[14][i];
		
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}

