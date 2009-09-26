int n;						/* numero de vertices */
int c[NN][NN], f[NN][NN];	/* capacidade, fluxo */
int v[NN], p[NN]			/* visitado, predecessor */

bool bfs(int s, int t) {
	queue<int> q;
	int i, j;
	for(i = 0; i < n; i++)
		v[i] = 0;
	q.push(s);
	v[s] = 1;
	p[s] = -1;
	while(!q.empty() && v[t] == 0) {
		i = q.front();
		q.pop();
		for(j = 0; j < n; j++) {
			if(v[j] == 0 && c[i][j] - f[i][j] > 0) {
				q.push(j);
				v[j] = 1;
				p[j] = i;
			}
		}
	}
	return v[t] == 1;
}

int max_flow(int s, int t) {
	int mf = 0;
	int i, j;

	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			f[i][j] = 0;

	while(bfs(s, t)) {
		int cf = INF;

		for(i = t; p[i] >= 0; i = p[i])
			cf = min(cf, c[p[i]][i] - f[p[i]][i]);

		for(i = t; p[i] >= 0; i = p[i]) {
			f[p[i]][i] += cf;
			f[i][p[i]] -= cf;
		}

		mf += cf;
	}

	return mf;
}
