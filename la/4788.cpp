#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 128;
int ecnt, in[N], next[N], out[N], vis[N];

struct edge { int next, to; } e[N << 1];

void add_edge(int from, int to){
	edge &E = e[ecnt];
	E.next = next[from];
	E.to = to;
	next[from] = ecnt++;
}

pair<int, int> dfs(int u){
	vector< pair<int, int> > result;
	int soldiers = in[u], remaining = out[u];
	vis[u] = true;
	for(int at = next[u], v; at != -1; at = e[at].next)
		if(!vis[v = e[at].to]) result.push_back(dfs(v));
	sort(result.rbegin(), result.rend());
	for(int i = 0; i < int(result.size()); ++i){
		soldiers += max(result[i].second - remaining, 0);
		remaining = max(result[i].second, remaining) - (result[i].second - result[i].first);
	}
	return make_pair(remaining, soldiers);
}

int main(void){
	for(int cn = 0, n; scanf("%d", &n) == 1 && n; ){
		for(int a, b, c, i = 0; i < n; ++i){
			scanf("%d %d %d", &a, &b, &c);
			a = max(a, b + c);
			in[i] = a;
			next[i] = -1;
			out[i] = a - (b + c);
		}
		for(int a, b, i = ecnt = 0; ++i < n && scanf("%d %d", &a, &b) == 2; ){
			add_edge(--a, --b);
			add_edge(b, a);
		}
		int ans = 1 << 29;
		for(int i = 0; i < n; ++i){
			memset(vis, false, n << 2);
			ans = min(ans, dfs(i).second);
		}
		printf("Case %d: %d\n", ++cn, ans);
	}
	return 0;
}

