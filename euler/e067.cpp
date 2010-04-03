#include <cmath>
#include <cstdio>
#include <ctime>

#define N 100
#define MAX(a,b) ((a) > (b)? (a):(b))
int ans = 0, m[N][N];
int main(void){
	clock_t ini = clock();
	for(int i = 0; i < N; ++i)
		for(int j = 0; j <= i; ++j) scanf("%d", &m[i][j]);
	for(int i = 1; i < N; ++i)
		for(int j = 0; j <= i; ++j)
			if(!j) m[i][j] += m[i - 1][j];
			else if(j == i) m[i][j] += m[i - 1][j - 1];
			else m[i][j] += MAX(m[i - 1][j], m[i - 1][j - 1]);
	for(int i = 0; i < N; ++i) 
		if(m[N-1][i] > ans) ans = m[N-1][i];
		
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}

