#include <cstdio>
#include <cstring>
bool adj[7][7], v[7];
int deg[7], vis;
void dfs(int k){	
	if(deg[k]){
		v[k] = 1;
		for(int w = 0; w < 7; w++)
			if(adj[k][w] && !v[w])
				dfs(w);
	} else dfs(k+1);
}
int main(void){
	int i, imp, j, n;
	for(int t = 1; scanf("%d",&n) && n; t++){
		memset(adj,0,sizeof(adj));
		memset(v,0,sizeof(v));
		memset(deg,0,sizeof(deg));
		while(n--)
			scanf("%d%d",&i,&j),
			deg[i]++, deg[j]++,
			adj[i][j] = adj[j][i] = 1;
		dfs(0);
		for(vis = imp = i = 0; i < 7; i++)
			imp += deg[i]&1,
			vis += (v[i] || !deg[i]);
		if(imp > 2 || vis != 7)
			printf("Teste %d\nnao\n\n",t);
		else printf("Teste %d\nsim\n\n",t);
	}
	return 0;
}
