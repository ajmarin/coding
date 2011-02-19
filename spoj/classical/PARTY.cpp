#include <cstdio>
const int INF = 4096;
int dp[2][1024];
int main(void){
	for(int b, *c, f, m, *o, p, w; scanf("%d %d", &b, &p) == 2 && (b || p); ){
		dp[0][0] = m = 0;
		for(int i = 1; i <= p; ++i){
			c = dp[i&1], o = dp[!(i&1)];
			scanf("%d %d", &w, &f);
			m += f;
			for(int j = 0; j <= m; ++j){
				c[j] = j > m - f ? INF : o[j];
				c[j] = j < f || o[j - f] + w > c[j] ? c[j] : o[j - f] + w;
			}
		}
		for(f = m; c[f] > b; f--);
		printf("%d %d\n", c[f], f);
	}
	return 0;
}

