#include <cstdio>

const int INF = 1 << 10;
double p[105][3005];
int adj[105][105];
int min(int a, int b){ return a < b ? a : b; }
int max(int a, int b){ return a > b ? a : b; }
int main(void){
	int t; scanf("%d", &t);
	char conn[128];
	for(int c = 0, n, r; c++ < t; ){
		scanf("%d %d", &n, &r);
		double comp = 1 / (double) r;
		int dice = 0;
		for(int i = 0; i < n; ++i){
			scanf("%s", conn);
			for(int j = 0; j < n; ++j)
				if(conn[j] == 'Y') adj[i][j] = 1;
				else adj[i][j] = INF;
		}
		/* Floyd-Warshall (APSP) */
		for(int k = 0; k < n; ++k)
			for(int i = 0; i < n; ++i)
				for(int j = 0; j < n; ++j)
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
		/* Find maximal path length */
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				dice = max(dice, adj[i][j]);
		/* Initialize probabilities */
		for(int i = 0; i <= dice; ++i){
			int lim = r * i + 1;
			for(int j = 0; j < lim; ++j) p[i][j] = 0;
		}
		p[0][0] = 1;
		/* Find probabilities through dynamic programming */
		for(int i = 1; i <= dice; ++i){
			int lim = r * (i - 1) + 1;
			for(int j = 0; j < lim; ++j)
				for(int k = 1; k <= r; ++k)
					p[i][j + k] += p[i - 1][j] * comp;
		}
		/* Read queries, compute probabilities */
		printf("Case %d\n", c);
		int budget, from, q, to, thrown; scanf("%d", &q);
		while(q--){
			scanf("%d %d %d", &from, &to, &budget);
			thrown = adj[--from][--to];
			double tp = 0;
			if(budget >= r * thrown) tp = 1;
			else for(int i = 0; i <= budget; ++i) tp += p[thrown][i];
			printf("%.6lf\n", tp);
		}
		puts("");
	}
	return 0;
}

