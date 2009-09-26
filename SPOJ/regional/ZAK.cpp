#include <cstdio>

#define INF (1<<30)
#define MM 1024

int m, n, g, k;
int mana[MM], dano[MM], mreq[MM];
int w[MM][MM];
int minmana;

int min(int a, int b) { return a < b ? a : b; }

int dijkstra(int s, int t) {
	int in[MM];
	int d[MM];
	int i, u;

	for(i = 0; i < n; i++)
		d[i] = w[s][i], in[i] = 0;

	in[u=s] = 1;

	while(!in[t]) {
		int best = INF;
		for(i = 0; i < n; i++)
			if(!in[i] && best > d[i])
				best = d[u = i];
		if(best == INF) break;

		in[u] = 1;

		for(i = 0; i < n; i++)
			if(!in[i] && w[u][i] < INF && d[i] > d[u] + w[u][i])
				d[i] = d[u] + w[u][i];
	}

	return d[t];
}

int main(void) {
	int i, j;

	while(scanf("%d %d %d %d", &m, &n, &g, &k)) {
		if(m == 0 && n == 0 && g == 0 && k == 0) break;

		/* init */
		n++;
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				w[i][j] = INF;
		w[0][1] = 0;

		/* input */
		for(i = 0; i < m; i++)
			scanf("%d %d", &mana[i], &dano[i]);

		/* processa mreq[] */
		mreq[0] = 0;
		for(i = 1; i < MM; i++) {
			mreq[i] = INF;
			for(j = 0; j < m; j++) {
				int il = i - dano[j];
				if(il < 0) il = 0;
				mreq[i] = min(mreq[i], mreq[il] + mana[j]);
			}
		}

		/* continua input */
		for(i = 0; i < g; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			w[a][b] = w[b][a] = 0;
		}
		for(i = 0; i < k; i++) {
			int a, hp;
			scanf("%d %d", &a, &hp);
			for(j = 0; j < n; j++)
				if(w[j][a] < INF)
					w[j][a] += mreq[hp];
		}

		/* processa */
		minmana = dijkstra(0, n-1);

		/* output */
		if(minmana == INF) printf("-1\n");
		else printf("%d\n", minmana);
	}

	return 0;
}
