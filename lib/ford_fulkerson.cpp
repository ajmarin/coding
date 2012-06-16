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
