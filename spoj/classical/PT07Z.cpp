#include <cstdio>
#include <vector>
using namespace std;
const int N = 10048;
vector < int > adj[N];
int dep[N], q[N], qh, qt, v[N];
int bfs(int x, int w, int &midx){
	int cd, maxd = 0, sz;
	dep[x] = qh = qt = 0;
	q[qt++] = x;
	v[x] = w;
	while(qh != qt){
		cd = dep[x = q[qh++]];
		sz = adj[x].size();
		for(int i = 0; i < sz; ++i){
			int nx = adj[x][i];
			if(v[nx] != w){
				v[q[qt++] = midx = nx] = w;
				maxd = dep[nx] = cd + 1;
			}
		}
	}
	return maxd;
}
int max(int a, int b){ return a > b ? a : b; }

int main(void){
	int a, ans = 0, b, idx, n; scanf("%d", &n);
	while(--n){
		scanf("%d %d", &a, &b); --a; --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	ans = max(ans, bfs(0, 2, idx));
	ans = max(ans, bfs(idx, 1, idx));
	printf("%d\n", ans);
	return 0;
}

