#include <cstdio>

#define FOR(i, n) for(int i = 0; i < n; ++i)

const int NN = 128;

int adj[NN][NN];

int max(int a, int b){ return a > b ? a : b; }
int min(int a, int b){ return a < b ? a : b; }

int main(void){
	scanf("%*d");
	for(int c = 0, n, r; scanf("%d %d", &n, &r) == 2; ){

		// Initialize adjacency matrix
		FOR(i, n) FOR(j, n) adj[i][j] = i == j ? 0 : 0x3f3f3f3f;

		// Read connections, update adjacency matrix
		for(int a, b, i = 0; i < r; ++i){
			scanf("%d %d", &a, &b);
			adj[a][b] = adj[b][a] = 1;
		}

		// All Pairs Shortest Path - Floyd Warshall
		FOR(k, n) FOR(i, n) FOR(j, n)
			adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

		// Compute answer
		int ans = -1, begin, end;
		scanf("%d %d", &begin, &end);
		FOR(i, n) ans = max(ans, adj[begin][i] + adj[i][end]);
		printf("Case %d: %d\n", ++c, ans);
	}
	return 0;
}

