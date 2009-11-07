#include <cstdio>
#include <cstdlib>

#define NN 10024
#define MOD 1300031

int T, n, m;
int adj[NN][NN], deg[NN];
int ch[NN], vis[NN];
int a[NN], b[NN], c[NN];

int min(int a, int b) { return a < b ? a : b; }

int dfs(int no) {
	vis[no] = 1;
	ch[no] = 1;
	for(int i = 0; i < deg[no]; i++)
		if(!vis[adj[no][i]])
			ch[no] += dfs(adj[no][i]);
	return ch[no];
}

int main(void) {
	int i, ans;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n), m = n-1;
		for(i = 0; i < n; i++) deg[i] = vis[i] = 0;
		for(i = 0; i < m; i++) {
			scanf("%d %d %d", &a[i], &b[i], &c[i]);
			a[i]--, b[i]--;
			adj[a[i]][deg[a[i]]++] = b[i];
			adj[b[i]][deg[b[i]]++] = a[i];
		}
		dfs(0);
		ans = 0;
		for(i = 0; i < m; i++) {
			ans = ans + (c[i]*
				(((n - min(ch[a[i]], ch[b[i]]))*min(ch[a[i]], ch[b[i]])) % MOD)) % MOD;
			ans %= MOD;
		}
		printf("%d\n", ans);
	}

	return 0;
}
