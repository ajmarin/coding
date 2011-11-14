#include <cstdio>

const int INF = 1 << 30, NN = 32;
char board[NN][NN];
struct edge { int from, to, w; } e[4*NN*NN];
int d[NN*NN], ecnt;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

#define FOR(i, n) for(int i = 0; i < n; ++i)

int mask(int x, int y){ return (x << 5) | y; }

void add_edge(int from, int to, int w){
	edge &E = e[ecnt++];
	E.from = from;
	E.to = to;
	E.w = w;
}

int main(void){
	for(int c, h, w, x, y, x2, y2, E, G; scanf("%d %d", &w, &h) == 2 && w; ){
		ecnt = 0;
		FOR(i, w) FOR(j, h) board[i][j] = 0, d[mask(i, j)] = INF;
		board[w - 1][h - 1] = 'E';
		d[0] = 0;
		// Read Gravestones
		scanf("%d", &G);
		FOR(i, G){
			scanf("%d %d", &x, &y);
			board[x][y] = 'G';
		}
		// Read Haunted Holes
		scanf("%d", &E);
		FOR(i, E){
			scanf("%d %d %d %d %d", &x, &y, &x2, &y2, &c);
			add_edge(mask(x, y), mask(x2, y2), c);
			board[x][y] = 'E';
		}
		FOR(i, w) FOR(j, h) if(!board[i][j]) FOR(dir, 4){
			x = i + dx[dir], y = j + dy[dir];
			if(x >= 0 && x < w && y >= 0 && y < h && board[x][y] != 'G')
				add_edge(mask(i, j), mask(x, y), 1);
		}
		// Bellman-Ford to check for negative-weight cycles
		// and find distance between (0, 0) and (W-1, H-1)
		int vertices = w * h - G - 1;
		FOR(i, vertices) FOR(j, ecnt){
			int from = e[j].from, to = e[j].to;
			if(d[from] != INF && d[from] + e[j].w < d[to]) d[to] = d[from] + e[j].w;
		}
		bool never = false;
		FOR(j, ecnt){
			int from = e[j].from, to = e[j].to;
			if(d[from] != INF && d[from] + e[j].w < d[to]) never = true;
		}
		if(never) puts("Never");
		else if(d[mask(w-1, h-1)] == INF) puts("Impossible");
		else printf("%d\n", d[mask(w - 1, h - 1)]);
	}
	return 0;
}

