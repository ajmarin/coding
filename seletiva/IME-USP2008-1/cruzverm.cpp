#include <cstdio>

#define NN 10000
#define ESC 1
#define NES 2

int t, n;
int adj[NN][NN];
int deg[NN];
int v[NN][3];

int max(int a, int b) { return a < b ? b : a; }

void dfs(int no) {
	int i;

	v[no][0] = 1;
	v[no][ESC] = 1;
	v[no][NES] = 0;

	for(i = 0; i < deg[no]; i++) {
		int u = adj[no][i];
		/* aresta no-u */
		if(!v[u][0]) {
			dfs(u);
			v[no][ESC] += v[u][NES];
			v[no][NES] += max(v[u][ESC], v[u][NES]);
		}
	}
}

int main(void) {
	int i;

	scanf("%d", &t);
	
	while(t--) {
		scanf("%d", &n);
		for(i = 0; i < n; i++) {
			deg[i] = 0;
			v[i][0] = 0;
		}
		for(i = 1; i < n; i++) {
			int a, b;
			scanf("%d %d", &a, &b), a--, b--;
			adj[a][deg[a]++] = b;
			adj[b][deg[b]++] = a;
		}
		dfs(0);
		printf("%d\n", max(v[0][NES], v[0][ESC]));
	}

	return 0;
}
