#include <cstdio>
const int N = 2048;
int n, m[N][N], v[N];
int max(int a, int b){ return a > b ? a : b; }
int main(void){
	while(scanf("%d", &n) == 1){
		for(int i = 0; i < n; ++i) scanf("%d", v + i), m[i][i] = v[i] * n;
		for(int a = n - 1, L = 1; L < n; --a, ++L)
			for(int s = 0, e = s + L; e < n; ++s, ++e)
				m[s][e] = max(v[s]*a + m[s+1][e], v[e]*a + m[s][e-1]);
		printf("%d\n", m[0][n-1]);
	}
	return 0;
}

