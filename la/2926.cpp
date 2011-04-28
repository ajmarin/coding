#include <cstdio>
#define N 1024
int cs[N][N], v[N][N];
int main(void){
	int t; scanf("%d", &t);
	for(int cnum = 0; cnum++ < t; ){
		int k, m, n, x, y;
		long long ans = 0;
		scanf("%d %d %d", &n, &m, &k);
		for(int i = 0; i <= n; ++i){
			for(int j = 0; j <= m; ++j){
				v[i][j] = cs[i][j] = 0;
			}
		}
		for(int i = 0; i < k; ++i){
			scanf("%d %d", &x, &y);
			++v[x][y];
			++cs[x][y];
		}
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= m; ++j){
				cs[i][j] += cs[i - 1][j];
			}
		}

		for(int i = 1; i <= n; ++i){
			long long sum = 0;
			for(int j = 1; j <= m; ++j){
				if(v[i][j] > 0){
					ans += sum * v[i][j];
				}
				sum += cs[n][j] - cs[i][j];
			}
		}

		printf("Test case %d: %lld\n", cnum, ans);
	}
	return 0;
}

