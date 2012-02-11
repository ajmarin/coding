#include <cstdio>
#include <vector>
using namespace std;

struct edge {
	int next, to;
	edge(int _next, int _to): next(_next), to(_to) {}
};
class Tarjan {
	vector<int> index, lowlink, next, scc, stack;
	vector<edge> g;
	vector<bool> stacked;
	int cnt, idx, n, top;
	
	void strongconnect(int u){
		int at, v;

		index[u] = lowlink[u] = idx++;
		stack[top++] = u;
		stacked[u] = true;

		for(at = next[u]; at != -1; at = g[at].next){
			v = g[at].to;
			if(index[v] == -1){
				strongconnect(v);
				lowlink[u] = min(lowlink[u], lowlink[v]);
			} else if(stacked[v]){
				lowlink[u] = min(lowlink[u], index[v]);
			}
		}
		if(lowlink[u] == index[u]){
			++cnt;
			do { 
				scc[v = stack[--top]] = cnt;
				stacked[v] = false;
			} while(v != u);
		}
	}
public:
	vector<int> run(int &scc_cnt){
		for(int i = 0; i < n; ++i) if(index[i] == -1) strongconnect(i); 
		scc_cnt = cnt;
		return scc;
	}
	Tarjan(int n, vector<edge>& graph, vector<int>& next){
		this->g = graph;
		this->n = n;
		this->next = next;
		index = vector<int>(n, -1);
		lowlink = vector<int>(n);
		scc = vector<int>(n);
		stack = vector<int>(n);
		stacked = vector<bool>(n, false);
		cnt = idx = top = 0;
	}
};

int main(void){
	scanf("%*d");
	for(int n, z; scanf("%d %d", &n, &z) == 2; ){
		vector<edge> g;
		vector<int> next(n, -1);
		for(int cnt = 0, from, to; z && scanf("%d %d", &from, &to) == 2; --z){
			--from, --to;
			g.push_back(edge(next[from], to));
			next[from] = cnt++;
		}
		Tarjan t(n, g, next);
		int answer = 0, sccs = 0;
		vector<int> scc = t.run(sccs);
		vector<int> in_edge(sccs, 0);
		for(int i = 0, j; i < n; ++i){
			for(int at = next[i]; at != -1; at = g[at].next){
				j = g[at].to;
				in_edge[scc[j]] += scc[i] != scc[j];
			}
		}
		for(int i = 0; i < sccs; ++i) answer += !in_edge[i];
		printf("%d\n", answer);
	}
	return 0;
}

