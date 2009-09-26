#include <cstdio>
#include <cmath>

#define NN 512
#define INICIO 0
#define FIM 1
#define INF 1E15
#define EPS 1E-9
#define PONTOA(i) (2 + 2*(i))
#define PONTOB(i) (PONTOA(i) + 1)

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

struct point { int x, y; };

/* Geometria {{{ */
double dist(point a, point b) {
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}	

int cross(point a, point b, point c) {
	return (b.x - a.x)*(c.y * a.y) - (c.x - a.x)*(b.y - a.y);
}

bool on_segment(point i, point j, point k) {
	return min(i.x, j.x) <= k.x && k.x <= max(i.x, j.x)
			&& min(i.y, j.y) <= k.y && k.y <= max(i.y, j.y);
}

int direction(point a, point b, point c) {
	return (c.x - a.x)*(b.y - a.y) - (b.x - a.x)*(c.y - a.y);
}

/* true se ab e cd interceptam */
bool segments_intersect(point a, point b, point c, point d) {
	int d1 = direction(c, d, a);
	int d2 = direction(c, d, b);
	int d3 = direction(a, b, c);
	int d4 = direction(a, b, d);

	if(((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0))
			&& ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0))) return true;
	if(d1 == 0 && on_segment(c, d, a)) return true;
	if(d2 == 0 && on_segment(c, d, b)) return true;
	if(d3 == 0 && on_segment(a, b, c)) return true;
	if(d4 == 0 && on_segment(a, b, d)) return true;

	return false;
}
/* }}} */

point inicio, fim;
point obsa[NN], obsb[NN];
int num_obstaculos;

double w[NN][NN];
int n;

/* Dijkstra {{{ */
double dijkstra(int src, int dest) {
	double d[NN];
	int in[NN];
	int v, i;

	for(i = 0; i < n; i++) {
		d[i] = w[src][i] < -EPS ? INF : w[src][i];
		in[i] = 0;
	}

	v = src;
	d[v] = 0.0;
	in[v] = 1;

	while(!in[dest]) {
		double menor = INF;
		v = -1;
		for(i = 0; i < n; i++) {
			if(!in[i] && d[i] - menor < -EPS) {
				menor = d[i];
				v = i;
			}
		}
		
		if(v == -1) break;

		in[v] = 1;

		/* relaxa */
		for(i = 0; i < n; i++)
			if(!in[i] && w[v][i] > EPS && d[v] + w[v][i] - d[i] < -EPS)
				d[i] = d[v] + w[v][i];
	}

	return d[dest];
}
/* }}} */

int main(void) {
	int i, j, k;
	
	while(scanf("%d %d %d %d %d", &inicio.x, &inicio.y, &fim.x, &fim.y, &num_obstaculos)) {
		if(inicio.x == 0 && inicio.y == 0 && fim.x == 0 && fim.y == 0 && num_obstaculos == 0) break;

		/* init */
		n = num_obstaculos*2 + 2;
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				w[i][j] = -1;
		
		/* input */
		for(i = 0; i < num_obstaculos; i++)
			scanf("%d %d %d %d", &obsa[i].x, &obsa[i].y, &obsb[i].x, &obsb[i].y);

		/* processa/modela o grafo */
		/* adjacencia inicio-fim */
		w[INICIO][FIM] = w[FIM][INICIO] = dist(inicio, fim);
		for(i = 0; i < num_obstaculos; i++) {
			if(segments_intersect(inicio, fim, obsa[i], obsb[i])) {
				w[INICIO][FIM] = w[FIM][INICIO] = -1;
				break;
			}
		}
		/* adjacencias inicio-obs */
		for(i = 0; i < num_obstaculos; i++) {
			/* obsa */
			w[INICIO][PONTOA(i)] = w[PONTOA(i)][INICIO] = dist(inicio, obsa[i]);
			for(j = 0; j < num_obstaculos; j++) {
				if(j != i && segments_intersect(inicio, obsa[i], obsa[j], obsb[j])) {
					w[INICIO][PONTOA(i)] = w[PONTOA(i)][INICIO] = -1;
					break;
				}
			}
			/* obsb */
			w[INICIO][PONTOB(i)] = w[PONTOB(i)][INICIO] = dist(inicio, obsb[i]);
			for(j = 0; j < num_obstaculos; j++) {
				if(j != i && segments_intersect(inicio, obsb[i], obsa[j], obsb[j])) {
					w[INICIO][PONTOB(i)] = w[PONTOB(i)][INICIO] = -1;
					break;
				}
			}
		}
		/* adjacencias obs-fim */
		for(i = 0; i < num_obstaculos; i++) {
			/* obsa */
			w[FIM][PONTOA(i)] = w[PONTOA(i)][FIM] = dist(fim, obsa[i]);
			for(j = 0; j < num_obstaculos; j++) {
				if(j != i && segments_intersect(fim, obsa[i], obsa[j], obsb[j])) {
					w[FIM][PONTOA(i)] = w[PONTOA(i)][FIM] = -1;
					break;
				}
			}
			/* obsb */
			w[FIM][PONTOB(i)] = w[PONTOB(i)][FIM] = dist(fim, obsb[i]);
			for(j = 0; j < num_obstaculos; j++) {
				if(j != i && segments_intersect(fim, obsb[i], obsa[j], obsb[j])) {
					w[FIM][PONTOB(i)] = w[PONTOB(i)][FIM] = -1;
					break;
				}
			}
		}
		/* adjacencias obs-obs */
		for(i = 0; i < num_obstaculos; i++) {
			for(j = 0; j < num_obstaculos; j++) {
				/* a-a */
				if(i == j) continue;
				w[PONTOA(i)][PONTOA(j)] = w[PONTOA(j)][PONTOA(i)] = dist(obsa[i], obsa[j]);
				for(k = 0; k < num_obstaculos; k++) {
					if(k != i && k != j && segments_intersect(obsa[i], obsa[j], obsa[k], obsb[k])) {
						w[PONTOA(i)][PONTOA(j)] = w[PONTOA(j)][PONTOA(i)] = -1;
						break;
					}
				}
				/* b-b */
				w[PONTOB(i)][PONTOB(j)] = w[PONTOB(j)][PONTOB(i)] = dist(obsb[i], obsb[j]);
				for(k = 0; k < num_obstaculos; k++) {
					if(k != i && k != j && segments_intersect(obsb[i], obsb[j], obsa[k], obsb[k])) {
						w[PONTOB(i)][PONTOB(j)] = w[PONTOB(j)][PONTOB(i)] = -1;
						break;
					}
				}
				/* a-b */
				w[PONTOA(i)][PONTOB(j)] = w[PONTOB(j)][PONTOA(i)] = dist(obsa[i], obsb[j]);
				for(k = 0; k < num_obstaculos; k++) {
					if(k != i && k != j && segments_intersect(obsa[i], obsb[j], obsa[k], obsb[k])) {
						w[PONTOA(i)][PONTOB(j)] = w[PONTOB(j)][PONTOA(i)] = -1;
						break;
					}
				}
				/* b-a */
				w[PONTOB(i)][PONTOA(j)] = w[PONTOA(j)][PONTOB(i)] = dist(obsb[i], obsa[j]);
				for(k = 0; k < num_obstaculos; k++) {
					if(k != i && k != j && segments_intersect(obsb[i], obsa[j], obsa[k], obsb[k])) {
						w[PONTOB(i)][PONTOA(j)] = w[PONTOA(j)][PONTOB(i)] = -1;
						break;
					}
				}
			}
		}

		/* output */
		printf("%.2lf\n", dijkstra(INICIO, FIM));
	}

	return 0;
}
