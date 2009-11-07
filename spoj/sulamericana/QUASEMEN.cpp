#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#define NN 500
#define INF 1061109567
using namespace std;
vector < vector < int > > p(500);
queue < int > q;
int n;
int adj[NN][NN];
void fastint(register int *n){
	(*n) = 0;
	register char c;
	while( c = getc( stdin ) ){
		switch(c){
			case ' ': case '\n': return;
			default: (*n) *= 10; (*n) += (c - '0'); break;
		}
	}
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
					d[i] = d[u] + adj[u][i],
					p[i].clear();
					p[i].push_back(u);
				} else if(temp == d[i])
					p[i].push_back(u);
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
	while(scanf("%d%d",&n,&E) && n){
		scanf("%d%d\n",&s,&d);
		for(i = 0; i < n; i++) p[i].clear();
		memset(adj,63,sizeof(adj));
		for(i = 0; i < E; i++){
			fastint(&a);
			fastint(&b);
			fastint(&adj[a][b]);
		}
		if((w = dijkstra(s,d)) == -1){ printf("-1\n"); continue;}
		q.push(d);
		while(!q.empty()){
			int k = q.front();
			q.pop();
			for(it = p[k].begin(); it != p[k].end(); it++)
				adj[(*it)][k] = INF, q.push((*it));
			p[k].clear();
		}
		printf("%d\n",dijkstra(s,d));
		
	}
	return 0;
}

