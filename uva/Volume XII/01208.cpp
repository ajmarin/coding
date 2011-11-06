#include <algorithm>
#include <cstdio>
using namespace std;

#define FOR(i,n) for(int i = 0; i < n; ++i)
const int NN = 128;
struct edge { 
	int f, t, w;
	bool operator<(const edge& e) const {
		return w < e.w || (w == e.w && (f < e.f || (f == e.f && t < e.t)));
	}
} e[NN * NN];
int edges = 0, p[NN];

void add_edge (int f, int t, int w){
	edge &E = e[edges++];
	E.f = f;
	E.t = t;
	E.w = w;
}

int root(int x){ return p[x] == x ? x : p[x] = root(p[x]); }
bool union_find(int x, int y){ p[x = root(x)] = y = root(y); return x != y; }

int main(void){
	int t; scanf("%d", &t);
	for(int cnum = 0, n, z; cnum++ < t && scanf("%d", &n) == 1; edges = 0){
		FOR(i, n){
			p[i] = i;
			FOR(j, n){
				scanf("%d,", &z);
				if(z && i < j) add_edge(i, j, z);
			}
		}
		sort(e, e + edges);
		printf("Case %d:\n", cnum);
		int cnt = 0;
		FOR(i, edges){
			if(union_find(e[i].f, e[i].t) && ++cnt)
				printf("%c-%c %d\n", 'A' + e[i].f, 'A' + e[i].t, e[i].w);
			if(cnt == n - 1) break;
		}
	}
	return 0;
}

