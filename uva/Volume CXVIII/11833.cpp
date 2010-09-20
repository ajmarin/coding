#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int INF = 0x3f3f3f3f;
#define FORI(a,b,c) for(int a = b; a < c; ++a)
#define FOR(a,b) FORI(a, 0, b)
const int NN = 250;
int c, k, m, n;
int w[NN][NN];
int dijkstra(int s, int t) {
	int in[NN], d[NN];
	int i, u = s;

	FOR(i, n) d[i] = w[s][i], in[i] = 0;
	d[s] = 0;
	in[s] = 1;

	while(s != t){
		int best = INF;
		FOR(i, n) if(!in[i] && best > d[i])	best = d[s = i];
		if(best == INF) break;
		in[s] = 1;
		FOR(i, n) if(!in[i] && w[s][i] < INF && d[i] > d[s] + w[s][i])
			d[i] = d[s] + w[s][i];
	}

	return d[t];
}
int main(void){
	int x, y, z;
	while(scanf("%d %d %d %d", &n, &m, &c, &k) && n){
		FOR(i, n) FORI(j, i + 1, n) w[i][j] = w[j][i] = INF;
		FOR(i, m){
			scanf("%d %d %d", &x, &y, &z);
			w[x][y] = w[y][x] = z;
			if(x < c){
				if(y >= c) w[x][y] = INF;
				else {
					int minc = min(x, y);
					int maxc = max(x, y);
					if(maxc - minc == 1) w[minc][maxc] = z;
					else w[minc][maxc] = INF;
					w[maxc][minc] = INF;
				}
			} else if(y < c) w[y][x] = INF;
		}
		x = 0;
		for(int i = c - 1; i--; ){
			x += w[i][i + 1];
			w[i][i + 1] = INF;
			w[i][c - 1] = x;
		}
		printf("%d\n", dijkstra(k, c - 1));

	}
	return 0;
}

