#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

#define FOR(i,n) for(int i = 0; i < n; ++i)

/* {{{ Ford Fulkerson */
#define INF 1048576
#define SINK 1
#define SOURCE 0

struct edge { int cap, flow, from, next, to; };

class FordFulkerson {
	vector < edge > g;
	int nodes;
	vector < int > next, p;
	vector < bool > vis;

	bool bfs(int s, int t){
		queue < int > q;
		int u, v;
		FOR(i, nodes) p[i] = -1, vis[i] = false;
		vis[s] = true;
		q.push(s);
		while(!q.empty() && !vis[t]){
			u = q.front();
			q.pop();
			for(int at = next[u]; at != -1; at = g[at].next){
				v = g[at].to;
				if(!vis[v] && g[at].cap - g[at].flow > 0){
					q.push(v);
					vis[v] = true;
					p[v] = at;
				}
			}
		}
		return vis[t];
	}
public:
	FordFulkerson(edge* edges, int ecnt, int* next, int n){
		this->g = vector< edge >(edges, edges + ecnt);
		this->next = vector< int >(next, next + n);
		p = vector< int >(n, -1);
		vis = vector< bool >(n, false);
		nodes = n;
	}
	int maxflow(int s, int t){
		int max_flow = 0, z = g.size();
		// Clear flow 
		FOR(i, z) g[i].flow = 0;
		// While there is a path from source to sink
		while(this -> bfs(s, t)){
			int path_cap = INF;
			// Find path capacity
			for(int i = p[t]; i != -1; i = p[g[i].from])
				path_cap = min(path_cap, g[i].cap - g[i].flow);

			// Adjust flow graph
			for(int i = p[t]; i != -1; i = p[g[i].from]){
				g[i].flow += path_cap;
				g[i^1].flow -= path_cap;
			}

			// Increment max_flow accordingly
			max_flow += path_cap;
		}
		return max_flow;
	}
};
/* }}} */

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

#define IN(x) (x + 2)
#define MASK(x,y) (x * c + y)
#define OUT(x) (x + nodes + 2)

int ecnt, next[1<<14];
edge e[1<<15];
void add_edge(int from, int to, int w){
	edge &E = e[ecnt];
	E.cap = w;
	E.flow = 0;
	E.from = from;
	E.next = next[from];
	E.to = to;
	next[from] = ecnt++;
}

int main(void){
	int t; scanf("%d", &t);
	for(int b, c, r; t-- && scanf("%d %d %d", &r, &c, &b) == 3; ){
		int mask, nodes = r * c, x, y;
		ecnt = 0;
		FOR(i, nodes*2+2) next[i] = -1;
		FOR(i, r) FOR(j, c){
			mask = MASK(i, j);
			add_edge(IN(mask), OUT(mask), 1);
			add_edge(OUT(mask), IN(mask), 0);
			if(!i || !j || i == r - 1 || j == c - 1){
				add_edge(OUT(mask), SINK, INF);
				add_edge(SINK, OUT(mask), 0);
			}
			FOR(dir, 4){
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				if(nx >= 0 && ny >= 0 && nx < r && ny < c){
					add_edge(OUT(mask), IN(MASK(nx, ny)), 1);
					add_edge(IN(MASK(nx,ny)), OUT(mask), 0);
				}
			}
		}
		FOR(i, b){
			scanf("%d %d", &x, &y);
			--x, --y;
			mask = MASK(x, y);
			add_edge(SOURCE, IN(mask), 1);
			add_edge(IN(mask), SOURCE, 0);
		}
		FordFulkerson ff(e, ecnt, next, 2 * nodes + 2);
		puts(ff.maxflow(SOURCE, SINK) == b ? "possible" : "not possible");
	}
	return 0;
}

