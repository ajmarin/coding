#include <cctype>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#define NN 500
#define INF 1061109567
#define ri	readint
using namespace std;
queue < int > q;
int n;
int adj[NN][NN], deg[NN], p[NN][NN];
const int MAX = 4096;
/* Reading integers */
char buf[MAX], *lim = buf + MAX, *now = lim;
void readint(int &n){	
	while(now != lim && !isdigit(*now)) now++;
	if(now == lim){
		int r = fread(buf, 1, MAX - 1, stdin);
		buf[r] = 0;
		lim = buf + r - 1;
		while(isdigit(*lim)) ungetc(*lim--, stdin);
		now = buf;
	}
	while(!isdigit(*now)) now++;
	for(n = 0; isdigit(*now); n = (n << 1) + (n << 3) + *now++ - '0');
}
int dijkstra(int s, int t) {
	int in[NN], d[NN];
	int best, i, temp, u = s;

	for(i = 0; i < n; i++)
		d[i] = adj[s][i], in[i] = 0;
	d[s] = 0;
	while(!in[t]) {
		in[u] = 1;
		
		for(i = 0; i < n; i++)
			if(adj[u][i] < INF){
				temp =  d[u] + adj[u][i];
				if(temp < d[i]){
					d[i] = d[u] + adj[u][i];
					p[i][(deg[i] = 0)++] = u;
				} else if(temp == d[i]) p[i][deg[i]++] = u;
			}
		best = INF;
		for(i = 0; i < n; i++)
			if(!in[i] && best > d[i])
				best = d[u = i];
		if(best == INF) break;
	}

	return ( ( !in[t] ) ? (-1) : (d[t]) );
}

int main(void){
	int a, b, d, E, i, s, w;
	vector < int >:: iterator it;
	for(ri(n), ri(E); n; ri(n), ri(E)){
		ri(s), ri(d);
		for(i = 0; i < n; i++) deg[i] = 0;
		memset(adj,63,sizeof(adj));
		for(i = 0; i < E; i++) ri(a), ri(b), ri(adj[a][b]);
		if((w = dijkstra(s,d)) == -1){ printf("-1\n"); continue; }
		q.push(d);
		while(!q.empty()){
			int k = q.front(); q.pop();
			for(int i = 0; i < deg[k]; ++i) adj[p[k][i]][k] = INF, q.push(p[k][i]);
			deg[k] = 0;
		}
		printf("%d\n", dijkstra(s,d));
		
	}
	return 0;
}

