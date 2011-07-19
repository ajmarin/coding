#include <cstdio>
#define FOR(i,n)	for(int i = 0; i < n; ++i)
#define FORI(i,f,n)	for(int i = f; i < n; ++i)
const int MAXN = 512, MINPPA = 1<<31;
int adj[MAXN][MAXN], p[MAXN], cnt[MAXN];
int findroot(int x){
	return p[x] = p[x] == x ? x : findroot(p[x]);
}
void unionfind(int a, int b){
	int ra = findroot(a), rb = findroot(b);
	if(ra == rb) return;
	p[ra] = rb;
}
int max(int a, int b){ return a > b ? a : b; }
void swap(int &a, int &b){ int tmp = a; a = b; b = tmp; }
int main(void){
	for(int m, n; scanf("%d %d", &n, &m) == 2 && (m || n); ){
		int a, ans = 0, b, maxppa = MINPPA, ppa;
		FOR(i, n) cnt[i] = 0, p[i] = i;
		FOR(i, n) FORI(j, i + 1, n) adj[i][j] = MINPPA;
		FOR(i, m){
			scanf("%d %d %d", &a, &b, &ppa);
			--a; --b;
			if(a > b) swap(a, b);
			if(ppa > adj[a][b]){
				adj[a][b] = ppa;
				maxppa = max(maxppa, ppa);				
			}
		}
		FOR(i, n) FORI(j, i + 1, n) if(adj[i][j] == maxppa) unionfind(i, j);
		FOR(i, n) ans = max(ans, ++cnt[findroot(i)]);
		printf("%d\n", ans);
	}
	return 0;
}
