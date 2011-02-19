#include <cstdio>
#include <vector>
using namespace std;
vector < int > adj[10048];
int d[10048];
bool has_cycle(int k, int dep){
	bool r = false;
	int sz = adj[k].size();
	d[k] = dep;
	for(int i = 0; i < sz; ++i){
		int x = adj[k][i];
		if(d[x] && d[x] < dep - 1) return true;
		if(!d[x]) r |= has_cycle(x, dep + 1);
	}
	return r;
}
int main(void){
	int a, b, i, m, n, r; scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i) d[i] = 0;
	for(i = 0; i < m; ++i){
		scanf("%d %d", &a, &b);
		adj[--a].push_back(--b);
		adj[b].push_back(a);
	}
	bool ok = !has_cycle(0, 1);
	for(int i = 0; i < n; ++i) ok &= !!d[i];
	puts(ok ? "YES" : "NO");
	return 0;
}
		
