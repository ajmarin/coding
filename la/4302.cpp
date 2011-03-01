#include <cstdio>
#include <list>
using namespace std;
const int N = 200048;
list < pair < int , int > > adj[N];
int ans;
int dfs(int at, int p){
	int sum = 0;
	for(int z; !adj[at].empty(); adj[at].pop_back())
		if((z = adj[at].back().first) != p)
			sum += max(0, adj[at].back().second + dfs(z, at));
	ans = max(ans, sum);
	return sum;
}

int main(void){
	for(int a, b, c, n, r; scanf("%d", &n) == 1 && n; ){
		for(int i = 0; i < n; ++i){
			scanf("%d %d %d", &a, &b, &c);
			adj[r = a].push_back(make_pair(b, c));
			adj[b].push_back(make_pair(a, c));
		}
		ans = 0; dfs(r, r);
		printf("%d\n", ans);
	}
	return 0;
}

