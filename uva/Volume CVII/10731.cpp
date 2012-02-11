#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

vector<bool> seen;
int ecnt;

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
		for(int i = 0; i < n; ++i) if(seen[i] && index[i] == -1) strongconnect(i); 
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

void add_edge(vector<edge>&g, vector<int>& next, int from, int to){
	if(from != to){
		g.push_back(edge(next[from], to));
		next[from] = ecnt++;
	}
}
int main(void){
	bool first = true;
	for(int n; scanf("%d\n", &n) == 1 && n; ){
		vector<edge> g;
		vector<int> next(26, -1);
		char a, b, c, d, e, f, line[1024];
		seen = vector<bool>(26, false);
		ecnt = 0;
		if(!first) puts("");
		first = false;
		for(int i = 0; i < n; ++i){
			fgets(line, 1024, stdin);
			a = *strtok(line, " ") - 'A';
			b = *strtok(NULL, " ") - 'A';
			c = *strtok(NULL, " ") - 'A';
			d = *strtok(NULL, " ") - 'A';
			e = *strtok(NULL, " ") - 'A';
			f = *strtok(NULL, " ") - 'A';
			seen[a] = seen[b] = seen[c] = seen[d] = seen[e] = seen[f] = true;
			add_edge(g, next, f, a);
			add_edge(g, next, f, b);
			add_edge(g, next, f, c);
			add_edge(g, next, f, d);
			add_edge(g, next, f, e);
		}
		Tarjan t(26, g, next);
		int sccs;
		vector<int> scc = t.run(sccs);
		vector<bool> shown(26, false);
		for(int i = 0; i < sccs; ++i){
			int first = 1, nscc = -1;
			for(int j = 0; j < 26; ++j){
				if(nscc == -1 && seen[j] && !shown[j]) nscc = scc[j];
				if(seen[j] && scc[j] == nscc){
					if(!first) putc(32, stdout);
					first = 0;
					printf("%c", j + 'A');
					shown[j] = true;
				}
			}
			puts("");
		}
	}
	return 0;
}

