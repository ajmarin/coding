#include <algorithm>
#include <cmath>
#include <cstdio>

#define EPS 1e-6
#define FOR(i, n) for(int i = 0; i < n; ++i)
#define FORI(i,s,n) for(int i = s; i < n; ++i)

using namespace std;

const int N = 64;
int x[N], y[N];
double d[N][N];

inline double hyp(int i, int j){
	return pow(i*i + j*j, .5);
}

int cmp(double a, double b){
	return (a - b > EPS) - (a - b < -EPS);
}

int main(void){

	for(int a, b, m, n; scanf("%d %d", &n, &m) == 2 && (m | n); ){
		int ansu = -1, ansv = -1, cmpval;
		double best = 0, cost, minz = 1e10, z;
		FOR(i, n) FOR(j, n) d[i][j] = i == j ? 0 : 1e10;
		FOR(i, n) scanf("%d %d", x + i, y + i);
		FOR(i, m){
			scanf("%d %d", &a, &b);
			--a; --b;
			d[a][b] = d[b][a] = hyp(x[a] - x[b], y[a] - y[b]);
		}
		FOR(k, n) FOR(i, n) FOR(j, n) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
		FOR(u, n) FORI(v, u + 1, n){
			cost = 0;
			z = hyp(x[v] - x[u], y[v] - y[u]);
			FOR(i, n) FORI(j, i+1, n)
				cost += d[i][j] - min(d[i][j], min(d[i][v] + z + d[u][j], d[i][u] + z + d[v][j]));
			cmpval = cmp(cost, best);
			if(cmpval == 1 || (cmpval == 0 && cmp(z, minz) < 0)){
				best = cost;
				ansu = u;
				ansv = v;
				minz = z;
			}
		}
		if(cmp(best, 0.5) != 1) puts("No road required");
		else printf("%d %d\n", ansu + 1, ansv + 1);

	}

	return 0;
}

