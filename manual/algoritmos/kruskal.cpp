int n; /* numero de vertices */

double kruskal() {
	priority_queue<pair<double, pair<int, int> > > q; /* fila de adjacencias */
	double total;
	int c; /* numero de componentes desconexas do grafo */

	/* inserir adjacencias na fila! */
	
	c = n;
	for(i = 0; i < n; i++) makeset(i);

	total = 0.0;
	while(c > 1) {
		double w = -q.top().first;
		int a = q.top().second.second;
		int b = q.top().second.second;
		q.pop();
		if(findset(a) != findset(b)) {
			/* aresta a-b faz parte da MST */
			unionset(a, b);
			total += w;
			c--;
		}
	}

	return total;
}
