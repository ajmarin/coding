#include <cstdio>

const int N = 1 << 10, NN = N << 10;
char m[N][N];
int c, dep[NN], q[NN], qh, qt, r, v[NN];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int bfs(int x, int w, int &midx){
	int cd, i, j, maxd = 0;
	dep[x] = qh = qt = 0;
	q[qt++] = midx = x;
	v[midx] = w;
	while(qh != qt){
		x = q[qh++], i = x >> 10, j = x & 1023;
		cd = dep[x];
		for(int d = 0; d < 4; ++d){
			int ni = i + dx[d], nj = j + dy[d];
			if(ni < 0 || nj < 0 || ni >= r || nj >= c) continue;
			if(m[ni][nj] == '.' && v[(ni << 10) + nj] != w){
				v[q[qt++] = midx = (ni << 10) + nj] = w;
				maxd = dep[midx] = cd + 1;
			}
		}
	}
	return maxd;
}
int max(int a, int b){ return a > b ? a : b; }

int main(void){
	int ans, idx, t;
	for(scanf("%d", &t); t-- && scanf("%d %d", &c, &r); ){
		ans = 0;
		for(int i = 0; i < r; ++i){
			scanf("%s", m[i]);
			for(int j = 0, k = i << 10; j < c; ++j) v[k + j] = 0;
		}
		for(int i = 0; i < r; ++i)
			for(int j = 0; j < c; ++j)
				if(m[i][j] == '.' && !v[(i << 10) + j]){
					ans = max(ans, bfs((i << 10) + j, 2, idx));
					ans = max(ans, bfs(idx, 1, idx));
				}
		printf("Maximum rope length is %d.\n", ans);
						
	}
	return 0;
}

