#include <cstdio>
#include <map>
#include <string>
#include <cmath>

using namespace std;

#define NN 1024
#define CC 64

int n, m;
int adj[NN][NN], deg[NN], vis[NN], c[NN];
int x[NN][CC], y[NN][CC];
double cost[NN][CC];
double ans;
map<string, int> ids;

void dfs(int u) {
	int i, j, k, cnt = 0;
	vis[u] = 1;
	for(j = 0; j < c[u]; j++) cost[u][j] = 0.0;
	for(i = 0; i < deg[u]; i++) {
		int v = adj[u][i];
		if(!vis[v]) {
			cnt++, dfs(v);
			for(j = 0; j < c[u]; j++) {
				double best = 1E100, val;
				for(k = 0; k < c[v]; k++) {
					val = sqrt((x[u][j] - x[v][k])*(x[u][j] - x[v][k]) + (y[u][j] - y[v][k])*(y[u][j] - y[v][k])) + cost[v][k];
					if(val < best) best = val;
				}
				cost[u][j] += best;
			}
		}
	}
}

int main(void) {
	int i, j;
	while(scanf("%d", &n) && n) {
		/* init */
		ids.clear();
		m = n-1;
		for(i = 0; i < n; i++) deg[i] = vis[i] = 0;

		/* input */
		for(i = 0; i < n; i++) {
			char buf[32];
			scanf("%s %d", &buf, &c[i]);
			ids[string(buf)] = i;
			for(j = 0; j < c[i]; j++)
				scanf("%d %d", &x[i][j], &y[i][j]);
		}
		for(i = 0; i < m; i++) {
			char bufa[32], bufb[32];
			int a, b;
			scanf("%s %s", &bufa, &bufb);
			a = ids[string(bufa)], b = ids[string(bufb)];
			adj[a][deg[a]++] = b;
			adj[b][deg[b]++] = a;
		}

		/* processa */
		dfs(0);
		ans = 1E100;
		for(i = 0; i < c[0]; i++) if(ans > cost[0][i]) ans = cost[0][i];

		/* output */
		printf("%.1lf\n", ans);
	}

	return 0;
}
