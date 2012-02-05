#include <cstdio>
#include <cstring>

const int NN = 128;
struct edge {
	int to, next;
} e[NN * NN];
int cnt[NN], next[NN], vis[NN];
int ecnt, vcnt;

void add_edge(int from, int to){
	edge &E = e[ecnt];
	E.to = to;
	E.next = next[from];
	next[from] = ecnt++;
}

int dfs(int u){
	vis[u] = 1;
	for(int en = next[u]; en != -1; en = e[en].next){
		int v = e[en].to;
		if(!vis[v]) dfs(v);
	}
	return ++vcnt;
}

int main(void){
	for(int n; scanf("%d", &n) == 1 && n; ){
		int ans = ecnt = vcnt = 0;
		for(int i = 0; i < n; ++i) next[i] = -1;
		for(int from, i = 0, z; i < n; ++i){
			scanf("%d", &z);
			while(z--){
				scanf("%d", &from);
				add_edge(i, --from);
			}
		}
		for(int i = 0; i < n; ++i){
			vcnt = 0;
			memset(vis, 0, n << 2);
			dfs(i);
			if((cnt[i] = vcnt) > cnt[ans]) ans = i;
		}
		printf("%d\n", ans + 1);
	}
	return 0;
}

