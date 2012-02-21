#include <cstdio>

int ecnt, next[10048], to[10048];
struct edge { int next, to, w; } e[10048];
int sv[10048][2];

void add_edge(int from, int to, int val){
	edge &E = e[ecnt];
	E.next = next[from];
	E.to = to;
	E.w = val;
	next[from] = ecnt++;
}

int main(void){
	for(int m, n; scanf("%d %d", &m, &n) == 2; ){
		int z = m > n ? m : n;
		ecnt = 0;
		for(int i = 0; i < z; ++i) next[i] = -1;
		for(int i = 0; i < m; ++i){
			scanf("%d", &z);
			for(int j = 0; j < z; ++j) scanf("%d", to + j);
			for(int j = 0, v; j < z; ++j){
				scanf("%d", &v);
				add_edge(to[j] - 1, i, v);
			}
		}
		printf("%d %d\n", n, m);
		for(int i = 0, cnt; i < n; ++i){
			cnt = 0;
			for(int at = next[i]; at != -1; at = e[at].next, ++cnt){
				sv[cnt][0] = e[at].to + 1;
				sv[cnt][1] = e[at].w;
			}
			printf("%d", cnt);
			if(!cnt) puts("\n");
			else putc(32, stdout);
			for(int j = cnt; j--; printf("%d%c", sv[j][0], j ? 32 : 10));
			for(int j = cnt; j--; printf("%d%c", sv[j][1], j ? 32 : 10));
		}
	}
	return 0;
}

