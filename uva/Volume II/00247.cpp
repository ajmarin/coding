#include <cstdio>
#include <map>
#include <string>
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
			do { 
				scc[v = stack[--top]] = cnt;
				stacked[v] = false;
			} while(v != u);
			++cnt;
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

map < string, int > msi;
char from[32], to[32];
string names[32];
int ncnt;

int get_id(string name){
	map< string, int >::iterator it = msi.find(name);
	if(it == msi.end()){
		names[ncnt] = name;
		return msi[name] = ncnt++;
	} 
	return it -> second;
}
int main(void){
	bool firstin = true;
	for(int dsn(0), n, m; scanf("%d %d", &n, &m) == 2 && n; ){
		int a, b, cnt = 0, sccs;
		vector<edge> edges;
		vector<int> next(n, -1);
		vector<int> circles;
		ncnt = 0;
		if(!firstin) puts("");
		firstin = false;
		msi.clear();
		for(int i = 0; i < m; ++i){
			scanf("%s %s", from, to);
			a = get_id(from);
			b = get_id(to);
			edges.push_back(edge(next[a], b));
			next[a] = cnt++;
		}
		Tarjan t(n, edges, next);
		circles = t.run(sccs);
		printf("Calling circles for data set %d:\n", ++dsn);
		for(int i = 0; i < sccs; ++i){
			bool first = true;
			for(int j = 0; j < n; ++j)
				if(circles[j] == i){
					if(!first) printf(", ");
					printf("%s", names[j].c_str());
					first = false;
				}
			puts("");
		}
	}
	return 0;
}

