#include <cstdio>
#include <cstring>
#include <algorithm> 

#define NC 300
#define NF 600
#define MAX(a,b) (((a)<(b))?(b):(a))

int adj[NC][NC], deg[NC];/* lista adj */
int lf[NF], ff[NF]; /* local/freq festas */
int leaf[NC], num_leaf; /* lista folhas */
int p[NC]; /* predecessor */
bool v[NC]; /* array visitados (dfs) */
bool inpath[NC];
bool dbg = 0;
void dfs(int k){
	v[k] = 1;
	bool is_a_leaf = 1;
	for(int i = 0; i < deg[k]; i++){
		int x = adj[k][i];
		if(!v[x]){
			p[x] = k;
			dfs(x);
			is_a_leaf = 0;
		}
	}
	if(is_a_leaf) leaf[num_leaf++] = k;			
}
int main(void){
	int C, F, local_festa, max, num_festa;
	int a, b, i, j;
	for(int cnum = 1; scanf("%d%d",&C,&F) && (C||F); cnum++){
		/* inicializa variaveis */
		memset(v,0,sizeof(v));
		memset(p,-1,sizeof(p));
		memset(deg,0,sizeof(deg));
		memset(lf,0,sizeof(lf));
		memset(ff,0,sizeof(ff));
		memset(leaf,0,sizeof(leaf));
		num_leaf = 0;
		/* constroi arvore */
		for(i = 1; i < C; i++){
			scanf("%d%d",&a,&b);
			adj[--a][deg[a]++] = --b;
			adj[b][deg[b]++] = a;
		}
		for(num_festa = i = 0; i < F; i++){
			scanf("%d",&local_festa);
			local_festa--;
			if(num_festa && local_festa == lf[num_festa-1])
				ff[num_festa-1]++;
			else{ 
				lf[num_festa] = local_festa;
				ff[num_festa++] = 1;
			}
		}
		/* MOSTRA FESTAS */
		if(dbg){
		printf("Festas:\n");
		for(i = 0; i < num_festa; i++)
			printf("%d(%d) ",lf[i]+1,ff[i]);
		putchar('\n');
		}
		/* DFS */
		dfs(0);
		
		for(max = i = 0; i  < num_leaf; i++){
			memset(inpath,0,sizeof(inpath));
			int path[NF], psize = 0;
			/* MONTA O CAMINHO */
			for(int x = leaf[i]; x != -1; x = p[x])
				path[psize++] = x, inpath[x] = 1;
			std::reverse(path,path+psize);
			for(int x = leaf[i]; x != -1 ; x = p[x])
				path[psize++] = x;
			/* MONTA ARRAY FESTAS */
			int t_festa = 0;
			int festas[NF], peso[NF];
			for(int x = 0; x < num_festa; x++)
				if(inpath[lf[x]]){
					if(t_festa && lf[x] == festas[t_festa-1])
						peso[t_festa-1]+= ff[x];
					else
						festas[t_festa] = lf[x], peso[t_festa++] = ff[x];
				}
			/* MOSTRA FESTAS */
			if(dbg){
				for(j = 0; j < t_festa; j++)
					printf("%d(%d) ",festas[j]+1,peso[j]);
				putchar('\n');
			}
			/* MOSTRA O CAMINHO */
			if(dbg) for(j = 0; j < psize; j++)
				printf("%d ",path[j]+1);
			/* LCS */
			int LCS[psize+1][t_festa+1];
			for(int x = 0; x <= psize; x++) LCS[x][0] = 0;
			for(int y = 0; y <= t_festa; y++) LCS[0][y] = 0;
			for(int x = 1; x <= psize; x++)
				for(int y = 1; y <= t_festa; y++)
					if(path[x-1] == festas[y-1])
						LCS[x][y] = LCS[x-1][y-1] + peso[y-1];
					else LCS[x][y] = MAX(LCS[x-1][y],LCS[x][y-1]);
			if(dbg) printf("[%d]\n",LCS[psize][t_festa]);
			max = MAX(max,LCS[psize][t_festa]);
		}
		printf("Teste %d\n%d\n\n",cnum,max);
	}
	return 0;
}



		
