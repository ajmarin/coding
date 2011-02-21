#include <cmath>
#include <cstdio>
#define FOR(i,n)	for(int i = 0; i < n; ++i)
typedef long long LL;
const int N = 100;
struct e {
	int w; long long g, l;
	e(int _w=0, LL _g=0, LL _l=0): w(_w), g(_g), l(_l) {}
} adj[N][N];
int deg[N], v[N], m, n;
LL z[N];
template <class _T> _T gcd(_T a, _T b)	{ return b ? gcd(b, a %b) : a;	}
bool dfs(int x){
	v[x] = 2;
	FOR(k, deg[x]){
		e h = adj[x][k];
		if(v[h.w]){
			LL g = gcd(z[x], z[h.w]);
			if(g != h.g || g * h.l != z[x] * z[h.w]) return 0;
		} else {
			if(z[x] == 0) return 0;
			z[h.w] = h.l * h.g / z[x];
			if(!dfs(h.w)) return 0;
		}
	}
	return 1;
}
bool test(int idx, LL y){
	z[idx] = y;
	if(dfs(idx)) return 1;
	FOR(i, n) v[i] -= (v[i] == 2) << 1;
	return 0;
}
int main(void){
	int a, b, g, l;
	bool ok = 1, f;
	scanf("%d %d", &n, &m);
	FOR(i, n) deg[i] = v[i] = 0, z[i] = 1;
	FOR(i, m){
		scanf("%d %d %d %d", &a, &b, &g, &l); --a; --b;
		adj[a][deg[a]++] = e(b, g, l);
		adj[b][deg[b]++] = e(a, g, l);
		ok &= !(l % g);
	}
	FOR(i, n){
		if(v[i] || !deg[i]) continue;
		f = false;
		int lim; LL lcm;
		lim = int(sqrt(lcm = adj[i][0].l) + 1);
		for(int j = 1; j < lim; ++j){
			if(lcm % j) continue;
			if(f |= test(i, j)) break;
			if(f |= test(i, lcm / j)) break;
		}
		FOR(j, n) v[j] -= v[j] == 2;
		if(!(ok &= f)) break;
	}
	puts(ok ? "YES" : "NO");
	if(ok) FOR(i, n) printf("%I64d%c", z[i], i == n - 1 ? '\n' : ' ');
	return 0;
}

