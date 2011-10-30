#include <cctype>
#include <cstdio>
#include <queue>
using namespace std;
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

#define FOR(i,n) for(int i = 0; i < n; ++i)
const int INF = 1 << 30, NN = 20005, MM = 100005;
struct edge { int from, to, cost, next; } e[MM];
int d[NN], last[NN], ec, n;

void add_edge(int from, int to, int cost){
	e[ec].from = from;
	e[ec].to = to;
	e[ec].cost = cost;
	e[ec].next = last[from];
	last[from] = ec++;
}

int dijkstra(int s, int t){
	FOR(i, n) d[i] = INF;
	priority_queue < pair< int, int > > pq;
	d[s] = 0;
	pq.push(make_pair(0, s));
	while(!pq.empty()){
		int cost = -pq.top().first, at = pq.top().second, temp;
		pq.pop();
		if(d[at] == cost){
			if(at == t) break;
			for(int z = last[at]; z != -1; z = e[z].next){
				temp = cost + e[z].cost;
				if(d[e[z].to] > temp){
					d[e[z].to] = temp;
					pq.push(make_pair(-temp, e[z].to));
				}
			}
		}
	}
	return d[t];
}
int main(void){
	int a, b, c = 1, t, w; RI(t);
	for(int m, y, z; t-- && (RI(n) + RI(m) + RI(y) + RI(z)) == 4; ){
		ec = 0; // clear edge counter
		FOR(i, n) last[i] = -1; // clear edge list
		FOR(i, m){ // read edges
			RI(a), RI(b), RI(w);
			add_edge(a, b, w);
			add_edge(b, a, w);
		}
		printf("Case #%d: ", c++);
		m = dijkstra(y, z);
		if(m == INF) puts("unreachable");
		else printf("%d\n", m);

	}
	return 0;
}

