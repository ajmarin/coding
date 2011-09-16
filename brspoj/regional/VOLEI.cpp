#include <cstdio>
#include <climits>
#include <queue>
#include <set>
#include <map>

#define foreach(i, c) for(typeof(c.begin()) i = c.begin(); i != c.end(); i++) 
#define NN 256
#define SRC 0
#define SINK 1
#define INF 1<<19

using namespace std;

struct point {
	long long x, y;
	point() { x = y = 0L; }
	point(long long a, long long b) { x = a; y = b; }
};
struct polygon { point p[128]; int n; };

polygon quadra;
set<long long> x, y;

int n;
int cap[NN][NN], f[NN][NN];
int v[NN], p[NN];
map<long long, int> nodesx, nodesy;
int flow;

/* Edmonds-Karp {{{ */
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
			if(v[j] == 0 && cap[i][j] - f[i][j] > 0) {
				q.push(j);
				v[j] = 1;
				p[j] = i;
			}
		}
	}
	return v[t] == 1;
}

int maxflow(int s, int t) {
	int mf = 0;
	int i, j;

	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			f[i][j] = 0;

	while(bfs(s, t)) {
		int cf = INF;

		for(i = t; p[i] >= 0; i = p[i])
			cf = min(cf, cap[p[i]][i] - f[p[i]][i]);

		for(i = t; p[i] >= 0; i = p[i]) {
			f[p[i]][i] += cf;
			f[i][p[i]] -= cf;
		}

		mf += cf;
	}

	return mf;
}
/* }}} */

/* Geometria {{{ */
long long cross(point a, point b, point c) {
	return (b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y);
}

bool on_segment(point i, point j, point k) {
	return min(i.x, j.x) <= k.x && k.x <= max(i.x, j.x)
			&& min(i.y, j.y) <= k.y && k.y <= max(i.y, j.y);
}

bool inpoly(polygon q, point p) {
	bool in = false;
	point a, b;
	int i, j;
	long long t;

	for(i = 0; i < q.n; i++) {
		j = (i+1) % q.n;
		if(q.p[j].x > q.p[i].x) {
			a = q.p[i];
			b = q.p[j];
		} else {
			a = q.p[j];
			b = q.p[i];
		}
		t = cross(a, b, p);
		if(t == 0 && on_segment(a, b, p)) return true; /* LADO! */
		if((q.p[j].x < p.x) == (p.x <= q.p[i].x) && t < 0)
			in = !in;
	}

	return in;
}
/* }}} */

int main(void) {
	int i, j, k;
	long long a, b, c, d;

	while(scanf("%d", &quadra.n)) {
		if(quadra.n == 0) break;

		/* init */
		n = 2;
		nodesx.clear();
		x.clear();
		nodesy.clear();
		y.clear();
		for(i = 0; i < NN; i++)
			for(j = 0; j < NN; j++)
				cap[i][j] = 0;

		/* input */
		c = d = INT_MAX;
		for(i = 0; i < quadra.n; i++) {
			scanf("%Ld %Ld", &a, &b);
			quadra.p[i].x = a, quadra.p[i].y = b;
			if(a == c) x.insert(a);
			if(b == d) y.insert(b);
			c = a, d = b;
		}
		if(a == c) x.insert(a);
		if(b == d) y.insert(b);

		/* processa */
		foreach(xc, x) {
			bool ok = false;
			foreach(yc, y) {
				point p(*xc, *yc);
				if(!inpoly(quadra, p)) {
					int xi, yi;
					if(nodesx.count(*xc) == 0) {
						nodesx[*xc] = xi = n++;
						cap[SRC][xi] = 1;
					} else xi = nodesx[*xc];
					if(nodesy.count(*yc) == 0) {
						nodesy[*yc] = yi = n++;
						cap[yi][SINK] = 1;
					} else yi = nodesy[*yc];
					cap[xi][yi] = 1;
				}
			}
		}
		flow = maxflow(SRC, SINK);

		/* output */
		printf("%d\n", x.size() + y.size() - flow);
	}

	return 0;
}
