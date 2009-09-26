int w[MAX_NODES][MAX_NODES];		/* adjacencias */
int d[MAX_NODES][MAX_NODES];		/* distancias */
int p[MAX_NODES][MAX_NODES];		/* predecessores */

/* algoritmo */
void floyd_warshall() {
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) { 
			d[i][j] = (i == j ? 0 : w[i][j]);
			p[i][j] = i;
		} 
	}

	for(k = 0; k < n; k++) {
		for(i = 0; i < n; i++) {
			if(i != k && d[i][k] < INF) { // opcional, deixa + rapido
				for(j = 0; j < n; j++) {
					if(d[i][k] + d[k][j] < d[i][j]) { 
						d[i][j] = d[i][k] + d[k][j]; 
						p[i][j] = p[k][j]; 
					}
				} // for j
			} // opcional
		} // for i
	} // for k
}

/* reconstruir caminho entre i e j */
void print_path(int i, int j) { 
	if(i != j) print_path(i, p[i][j]); 
	print(j); 
} 

