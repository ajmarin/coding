int n;
int w[NN][NN], adj[NN][NN], deg[NN];

int dijkstra(int s, int t) {
	int in[NN], d[NN];
	int i, u, v;
	priority_queue< pair<int,int> > q;

	for(i = 0; i < n; i++) d[i] = INF, in[i] = 0;
	d[s] = 0, q.push(make_pair(0, s));

	while(!in[t] && !q.empty()) {
		u = q.top().second, q.pop();
		if(in[u]) continue;

		in[u] = 1;

		for(i = 0; i < deg[u]; i++) {
			v = adj[u][i];
			if(!in[v] && d[v] > d[u] + w[u][i]) {
				d[v] = d[u] + w[u][i];
				q.push(make_pair(-d[v], v));
			}
		}
	}

	return d[t];
}
