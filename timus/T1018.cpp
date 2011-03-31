#include <cstdio>
#include <utility>
using namespace std;
const int N = 128;
int deg[N], dp[N][N], n, q;
pair < int, int > adj[N][3];
int max(int a, int b){ return a > b ? a : b; }
void dfs(int k, int p){
	int *left, *right, cl, cr;
	left = right = dp[k];
	for(int i = 0; i < deg[k]; ++i){
		int to = adj[k][i].first, cost = adj[k][i].second;
		if(to == p) continue;
		if(left == dp[k]) left = dp[to], cl = cost;
		else right = dp[to], cr = cost;
		dfs(to, k);
	}
	if(left != right){
		for(int a = 0; a <= q; ++a)
			for(int b = 0; a + b <= q; ++b)
				if(a && left[a-1] != ~0 && b && right[b-1] != ~0) 
					dp[k][a+b] = max(dp[k][a+b], left[a-1] + cl + cr + right[b-1]);
				else if(a && left[a-1] != ~0)
					dp[k][a] = max(dp[k][a], left[a-1] + cl);
				else if(b && right[b-1] != ~0)
					dp[k][b] = max(dp[k][b], right[b-1] + cr);
	}
}
int main(void){
	for(int x, y, z; scanf("%d %d", &n, &q) == 2; ){
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j) dp[i][j] = ~0 + !j;
			deg[i] = 0;
		}
		for(int i = 1; i < n; ++i){
			scanf("%d %d %d", &x, &y, &z);
			adj[x][deg[x]++] = make_pair(y, z);
			adj[y][deg[y]++] = make_pair(x, z);
		}
		dfs(1, 0);
		printf("%d\n", dp[1][q]);
	}
	return 0;
}

