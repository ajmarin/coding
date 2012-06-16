#include <cstdio>
#include <map>
#include <string>
using namespace std;

#define FOR(i,n) for(int i = 1; i <= n; ++i)
#define SAFE(x) (x >= 18 && x <= 42)
const int NN = 128;
struct edge { int a, d, next, to; } e[1024];

map < string, int > m;
int ccnt, ecnt, next[NN];

int get_index(char *city){
	int &z = m[city];
	if(!z){ z = ++ccnt; next[z] = -1; }
	return z;
}

void add_edge(int from, int to, int departure, int arrival){
	edge &E = e[ecnt];
	E.a = arrival;
	E.d = departure;
	E.next = next[from];
	E.to = to;
	next[from] = ecnt++;
}

int dijkstra(int from, int to){
	static int d[NN][2], vis[NN];
	int at, L, u = from, v;
	int minL = 0, minT = 25;
	FOR(i, ccnt) vis[i] = false, d[i][0] = 1<<20;
	for(d[u][0] = 0, d[u][1] = 18; u != to && minL != 1 << 20; ){
		vis[u] = true;
		for(at = next[u]; at != -1; at = e[at].next){
			if(vis[v = e[at].to]) continue;
			L = d[u][0] + (d[u][1] > e[at].d);
			if(L < d[v][0] || (L == d[v][0] && e[at].a < d[v][1])) d[v][0] = L, d[v][1] = e[at].a;
		}
		minL = 1 << 20;
		minT = 25;
		FOR(i, ccnt) if(!vis[i] && (d[i][0] < minL || (d[i][0] == minL && d[i][1] < minT))){
			u = i; minL = d[i][0]; minT = d[i][1];
		}
	}
	return d[to][0];
}
int main(void){
	int t; scanf("%d", &t);
	char from[64], to[64];
	for(int c = 0, n; c++ < t; ){
		ccnt = ecnt = 0;
		m.clear();
		scanf("%d", &n);
		for(int a, arrival, b, departure; n--; ){
			scanf("%s %s %d %d", from, to, &departure, &arrival);
			a = get_index(from);
			b = get_index(to);
			arrival += departure += (departure <= 6 ? 24 : 0);
			if(departure >= 18 && arrival <= 30) add_edge(a, b, departure, arrival);
		}
		scanf("%s %s", from, to);
		n = dijkstra(get_index(from), get_index(to));
		printf("Test Case %d.\n", c);
		if(n == 1 << 20) puts("There is no route Vladimir can take.");
		else printf("Vladimir needs %d litre(s) of blood.\n", n);
	}
	return 0;
}

