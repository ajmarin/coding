#include <cstdio>
#include <queue>

using namespace std;

#define NN 128
#define DD 1024
#define INF (1<<20)

int n, m, a, d;
int ch[DD];

/* Edmonds-Karp {{{ */
int c[NN][NN], f[NN][NN];
int v[NN], p[NN];

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

void maxflow(int s, int t) {
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
	}
}
/* }}} */

int bfsf(int s, int t) {
	queue<int> q;
	int dist[NN];
	int i, j;
	for(i = 0; i < n; i++)
		v[i] = 0, dist[i] = INF;
	q.push(s);
	dist[s] = 0;
	v[s] = 1;
	p[s] = -1;
	while(!q.empty() && v[t] == 0) {
		i = q.front();
		q.pop();
		for(j = 0; j < n; j++) {
			if(v[j] == 0 && f[i][j] > 0) {
				q.push(j);
				dist[j] = dist[i] + 1;
				v[j] = 1;
				p[j] = i;
			}
		}
	}
	return dist[t];
}

int main(void) {
	int i, j;

	while(scanf("%d %d %d", &n, &m, &a)) {
		if(n == 0 && m == 0 && a == 0) break;

		/* init */
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				c[i][j] = 0;

		/* input */
		for(i = 0; i < m; i++) {
			int o, d, s;
			scanf("%d %d %d", &o, &d, &s), o--, d--;
			c[o][d] = s;
		}

		/* processa */
		maxflow(0, n-1);
		for(i = 0; i < DD; i++) ch[i] = 0;
		while((j = bfsf(0, n-1)) != INF) {
			int cf = INF;
			for(i = n-1; p[i] >= 0; i = p[i])
				cf = min(cf, f[p[i]][i]);
			for(i = n-1; p[i] >= 0; i = p[i])
				f[p[i]][i] -= cf;
			ch[j] += cf;
		}
		for(d = 1; a > 0; d++) {
			ch[d] += ch[d-1];
			a -= ch[d];
		}

		/* output */
		printf("%d\n", d-1);
	}

	return 0;
}
