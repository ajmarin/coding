#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
const int N = 3072;
vector < pair < int, int > > adj[N];
int v[N], p[N];
int find(int x){ return p[x] == -1 ? x : p[x] = find(p[x]); }
bool uf(int a, int b){
	if((a = find(a)) ==  (b = find(b))) return false;
	p[b] = a;
	return true;
}
struct edge {
	int f, t, w;
	bool operator<(const edge e) const {
		return w < e.w;
	}
} e[100000];

int main(void){
	int t; scanf("%d", &t);
	for(int a, b, c, cn = 0, n, r, x, y; cn++ < t; ){
		scanf("%d %d", &n, &r);
		for(int i = 0; i < n; ++i) adj[i].clear(), p[i] = -1;
		for(int i = 0; i < r; ++i){
			scanf("%d %d %d", &a, &b, &c);
			if(a > b) swap(a, b);
			e[i].f = --a;
			e[i].t = --b;
			e[i].w = c;
		}
		sort(e, e + r);
		/* MST (Kruskal) */
		for(int ec = 1, i = 0; ec != n; ++i){
			x = e[i].f, y = e[i].t;
			if(uf(x, y)){
				adj[x].push_back(make_pair(e[i].w, y));
				adj[y].push_back(make_pair(e[i].w, x));
				++ec;
			}
		}
		printf("Case %d\n", cn);
		scanf("%d", &r);
		while(r--){
			scanf("%d %d", &a, &b); --a; --b;
			//printf("Path (%d, %d)\n", a, b);
			queue < int > q;
			for(int i = 0; i < n; ++i) v[i] = -1;
			q.push(a); v[a] = 0;
			while(!q.empty()){
				int at = q.front(), sz = adj[at].size(), to; q.pop();
				for(int i = 0; i < sz; ++i){
					to = adj[at][i].second;
					if(v[to] != -1) continue;
					v[to] = max(adj[at][i].first, v[at]);
					q.push(to);
				}
				if(v[b] != -1) break;
			}
			printf("%d\n", v[b]);
		}
		puts("");
	}
	return 0;
}

