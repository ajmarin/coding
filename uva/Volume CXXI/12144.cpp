#include <cctype>
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
/* {{{ FAST integer input */
#define X10(n)	((n << 3) + (n << 1))
#define RI		readint
const int MAXR = 65536;
char buf[MAXR], *lim = buf + MAXR - 1, *now = lim + 1;
bool adapt(){ // Returns true if there is a number waiting to be read, false otherwise
	while(now <= lim && !isdigit(*now)) ++now;
	if(now > lim){
		int r = fread(buf, 1, MAXR-1, stdin);
		buf[r] = 0;
		lim = buf + r - 1;
		if(r == MAXR - 1){
			while(isdigit(*lim)) ungetc(*lim--, stdin);
			if(*lim == '-') ungetc(*lim--, stdin);
		}
		now = buf;
	}
	while(now <= lim && !isdigit(*now)) ++now;
	return now <= lim;
}
bool readint(int& n){ // Returns true on success, false on failure
	if(!adapt()) return false;
	bool ngtv = *(now - 1) == '-';
	for(n = 0; isdigit(*now); n = X10(n) + *now++ - '0');
	if(ngtv) n = -n;
	return true;
}
/* }}} end FAST integer input */
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
	while(RI(n) && RI(E) && n){
		RI(s), RI(d);
		for(i = 0; i < n; i++) p[i].clear();
		memset(adj,63,sizeof(adj));
		for(i = 0; i < E; i++) RI(a), RI(b), RI(adj[a][b]);
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

