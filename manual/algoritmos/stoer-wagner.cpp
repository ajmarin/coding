int n;
int adj[MAX_NODES][MAX_NODES];

/* Stoer-Wagner {{{ */
int v[MAX_NODES], cn;

int mincutphase() {
	int w[MAX_NODES], a[MAX_NODES];
	int i, j;

	/* inicializa conjunto A e pesos dos vertices */
	a[v[0]] = 1;

	for(i = 1; i < cn; i++) {
		a[v[i]] = 0;
		w[i] = adj[v[0]][v[i]];
	}

	/* insere os outros vertices */
	int prev = v[0];
	for(i = 1; i < cn; i++) {
		/* encontra o "most tightly connected vertex" nao pertencente a A */
		int zj = -1;
		for(j = 1; j < cn; j++)
			if(!a[v[j]] && (zj < 0 || w[j] > w[zj]))
				zj = j;

		/* insere o vertice no conjunto A */
		a[v[zj]] = 1;

		/* ultimo vertice? */
		if(i == cn - 1) {
			/* merge prev e v[zj] */
			for(i = 0; i < cn; i++)
				adj[v[i]][prev] = adj[prev][v[i]] += adj[v[zj]][v[i]];
			v[zj] = v[--cn];

			return w[zj];
		}
		prev = v[zj];

		/* atualiza os pesos dos vizinhos */
		for(j = 1; j < cn; j++)
			if(!a[v[j]])
				w[j] += adj[v[zj]][v[j]];
	}

	return INF;
}

int mincut() {
	int best = INF;

	cn = n;
	for(int i = 0; i < n; i++) v[i] = i;

	while(cn > 1)
		best = min(mincutphase(), best);

	return best;
}
/* }}} */
