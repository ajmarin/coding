int n;
int w[NN][NN];

int dijkstra(int s, int t) {
	int in[NN], d[NN];
	int i, u;

	for(i = 0; i < n; i++)
		d[i] = w[s][i], in[i] = 0;
	d[s] = 0;

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
