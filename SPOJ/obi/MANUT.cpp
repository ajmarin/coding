#include <cstdio>
#include <cstring>
#define min(a,b) ((a<b)?(a):(b))
#define NN 401
int a, b, i, m, n;

/* Pont Art {{{ */
bool art[NN], hasArt, reach[NN][NN];
int idx[NN], low[NN], time;

void Art(int v){
	low[v] = idx[v] = time = time+1;
	for (int w = 1; w <= n; w++)
		if(reach[v][w]){
			if (idx[w]) low[v] = min(low[v],idx[w]);
			else {
				Art(w);
				low[v] = min(low[v],low[w]);
				if(!art[v] && ((idx[v] == 1 && idx[w] != 2)||(idx[v] != 1 && low[w] >= idx[v])))
					art[v] = hasArt = 1;
			}
		}
}
/* }}} */

int main(void){
	for(int t = 1; scanf("%d%d",&n,&m) && n; t++){
		memset(reach,0,sizeof(reach));
		memset(low,0,sizeof(low));
		memset(idx,0,sizeof(idx));
		memset(art,0,sizeof(art));
		for(i = 0; i < m; i++)
			scanf("%d%d",&a,&b),
			reach[a][b] = reach[b][a] = 1;
		hasArt = time = 0;
		Art(1);
		printf("Teste %d\n",t);
		if(hasArt){
			for(i = 1; i <= n; i++)
				if(art[i]) printf("%d ",i);
		}
		else printf("nenhum");
		printf("\n\n");
	}
	return 0;
}
