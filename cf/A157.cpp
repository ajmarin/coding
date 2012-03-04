#include <cstdio>

int v[32][32];
int main(void){
	int c[32], r[32];
	for(int n; scanf("%d", &n) == 1 && n; ){
		for(int i = 0; i < n; ++i) c[i] = r[i] = 0;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j){
				scanf("%d", &v[i][j]);
				r[i] += v[i][j];
				c[j] += v[i][j];
			}

		int ans = 0;
		for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j)
			ans += c[j] > r[i];
		printf("%d\n", ans);
	}
	return 0;
}

