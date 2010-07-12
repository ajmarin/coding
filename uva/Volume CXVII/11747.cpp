#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
#define FOR(a,b,c) for(int a = b; a < c; ++a)
const int N = 1005;
const int M = 25005;
int e, n, p[N], re[M], rec;

struct edge {
	int u, v, w;
	bool operator<(const edge x) const { return w < x.w; }
} edges[M];
int find(int x){
	while(p[x] != -1) x = p[x];
	return x;
}
int main(void){
	while(scanf("%d %d", &n, &e) && n){
		rec = 0;
		FOR(i, 0, n) p[i] = -1;
		FOR(i, 0, e){
			scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
		}
		sort(edges, edges + e);
		FOR(i, 0, e){
			int ra = find(edges[i].u), rb = find(edges[i].v);
			if(ra == rb) re[rec++] = edges[i].w;
			else p[ra] = rb;
		}
		FOR(i, 0, rec){
			if(i) putc(32, stdout);
			printf("%d", re[i]);
		}
		if(!rec) printf("forest");
		putc(10, stdout);
	}
	return 0;
}
