#include <cmath>
#include <cstdio>
#include <ctime>
const int NN = 80;
int m[NN][NN];
int max(int a, int b){ return a > b ? a : b; }
int min(int a, int b){ return a < b ? a : b; }
int main(void){
	clock_t ini = clock();
	freopen("matrix.txt", "r", stdin);
	for(int i = 0; i < NN; ++i) for(int j = 0; j < NN; ++j){
		scanf("%d%*c", &m[i][j]);
		if(i && j) m[i][j] += min(m[i - 1][j], m[i][j - 1]);
		else if(i) m[i][j] += m[i - 1][j];
		else if(j) m[i][j] += m[i][j - 1];
	}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", m[NN - 1][NN - 1]);
	return 0;
}

