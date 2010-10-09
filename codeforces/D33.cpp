#include <cmath>
#include <cstdio>

#define NN 1048
#define EPS 1e-9
#define FORI(a,b,c)	for(int a = b; a < c; ++a)
#define FOR(a,b)	FORI(a,0,b)
struct p2d { int p, x, y; } p[NN];
struct c2d { p2d c; int l, p, r; } c[NN];
bool inside(p2d &p, c2d &c){ return hypot(c.c.x - p.x, c.c.y - p.y) - c.r < EPS; }
int lca[NN][NN];
int m, n;
c2d *cp = c + 1;
void dfs(int k, int l){
	c[k].l = l;
	FOR(i, m) if(cp[i].p == k) dfs(i + 1, l + 1);
}
int lca_idx(int x, int y){
	if(lca[x][y] != -1) return lca[x][y];
	if(x == y) return lca[x][y] = x;
	if(c[x].l > c[y].l) return lca[x][y] = lca_idx(c[x].p, y);
	if(c[y].l > c[x].l) return lca[x][y] = lca_idx(x, c[y].p);
	return lca[x][y] = lca_idx(c[x].p, c[y].p);
}
int main(void){
	int a, b, k;
	scanf("%d %d %d", &n, &m, &k);
	FOR(i, n) scanf("%d %d", &p[i].x, &p[i].y);
	FOR(i, m) scanf("%d %d %d", &cp[i].r, &cp[i].c.x, &cp[i].c.y);
	FOR(i, n) {
		int minr = 0x7fffffff;
		p[i].p = 0;
		FOR(j, m){
			if(cp[j].r < minr && inside(p[i], cp[j])){
				minr = cp[j].r;
				p[i].p = j + 1;
			}
		}
	}
	FOR(i, m + 1){
		FOR(j, m + 1) lca[i][j] = -1;
		if(i == m) break;
		int minr = 0x7fffffff;
		cp[i].p = 0;
		FOR(j, m){
			if(i == j) continue;
			if(cp[j].r < minr && cp[j].r > cp[i].r && inside(cp[i].c, cp[j])){
				minr = cp[j].r;
				cp[i].p = j + 1;
			}
		}
	}
	dfs(0, 0);
	FOR(i, k){
		scanf("%d %d", &a, &b);
		a = a - 1; b = b - 1;
		int lcalevel = c[lca_idx(p[a].p, p[b].p)].l;
		printf("%d\n", c[p[a].p].l + c[p[b].p].l - (lcalevel << 1));
	}
	return 0;
}

