#include <cstdio>
#include <cmath>

#define NN 200
#define FOR(a,b) for(int a = 0; a < b; ++a)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

struct point {
	int x, y;
	inline int sqr(int k){ return (k*k);}
	int d2(const point a){ return sqr(x-a.x)+sqr(y-a.y); }
}p[NN];

int n;

int dijkstra(int s, int t) {
	int d[NN], u;
	bool in[NN];
	FOR(i, n) d[i] = p[s].d2(p[i]), in[i] = 0;
	while(!in[t]) {
		int best = 0x7fffffff;
		FOR(i, n) if(!in[i] && best > d[i]) best = d[u = i];
		in[u] = 1;
		FOR(i, n) if(!in[i]){
			int temp = p[u].d2(p[i]);
			d[i] = MIN(MAX(temp,d[u]),d[i]);
		}
	}
	return d[t];
}
int main(void){
	for(int snum = 1; scanf("%d",&n) && n; ++snum){
		FOR(i, n) scanf("%d %d",&p[i].x,&p[i].y);
		printf("Scenario #%d\n",snum);
		printf("Frog Distance = %.3lf\n\n",sqrt(dijkstra(0,1)));
	}
	return 0;
}

