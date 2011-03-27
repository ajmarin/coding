#include <cstdio>
#include <vector>
using namespace std;
const int INF = 0x3fffffff, N = 1024;
vector < int > adj[N];
int maxs, memo[N], w[N], x[N], y[N];
bool v[N];
int dfs(int k){
	int r = w[k], sz = adj[k].size();
	v[k] = 1;
	for(int i = 0; i < sz; ++i){
		if(v[adj[k][i]]) continue;
		int x = dfs(adj[k][i]);
		if(x > 0) r += x;
	}
#ifdef DBG
	printf("memo[%d (%d, %d)] = %d\n", k, x[k], y[k], memo[k]);
#endif
	return r;
}
int abs(int a){ return a < 0 ? -a : a; }
int max(int a, int b){ return a > b ? a : b; }
int main(void){
	int n, t; scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) memo[i] = INF, v[i] = 0;
		for(int i = 0; i < n; ++i){
			scanf("%d %d %d", x + i, y + i, w + i);
			for(int j = 0; j < i; ++j)
				if(abs(x[j] - x[i]) + abs(y[j] - y[i]) == 1){
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
		}
		maxs = 0;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j) v[i] = 0, memo[i] = INF;
			maxs = max(maxs, dfs(i)); 
		}
		printf("%d\n", maxs);
		for(int i = 0; i < n; ++i) adj[i].clear();
	}
	return 0;
}

