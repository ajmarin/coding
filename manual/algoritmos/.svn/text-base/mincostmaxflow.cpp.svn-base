int n;
int f[NN][NN], cap[NN][NN], cost[NN][NN]; /* fluxo, capacidade, custo */
list< pair<int, int> > edges; /* lista de adjacencias */

int p[NN], d[NN]; /* previous, dists do bellman-ford */

int bellmanford(int s, int t) {
	int i;

	for(i = 0; i < n; i++) d[i] = INF;

	d[s] = 0;
	p[s] = -1;

	for(i = 0; i < n; i++) {
		bool troca = false;
		foreach(e, edges) {
			int u = e->first, v = e->second;

			/* tenta reduzir fluxo v->u */
			if(f[v][u] && d[v] > d[u] - cost[v][u]) {
				p[v] = u;
				d[v] = d[u] - cost[v][u];
				troca = true;
			}

			/* tenta reforcar fluxo u->v */
			if(f[u][v] < cap[u][v] && d[v] > d[u] + cost[u][v]) {
				p[v] = u;
				d[v] = d[u] + cost[u][v];
				troca = true;
			}
		}
		if(!troca) break;
	}

	return d[t];
}

void mincostmaxflow(int &fcost, int &flow, int s, int t) {
	int i, j;

	/* inicia rede de fluxos */
	fcost = flow = 0;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			f[i][j] = 0;

	while(bellmanford(s, t) < INF) {
		int cf = INF;

		/* encontra gargalo */
		for(i = t; p[i] >= 0; i = p[i])
			if(f[i][p[i]]) cf = min(cf, f[i][p[i]]);
			else cf = min(cf, cap[p[i]][i] - f[p[i]][i]);

		/* atualiza rede residual */
		for(i = t; p[i] >= 0; i = p[i]) {
			if(f[i][p[i]]) {
				f[i][p[i]] -= cf;
				fcost -= cf * cost[i][p[i]];
			} else {
				f[p[i]][i] += cf;
				fcost += cf * cost[p[i]][i];
			}
		}

		flow += cf;
	}
}
