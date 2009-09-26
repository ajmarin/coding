int n;
int cost[NN][NN];

int x[NN], y[NN], lx[NN], ly[NN], prev[NN], q[NN];

int hungarian() {
	int i, j, k, s, head, tail;
	int ret = 0;

	/* init */
	for(i = 0; i < n; i++) {
		lx[i] = ly[i] = 0;
		for(j = 0; j < n; j++) lx[i] = max(lx[i], cost[i][j]);
		x[i] = y[i] = -1;
	}

	/* go! go! go! */
	for(i = 0; i < n; i++) {
		/* procura caminho aumentante (BFS) */
		for(j = 0; j < n; j++) prev[j] = -1;
		for(q[0] = i, head = 0, tail = 1; head < tail && x[i] < 0; head++) {
			s = q[head];
			for(j = 0; j < n; j++) {
				if(x[i] >= 0) break;
				if(lx[s] + ly[j] > cost[s][j] || prev[j] >= 0) continue;
				q[tail++] = y[j];
				prev[j] = s;
				if(y[j] < 0) while(j >= 0) {
					s = y[j] = prev[j];
					k = x[s]; /* swap(x[s], j) */
					x[s] = j;
					j = k;
				}
			}
		}

		/* se nao encontrou caminho, atualiza labels e tenta de novo */
		if(x[i] < 0) {
			k = INF;
			for(head = 0; head < tail; head++)
				for(j = 0; j < n; j++)
					if(prev[j] == -1)
						k = min(k, lx[q[head]] + ly[j] - cost[q[head]][j]);
			for(j = 0; j < tail; j++)
				lx[q[j]] -= k;
			for(j = 0; j < n; j++)
				if(prev[j] >= 0)
					ly[j] += k;
			i--;
		}
	}

	/* calcula soma */
	for(i = 0; i < n; i++)
		if(x[i] >= 0)
			ret += cost[i][x[i]];

	return ret;
}
