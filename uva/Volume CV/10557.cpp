#include <cstdio>

#define FOR(i,n) for(int i = 0; i < n; ++i)
const int INF = 1 << 30;

struct edge {
	int from, to;
} e[10048];
int d[128], energy[128], ec, n;
bool seen[128];

bool dfs(int u){
	if(u == n - 1) return true;
	bool r = false;
	seen[u] = true;
	FOR(i, ec){
		int z = e[i].from, v = e[i].to;
		if(z == u && !seen[v]) r |= dfs(v);
	}
	return r;
}

int main(void){
	while(scanf("%d", &n) == 1 && n != -1){
		ec = 0; // edge counter
		for(int i = 0, conn; i < n; ++i){
			scanf("%d%d", energy + i, &conn);
			while(conn--){
				e[ec].from = i;
				scanf("%d", &e[ec].to);
				--e[ec++].to;
			}
		}
		// Bellman-Ford
		FOR(i, n) d[i] = -INF, seen[i] = false;
		d[0] = 100;
		FOR(i, n) FOR(j, ec){
			int u = e[j].from, v = e[j].to;
			if(d[u] > 0 && d[u] + energy[v] > d[v])
				d[v] = d[u] + energy[v];
		}
		FOR(j, ec){
			int u = e[j].from, v = e[j].to;
			if(d[u] > 0 && d[u] + energy[v] > d[v])
				if(dfs(u)){
					d[n-1] = 1000;
					break;
				}
		}
		puts(d[n-1] > 0 ? "winnable" : "hopeless");
	}
	return 0;
}

