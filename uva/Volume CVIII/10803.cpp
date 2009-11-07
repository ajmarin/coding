#include <cmath>
#include <cstdio>

#define FORI(a,b,c) for(int a = b; a < c; ++a)
#define FOR(a,b) FORI(a,0,b)
#define NN 101

struct point {
	int x, y;
	inline int sqr(int k){ return k*k;}
	int d2(point a){ return sqr(x - a.x) + sqr(y - a.y);}
}p[NN];

bool v[NN];
int adj[NN][NN], deg[NN];
double d[NN][NN];
int cnum = 0, vis, N, T;

int dfs(int k){
	v[k] = 1;
	vis++;
	FOR(i, deg[k]) if(!v[adj[k][i]]) dfs(adj[k][i]);
	return vis;
}
int main(void){
	scanf("%d",&T);
	while(T--){
		printf("Case #%d:\n",++cnum);
		scanf("%d",&N);
		FOR(i, N) {
			v[i] = deg[i] = 0;
			FOR(j, i) d[i][j] = d[j][i] = 1E7;
		}
		vis = 0;
		FOR(i, N) scanf("%d %d",&p[i].x,&p[i].y);
		FOR(i, N) FOR(j, i){
			int x = p[j].d2(p[i]);
			if(x < 101){
				adj[i][deg[i]++] = j;
				adj[j][deg[j]++] = i;
				double ddd = sqrt(x);
				d[i][j] = d[j][i] = ddd;
			}

		}
		if(dfs(0) < N) puts("Send Kurdy\n");
		else{
			FOR(k,N) FOR(i, N) FOR(j, N){
				double dist = d[i][k] + d[k][j];
				if(dist < d[i][j]) d[i][j] = dist;
			}
			double max = 0;
			FOR(i, N) FOR(j, i) if(d[i][j] > max) max = d[i][j];
			printf("%.4lf\n\n",max);
		}

	}
	return 0;
}

