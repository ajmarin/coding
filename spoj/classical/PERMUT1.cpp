#include <cstdio>

int m[16][128];
int main(void){
	int i, j, sum;
	for(i = 0; i < 13; ++i)
		for(j = 0; j < 100; ++j)
			m[i][j] = 0;
	m[1][0] = 1;
	for(i = 2; i < 13; ++i)
		for(j = sum = 0; j < 100; ++j){
			sum += m[i - 1][j];
			if(j >= i) sum -= m[i - 1][j - i];
			m[i][j] = sum;
		}
	for(scanf("%d", &sum); sum--; ){
		scanf("%d %d", &i, &j);
		printf("%d\n", m[i][j]);
	}
	return 0;
}

