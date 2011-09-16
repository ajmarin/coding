#include <cstdio>
#define TAM 128
int i, j, m, n, temp, x, y;
int adj[TAM][TAM], min[TAM], p[TAM];
bool v[TAM];
int prim(int k){
	int next = -1, tmin = 1000;
	v[k] = 1;
	for(int i = 1; i <= n; i++)
		if(!v[i]){
			if(adj[k][i] < min[i]) min[i] = adj[k][i], p[i] = k;
			if(min[i] < tmin) tmin = min[i], next = i;
		}
	if(next != -1){
		if(p[next] > next) printf("%d %d\n",next,p[next]);
		else printf("%d %d\n",p[next],next);
		prim(next);
	}
}
int main(void){
	for(int t = 1; scanf("%d%d",&n,&m) && n; t++){
		for(i = 1; i <= n; v[i] = 0, min[i] = 1000, i++)
			for(j = 1; j <= n; j++)
				adj[i][j] = 1<<7;
		while(m--) scanf("%d%d%d",&x,&y,&temp), adj[x][y] = adj[y][x] = temp;
		printf("Teste %d\n",t);
		prim(1);
		putchar('\n');
	}
	return 0;
}
