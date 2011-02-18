#include <cstdio>

unsigned dp[2][10001];
const unsigned INF = 1 << 30;
unsigned min(unsigned a, unsigned b){ return a < b ? a : b; }
int main(void){
	int e, f, n, p, t, w; scanf("%d", &t);
	unsigned *c, *o;
	while(t--){
		double max = 0;
		int idx = -1;
		scanf("%d %d %d", &e, &f, &n);
		f -= e;
		for(int i = 0; i <= f; ++i) dp[0][i] = INF;
		dp[0][0] = 0;
		for(int i = 1; i <= n; ++i){
			scanf("%d %d", &p , &w);
			c = dp[i & 1], o = dp[!(i & 1)];
			for(int j = 0; j <= f; ++j) c[j] = INF;
			for(int j = 0; j <= f; ++j){
				c[j] = o[j];
				if(j >= w) c[j] = min(c[j], c[j - w] + p);
			}
		}
		c = dp[n & 1];
		if(c[f] == INF) puts("This is impossible.");
		else printf("The minimum amount of money in the piggy-bank is %u.\n", c[f]);
	}
	return 0;
}

