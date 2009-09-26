int n;
int w[NN][NN]; /* w[i][j] = num arestas entre (i,j) */
stack<int> tour;

void find_tour(int u) {
	for(int v = 0; v < n; v++) {
		while(w[u][v]) {
			w[u][v]--;
			w[v][u]--;
			find_tour(v);
		}
	}
	tour.push(u);
}

void go() {
	/* cuidado! supoe que o ciclo existe */
	find_tour(start);
	i = tour.top(); tour.pop();
	while(!tour.empty()) {
		j = tour.top(); tour.pop();
		printf("%d %d\n", i, j);
		i = j;
	}
}
