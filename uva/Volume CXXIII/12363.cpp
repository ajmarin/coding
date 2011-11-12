#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

const int NN = 10048;
int n;
vector<int> adj[NN];
stack< pair<int, int> > s;									// BCC
int num[NN], low[NN], p[NN];
int cnt;


int root(int x){ return p[x] == x ? x : p[x] = root(p[x]); }
bool union_find(int a, int b){
	p[a = root(a)] = b = root(b);
	return a != b;
}
void dfs(int u, int prnt = -1) {
	low[u] = num[u] = cnt++;

	for(int i = 0; i < (int)adj[u].size(); i++) {
		int v = adj[u][i];
		if(num[v] == -1) {
			s.push(make_pair(u, v));						// BCC
			dfs(v, u);
			low[u] = min(low[u], low[v]);

			if(low[v] == num[v]) {
				/* u-v eh ponte */
				union_find(u, v);
//				printf("found bridge: %d-%d\n", u, v);
			}
		} else if(v != prnt) {
			if(num[v] < num[u]) s.push(make_pair(u, v));	// BCC
			low[u] = min(low[u], num[v]);
		}
	}
}

void findcuts(void) {
	memset(num, -1, sizeof(num));
	for(int i = 0; i < n; i++)
		if(num[i] == -1) cnt = 0, dfs(i);
}

int main(void){
	for(int c, q; scanf("%d %d %d", &n, &c, &q) == 3 && n; ){
		for(int i = 0; i < n; ++i){
			adj[i].clear();
			p[i] = i;
		}
		for(int a, b, i = 0; i < c; ++i){
			scanf("%d %d", &a, &b);
			--a;
			--b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		findcuts();
		for(int a, b, i = 0; i < q; ++i){
			scanf("%d %d", &a, &b);
			puts(root(--a) == root(--b) ? "Y" : "N");
		}
		puts("-");
	}
	return 0;
}

