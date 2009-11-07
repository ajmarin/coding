#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;

#define MAX_NODES 100
#define INF 1<<20
#define REP(a,b) for(a = 0; a < b; a++)

int c[MAX_NODES][MAX_NODES];	/* capacidade */
int f[MAX_NODES][MAX_NODES];	/* fluxo */
int v[MAX_NODES];				/* visitados */
int p[MAX_NODES];				/* predecessores no caminho */
int n;							/* numero de vertices */

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
int main(void){
	int a, b, cap, d, e, i, j, s;
	for(int cnum = 1; scanf("%d",&n) && n; cnum++){
		scanf("%d%d%d",&s,&d,&e);
		REP(i,n) REP(j,n) c[i][j] = 0;
		for(i = 0; i < e; i++)
			scanf("%d%d%d",&a,&b,&cap),
			c[--a][--b] = c[b][a] = cap + c[a][b];
		printf("Network %d\nThe bandwidth is %d.\n\n",cnum,max_flow(--s,--d));
	}
	return 0;
}

