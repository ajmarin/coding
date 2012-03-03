#include <cstdio>

const int N = 256;

long long dp[N][16][32];
int v[N];

int main(void){
	for(int j = 0; j <= 10; ++j)
		for(int k = 0; k < 20; ++k)
			dp[0][j][k] = 0;
	dp[0][0][0] = 1;
	for(int n, q, sn(0); scanf("%d %d", &n, &q) == 2 && (n | q); ){
		for(int i = 1; i <= n; ++i) scanf("%d", v + i);
		printf("SET %d:\n", ++sn);
		for(int m, mod, qn = 0; qn++ < q; ){
			scanf("%d %d", &mod, &m);
			for(int i = 1; i <= n; ++i){
				int z = v[i] % mod;
				int jlim = i < m ? i : m;
				if(z < 0) z += mod;
				for(int j = 0; j <= jlim; ++j)
					for(int k = 0; k < mod; ++k){
						dp[i][j][k] = dp[i - 1][j][k];
						if(j) dp[i][j][k] += dp[i - 1][j - 1][(k - z + mod) % mod];
					}
			}
			printf("QUERY %d: %lld\n", qn, dp[n][m][0]);
		}
	}
	return 0;
}

