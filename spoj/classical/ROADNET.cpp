#include <cstdio>
int m[200][200];
int main(void){
	int i, j, k, n, p, t;
	for(scanf("%d", &t); t--; ){
		scanf("%d", &n);
		for(i = 0; i < n; ++i)
			for(j = 0; j < n; ++j)
				scanf("%d", &m[i][j]);
		for(i = 0; i < n; ++i)
			for(j = i + 1; j < n; ++j){
				for(k = 0, p = 1; p && k < n; ++k)
					p &= k == i || k == j || (m[i][k] + m[k][j] > m[i][j]);
				if(p) printf("%d %d\n", i+1, j+1);
			}
	}
	return 0;
}

