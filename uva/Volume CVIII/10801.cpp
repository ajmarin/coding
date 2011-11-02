#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

const int INF = 1 << 30, NN = 512;
#define FOR(i,n) for(int i = 0; i < n; ++i)
char line[4096];
int b[8], d[NN], floors[NN], next[NN], speed[8];
struct edge { int cost, from, to, next; } e[NN*NN];
int ec;

void add_edge(int from, int to, int cost){
	edge &E = e[ec];
	E.cost = cost;
	E.from = from;
	E.to = to;
	E.next = next[from];
	next[from] = ec++;
}

int dijkstra(int s, int t){
	FOR(i, NN) d[i] = INF;
	d[s] = 0;
	priority_queue < pair < int , int > > pq;
	pq.push( make_pair( 0, s ) );
	while(!pq.empty()){
		int cost = -pq.top().first, at = pq.top().second, temp, v;
		int base;
		for(base = 0; b[base + 1] <= at; ++base);
		pq.pop();
		if(cost == d[at]){
			if(floors[at] == t) return cost;
			for(int z = next[at]; z != -1; z = e[z].next){
				temp = cost + e[z].cost;
				v = e[z].to;
				if(temp < d[v]) pq.push( make_pair(-(d[v] = temp), v) );
			}
		}
	}
	return INF;
}

int main(void){
	b[0] = 1;
	for(int n, k; scanf("%d %d", &n, &k) == 2; ){
		int ans, *f, ttime;
		FOR(i, NN) next[i] = -1;
		ec = 0;
		FOR(i, n) scanf("%d", speed + i);
		scanf("\n");
		FOR(i, n){
			/* Read floors for elevator i */
			f = floors + b[i];
			gets(line);
			for(char *p = strtok(line, " "); p != NULL; p = strtok(NULL, " "))
				*f++ = atoi(p);
			if(floors[b[i]] == 0) add_edge(0, b[i], 0);
			b[i + 1] = f - floors;
			/* Add edges between elevator i floors */
			for(int j = b[i] + 1; j < b[i + 1]; ++j){
				ttime = (floors[j] - floors[j - 1]) * speed[i];
				add_edge(j - 1, j, ttime);
				add_edge(j, j - 1, ttime);
			}
			/* Add edges between elevator i and other elevators */
			FOR(j, i) for(int si = b[i], sj = b[j]; si < b[i + 1] && sj < b[j + 1]; ){
				if(floors[si] == floors[sj]){
					add_edge(si, sj, 60);
					add_edge(sj, si, 60);
				}
				si += floors[si] <= floors[sj];
				sj += floors[sj] < floors[si];
			}
		}
		if((ans = dijkstra(0, k)) == INF) puts("IMPOSSIBLE");
		else printf("%d\n", ans);
	}

	return 0;
}

