#include<cstdio>
#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a>b)?(a):(b))
int adj[128][128];
int main(void){
	for(int a, b, i, j, k, min, max_prof, n, t = 1; scanf("%d",&n) && n; t++){
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				adj[i][j] = 1<<10;
		for(i = 1; i < n; i++)
			scanf("%d%d",&a,&b),
			adj[--a][--b] = adj[b][a] = 1;		
		for(k = 0; k < n; k++)
			for(i = 0; i < n; i++)
				for(j = 0; j < n; j++){
					int temp = adj[i][k]+adj[k][j];
					adj[i][j] = MIN(adj[i][j],temp);
				}
		b = 0; min = n;
		for(i =0; i < n; i++){
			for(max_prof = j = 0; j < n; j++)
				if(i!=j) max_prof = MAX(max_prof,adj[i][j]);
			if(max_prof < min)
				min = max_prof, b = i;
		}
		printf("Teste %d\n%d\n\n",t,b+1);
	}
	return 0;
}
