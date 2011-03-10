#include <cstdio>

char b[64];
int r[64][64];
int main(void){
	int k, n, t, z;
	for(scanf("%d", &t); t--; ){
		scanf("%d %d", &n, &k);
		n <<= 1;
		for(int i = 0; i < n; ++i) b[i] = '.', r[0][i] = 0;
		for(int i = 0; i < k; ++i){
			scanf("%d", &z);
			b[--z] = '[';
		}
		r[0][1] = 1;
		for(int i = 1; i < n; ++i)
			for(int j = 0; j < n; ++j){
				r[i][j] = 0;
				if(j) r[i][j] += r[i - 1][j - 1];
				if(b[i] != '[' && j != n - 1) r[i][j] += r[i - 1][j + 1];
			}
		printf("%d\n", r[n - 1][0]);
	}
	return 0;
}

