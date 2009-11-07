#include <cstdio>
#include <cmath>
#include <list>

using namespace std;

int min(int a, int b) { return a < b ? a : b; }
#define foreach(i, c) for(typeof(c.begin()) i = c.begin(); i != c.end(); i++) 
#define INF 1E16
#define EPS 1E-10

#define SOURCE 0
#define SINK 1
#define PLAYER(x) ((x) + 1)
#define FINISH(x) ((x) + num_players + 1)

#define N 256

int num_players, num_finish;
double px[N], py[N], ps[N];
double fx[N], fy[N];

/* Min-Cost Max-Flow {{{ */
int n;
int f[N][N], cap[N][N];
double cost[N][N];
list< pair<int, int> > edges;

int p[N];
double d[N];

double bellmanford(int s, int t) {
	int i;

	for(i = 0; i < n; i++) d[i] = INF;

	d[s] = 0.0;
	p[s] = -1;

	for(i = 0; i < n; i++) {
		bool troca = false;
		foreach(e, edges) {
			int u = e->first, v = e->second;

			if(f[v][u] && d[v] - (d[u] - cost[v][u]) > EPS) {
				p[v] = u;
				d[v] = d[u] - cost[v][u];
				troca = true;
			}

			if(f[u][v] < cap[u][v] && d[v] - (d[u] + cost[u][v]) > EPS) {
				p[v] = u;
				d[v] = d[u] + cost[u][v];
				troca = true;
			}
		}
		if(!troca) break;
	}

	return d[t];
}

double mincostmaxflow(int s, int t) {
	double fcost;
	int i, j;

	fcost = 0.0;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			f[i][j] = 0;

	while(bellmanford(s, t) - INF < -EPS) {
		int cf = 1<<27;

		for(i = t; p[i] >= 0; i = p[i])
			if(f[i][p[i]]) cf = min(cf, f[i][p[i]]);
			else cf = min(cf, cap[p[i]][i] - f[p[i]][i]);

		for(i = t; p[i] >= 0; i = p[i]) {
			if(f[i][p[i]]) {
				f[i][p[i]] -= cf;
				fcost -= cf * cost[i][p[i]];
			} else {
				f[p[i]][i] += cf;
				fcost += cf * cost[p[i]][i];
			}
		}
	}

	return fcost;
}
/* }}} */

int main(void) {
	int i, j;

	while(scanf("%d %d", &num_players, &num_finish)) {
		if(num_players == 0 && num_finish == 0) break;

		/* init */
		n = num_players + num_finish + 2;
		edges.clear();
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++) {
				cap[i][j] = 0;
				cost[i][j] = INF;
			}

		/* input */
		for(i = 1; i <= num_players; i++) {
			scanf("%lf %lf %lf", &px[i], &py[i], &ps[i]);
			cost[SOURCE][PLAYER(i)] = 0;
			cap[SOURCE][PLAYER(i)] = 1;
			edges.push_back(make_pair(SOURCE, PLAYER(i)));
			edges.push_back(make_pair(PLAYER(i), SOURCE));
		}
		for(j = 1; j <= num_finish; j++) {
			scanf("%lf %lf", &fx[j], &fy[j]);
			cost[FINISH(j)][SINK] = 0;
			cap[FINISH(j)][SINK] = 1;
			edges.push_back(make_pair(FINISH(j), SINK));
			edges.push_back(make_pair(SINK, FINISH(j)));
			while(scanf("%d", &i) && i) {
				double dist = sqrt((fx[j] - px[i])*(fx[j] - px[i]) + (fy[j] - py[i])*(fy[j] - py[i]));
				cap[PLAYER(i)][FINISH(j)] = 1;
				cost[PLAYER(i)][FINISH(j)] = dist/ps[i];
				edges.push_back(make_pair(PLAYER(i), FINISH(j)));
				edges.push_back(make_pair(FINISH(j), PLAYER(i)));
			}
		}

		/* output */
		printf("%.1lf\n", mincostmaxflow(SOURCE, SINK));
	}

	return 0;
}
