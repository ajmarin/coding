#include <cstdio>

#define NN 512
#define INF (1<<28)

int w[NN][NN];
int n, m, q;

int min(int a, int b) { return a < b ? a : b; }

int main(void) {
	int i, j, k, a, b, c;
	
	while(scanf("%d %d", &n, &m)) {
		if(n == 0 && m == 0)
			break;
		
		/* inicia */
		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
				w[i][j] = i == j ? 0 : INF;
		
		/* le as arestas */
		for(i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &c);
			w[a][b] = c;
			if(w[a][b] < INF && w[b][a] < INF) w[b][a] = w[a][b] = 0;
		}
		
		/* Floyd-Warshall */
		for(k = 1; k <= n; k++)
			for(i = 1; i <= n; i++)
				for(j = 1; j <= n; j++)
					w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
		
		/* consultas */
		scanf("%d", &q);
		for(i = 0; i < q; i++) {
			scanf("%d %d", &a, &b);
			if(w[a][b] == INF) printf("Nao e possivel entregar a carta\n");
			else printf("%d\n", w[a][b]);
		}
		printf("\n");
	}

	return 0;
}
