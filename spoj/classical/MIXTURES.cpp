#include <cstdio>
const int INF = 1 << 29, N = 100;
int r[N][N], s[N][N], v[N];
int min(int a, int b){ return a < b ? a : b; }
int main(void){
	for(int n; scanf("%d", &n) == 1; ){
		for(int i = 0; i < n; ++i){
			scanf("%d", v + i);
			r[i][i] = v[i];
			s[i][i] = 0;
			for(int j = i - 1; j > -1; --j){
				r[j][i] = (r[j + 1][i] + v[j]) % 100;
				s[j][i] = INF;
			}
		}
		for(int L = 1; L < n; ++L)
			for(int b = 0, e = L; e < n; ++b, ++e)
				for(int i = b; i < e; ++i)
					s[b][e] = min(s[b][e], r[b][i]*r[i+1][e]+s[b][i]+s[i+1][e]);
		printf("%d\n", s[0][n - 1]);
	}
	return 0;
}

