#include <cstdio>
#include <cstring>
bool must[300], vis[300];
int adj[300][300], deg[300];
int a, b, c, v, i;

int dfs(int k){
	int s = 0;
	vis[k] = 1;
	for(int w = 0; w < deg[k]; w++){
		int x = adj[k][w];
		if(!vis[x])
			s += dfs(x);
	}
	return( (s || must[k]) ? (k ? s + 1: s) : 0);
}
int main(void){	
	for(int t = 1; scanf("%d%d",&c,&v) && c; t++){
		memset(must,0,c);
		memset(vis,0,c);
		memset(deg,0,(c<<2));
		for(i = 1; i < c; i++){
			scanf("%d%d",&a,&b);
			adj[--a][deg[a]++] = --b;
			adj[b][deg[b]++] = a;
		}
		for(i = 0; i < v; i++){
			scanf("%d",&a);
			must[--a] = 1;
		}
		printf("Teste %d\n%d\n\n",t,2*dfs(0));
	}
	return 0;
}
