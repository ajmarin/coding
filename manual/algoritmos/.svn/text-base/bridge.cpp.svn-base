int w[MAX_NODES][MAX_NODES];	/* matriz de adjacencia */
int num_nodes;					/* numero de nos */

/* variaveis do bridgeR */
int cnt, lbl[MAX_NODES], low[MAX_NODES], parnt[MAX_NODES];
int bcnt;						/* numero de bridges */

void bridgeR(int v) {
	int x;

	lbl[v] = cnt++;
	low[v] = lbl[v];

	for(x = 0; x < num_nodes; x++) {
		if(!w[v][x])
			/* se x nao eh adjacente a v, continue */
			continue;

		if(lbl[x] == -1) {
			/* se x nao foi visitado ainda, visite */
			parnt[x] = v;
			bridgeR(x);

			if(low[v] > low[x]) low[v] = low[x];
			if(low[x] == lbl[x]) {
				/* v-x eh uma ponte */
				printf("%d-%d\n", v, x);
				bcnt++;
			}
		} else if(x != parnt[v] && low[v] > lbl[x]) {
			low[v] = lbl[x];
		}
	}
}

void all_bridges() {
	int v;

	bcnt = cnt = 0;

	for(v = 0; v < num_nodes; v++)
		lbl[v] = -1;

	for(v = 0; v < num_nodes; v++) {
		if(lbl[v] == -1) {
			parnt[v] = v;
			bridgeR(v);
		}
	}
}

