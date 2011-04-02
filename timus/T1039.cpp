#include <cstdio>
#include <vector>
using namespace std;
const int N = 6005;
int dp[N][2], leaf[N], v[N];
vector < int > adj[N];
int max(int a, int b){ return a > b ? a : b; }
void dfs(int k){
	int sz = adj[k].size();
	for(int i = 0; i < sz; ++i){
		int son = adj[k][i];
		dfs(son);
		dp[k][0] += max(dp[son][1], dp[son][0]);
		dp[k][1] += dp[son][0];
	}
#ifdef DBG
	printf("Use %d -> %d, dont -> %d\n", k, dp[k][1], dp[k][0]);
#endif
}
int main(void){
	for(int n; scanf("%d", &n) == 1; ){
		for(int i = 1; i <= n; ++i){
			scanf("%d", v + i);
			leaf[i] = 1;
			dp[i][0] = 0;
			dp[i][1] = max(v[i], 0);
			adj[i].clear();
		}
		for(int a, b; scanf("%d %d", &a, &b) && (a | b); ){
			adj[b].push_back(a);
			leaf[a] = 0;
		}
		for(int i = 1; i <= n; ++i)
			if(leaf[i]){
				dfs(i);
				printf("%d\n", max(dp[i][0], dp[i][1]));
			}
	}
	return 0;
}

