#include <cstdio>
#define NN 300
int path[NN][NN], p[NN], psize[NN], v[NN];
int adj[NN][NN], deg[NN];
int leaves[NN];
int cpath[NN];
int ans[600];

void dfs(int k, int d, int pnum){
	cpath[d] = k;
	psize[k] = d + 1;
	p[k] = pnum;
	for(int i = 0; i < d; ++i){
		path[k][i] = cpath[i];
	}
	path[k][d] = k;
	int dec = 0;
	for(int i = 0; i < deg[k]; ++i){
		int x = adj[k][i];
		if(psize[x] < psize[k]){
			dec++;
			continue;
		}
		dfs(adj[k][i], d + 1, k);
	}
	deg[k] -= dec;
}
int main(void){
	int a, ansp = 0, at, b, l = 0, n, ok;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) v[i] = deg[i] = 0, psize[i] = 300;
	for(int i = 0; i < (n - 1); ++i){
		scanf("%d %d", &a, &b);
		--a; --b;
		adj[a][deg[a]++] = b;
		adj[b][deg[b]++] = a;
	}
	dfs(0, 0, -1);
	for(int i = 0; i < n; ++i)
		if(deg[i] == 0) scanf("%d", &leaves[l]), leaves[l++]--;
	at = 0;
	for(int i = 0; i < l; ++i){
		int k = leaves[i], m = psize[at] - 1;
		ok = 1;
		for(m = psize[at]; m-- && (m >= psize[k] || path[at][m] != path[k][m]); ){
			ok &= (deg[at] == 0) || (psize[k] > m && path[at][m] == path[k][m]);
			ans[ansp++] = path[at][m];
			at = p[at];
		}
		if(!ok) break;
		
		while(m < psize[k]){
			ans[ansp] = path[k][m++];
			if(p[ans[ansp]] != -1 && !v[ans[ansp]]){
				deg[p[ans[ansp]]]--;
				v[ans[ansp]] = 1;
			}
			ansp++;
		}
		at = p[k];
	}
	while(p[at] != -1) ans[ansp++] = at, at = p[at];
	if(!ok) puts("-1");
	else {
		for(int i = 0; i < (n << 1) - 1; ++i){
			if(i) putc(32, stdout);
			printf("%d", ans[i] + 1);
		}
		putc(10, stdout);
	}
	return 0;
}
