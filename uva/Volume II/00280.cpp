#include <cstdio>

const int NN = 128;
int adj[NN][NN], deg[NN];
bool v[NN];
int visited;

void dfs(int k){
	for(int i = 0; i < deg[k]; ++i){
		int x = adj[k][i];
		if(!v[x]){
			visited++;
			v[x] = 1;
			dfs(x);
		}
	}
}

int main(void){
	for(int m, n, src; scanf("%d", &n) == 1 && n; ){
		for(int i = 0; i < n; ++i) deg[i] = 0;
		for(int s, t; scanf("%d", &s) == 1 && s--; )
			while(scanf("%d", &t) == 1 && t) adj[s][deg[s]++] = --t;
		scanf("%d", &m);
		while(m--){
			scanf("%d", &src);
			visited = 0;
			dfs(--src);
			printf("%d", n - visited);
			for(int i = 0; i < n; ++i){
				if(!v[i]) printf(" %d", i + 1);
				v[i] = 0;
			}
			putc(10, stdout);
		}
	}
	return 0;
}

