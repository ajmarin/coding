#include <cstdio>

#define FOR(i,n)	for(int i = 0; i < n; ++i)
const int INF = 1 << 20;
int adj[128][128];
int min(int a, int b){ return a < b ? a : b; }
int max(int a, int b){ return a > b ? a : b; }
int main(void){
	int T; scanf("%d", &T);
	for(int map = 0, m, n; T-- && scanf("%d %d", &n, &m) == 2; ){
		int a, b, c;
		// Read input and initialize adjacency matrix
		FOR(i, n) FOR(j, n) adj[i][j] = i == j ? 0 : INF;
		FOR(i, m){
			scanf("%d %d %d", &a, &b, &c);
			--a; --b;
			adj[b][a] = adj[a][b] = min(adj[a][b], c);
		}
		// Floyd-Warshall
		FOR(k, n) FOR(i, n) FOR(j, n) adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
		// Find best rally point
		int j, max_d = -1, tmpmax_d;
		FOR(i, n){
			for(j = 0, tmpmax_d = -1; adj[i][j] != INF && j < n; ++j) 
				tmpmax_d = max(tmpmax_d, adj[i][j]);
			if(j != n) continue;
			for(j = 1; adj[i][j] == adj[i][j - 1] && j < 5; ++j);
			if(j == 5 && (tmpmax_d < max_d || max_d == -1)) max_d = tmpmax_d;
		}
		printf("Map %d: %d\n", ++map, max_d);


	}
	return 0;	
}

