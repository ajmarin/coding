#include <cstdio>
#include <cstring>


const int NN = 128;

struct edge { int next, to; } e[NN*NN];

bool blocked[NN], r[NN], vis[NN];
int next[NN];
int cn = 0, ecnt, n;

void add_edge(int from, int to){
	edge &E = e[ecnt];
	E.next = next[from];
	E.to = to;
	next[from] = ecnt++;
}

void dfs(int u){
	if(blocked[u]) return;
	vis[u] = true;
	for(int at = next[u], v; at != -1; at = e[at].next)
		if(!vis[v = e[at].to]) dfs(v);
}

int main(void){
	for(scanf("%*d"); scanf("%d", &n) == 1; ){ 
		int dashes = (n << 1) - 1;
		ecnt = 0;
		for(int i = 0; i < n; ++i){
			blocked[i] = false;
			next[i] = -1;
			for(int j = 0, z; j < n; ++j){
				scanf("%d", &z);
				if(z) add_edge(i, j);
			}
		}
		printf("Case %d:\n", ++cn);
		memset(vis, 0, n);
		dfs(0);
		memcpy(r, vis, n);
		for(int i = 0; i < n; ++i){
			memset(vis, 0, n);
			blocked[i] = true;
			dfs(0);
			blocked[i] = false;
			/* Output */
			putc('+', stdout);
			for(int j = dashes; j--; putc('-', stdout));
			puts("+");
			for(int j = 0; j < n; ++j){
				putc('|', stdout);
				putc(vis[j] || !r[j] ? 'N' : 'Y', stdout);
			}
			puts("|");
		}
		putc('+', stdout);
		for(int j = dashes; j--; putc('-', stdout));
		puts("+");
	}
	return 0;
}

