#include <cstdio>
#include <map>
#include <string>
using namespace std;
#define FOR(i,n)	for(int i = 0; i < n; ++i)

const int INF = 0x3F3F3F3F, NN = 128;
int g[NN][NN], cities;
map < string, int > m;

int min(int a, int b){ return a < b ? a : b; }

int get_idx(string s){
	map < string, int > :: iterator it = m.find(s);
	int r;
	if(it == m.end()) r = m[s] = cities++;
	else r = it -> second;
	return r;
}

int main(void){
	char from[16], origin[16], to[16];
	char ft[8], tf[8];
	for(int c, cnum(1), n, r; scanf("%d %d %d", &n, &c, &r) == 3 && (n + c + r); ){
		int ans(0), cnt[n], oidx, w;
		m.clear();
		cities = 0;
		FOR(i, n){
			FOR(j, n) g[i][j] = INF;
			cnt[i] = g[i][i] = 0;
		}
		scanf("%s", origin);
		oidx = get_idx(origin);
		FOR(i, c) scanf("%s", from), ++cnt[get_idx(from)];
		FOR(i, r){
			scanf("%s %[<-]%d%[->] %s", from, tf, &w, ft, to);
			int fidx = get_idx(from), tidx = get_idx(to);
			if(ft[1] == '>') g[fidx][tidx] = min(g[fidx][tidx], w);
			if(tf[0] == '<') g[tidx][fidx] = min(g[tidx][fidx], w);
		}
		FOR(k, n) FOR(i, n) FOR(j, n)
			g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
		FOR(i, n) ans += cnt[i] * (g[oidx][i] + g[i][oidx]);
		printf("%d. %d\n", cnum++, ans);
	}
	return 0;
}

