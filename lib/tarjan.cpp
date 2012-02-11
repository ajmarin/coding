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

