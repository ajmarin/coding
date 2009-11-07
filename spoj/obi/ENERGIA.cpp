#include <cstdio>
int adj[100][100], deg[100], vis;
bool v[100];
void dfs(int k){
	v[k] = 1; vis++;
	for(int j = 0; j < deg[k]; j++)
		if(!v[adj[k][j]])
			v[adj[k][j]] = 1,
			dfs(adj[k][j]);
}
int main(void){
	int a, b, i, E, L;
	for(int t = 1; scanf("%d%d",&E,&L) && E; t++){
		for(i = 0; i < E; i++) deg[i] = v[i] = 0;
		for(i = 0; i < L; i++)
			scanf("%d%d",&a,&b),
			adj[--a][deg[a]++] = --b,
			adj[b][deg[b]++] = a;
		vis = 0;
		dfs(0);
		printf("Teste %d\n",t);
		if(vis == E) printf("normal\n\n");
		else printf("falha\n\n");
	}
	return 0;
}
