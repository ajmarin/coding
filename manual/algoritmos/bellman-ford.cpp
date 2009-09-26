struct { int u, v, w; } e[MM]; /* arestas (u,v) com peso w */

int bellmanford(int s, int t) {
	int di[NN], p[NN]; /* distancias e predecessores */
	int i, j;

	for(i = 0; i < n; i++)
		di[i] = INF, p[i] = -1;

	di[s] = 0;

	for(j = 0; j < n; j++) {
		bool trocou = false;
		for(i = 0; i < m; i++) {
			int u = e[i].u, v = e[i].v;
			if(di[v] > di[u] + e.w) {
				di[v] = di[u] + e.w;
				p[v] = u;
				trocou = true;
			}
		}
		if(!trocou) break;
	}

	return di[t];
}
