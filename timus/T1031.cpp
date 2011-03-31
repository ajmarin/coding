#include <cstdio>
const int N = 10048;
int d[N], dp[N];
int min(int a, int b){ return a < b ? a : b; }
int main(void){
	int C[3], L[3], n, s, t;
	int i;
	while(true){
		for(i = 0; i < 3; ++i) if(scanf("%d", &L[i]) != 1) break;
		if(i != 3) break;
		for(i = 0; i < 3; ++i) if(scanf("%d", &C[i]) != 1) break;
		scanf("%d %d %d", &n, &s, &t);
		if(s > t) s ^= t ^= s ^= t;
		for(int i = 2; i <= n; ++i) scanf("%d", d + i);
		for(int i = s; i <= t; ++i) dp[i] = 0x7fffffff;
		dp[s] = 0;
		for(int i = s; i < t; ++i)
			for(int j = i + 1; j <= t; ++j){
				int dist = d[j] - d[i];
				if(d[j] - d[i] > L[2]) break;
				for(int k = 0; k < 3; ++k)
					if(dist <= L[k]){ dp[j] = min(dp[j], dp[i] + C[k]); break; }
			}
		printf("%d\n", dp[t]);
	}
	return 0;
}

