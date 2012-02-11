#include <cstdio>
#include <cstring>

#define VALID(x,y) (x >= 0 && x < n && y >= 0 && y < m)
const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int cnt, m, n; 

char b[128][128];
bool v[128][128];

void dfs(int x, int y){
	int nx, ny;
	++cnt;
	v[x][y] = true;
	for(int d = 0; d < 8; ++d){
		nx = x + dx[d], ny = y + dy[d];
		if(VALID(nx, ny) && !v[nx][ny] && b[nx][ny] == 'W')
			dfs(nx, ny);
	}
}

int main(void){
	for(int t = 1; --t || scanf("%d\n\n", &t) == 1; ){
		for(n = 0; fgets(b[n], 128, stdin) && (*b[n] == 'L' || *b[n] == 'W'); ++n);
		for(m = 0; b[0][m] == 'L' || b[0][m] == 'W'; ++m);
//		printf("%d %d\n", n, m);
		for(int x, y; sscanf(b[n], "%d %d", &x, &y) == 2; ){
			cnt = 0;
			memset(v, 0, sizeof v);
//			printf("%d %d\n", x, y);
			dfs(--x, --y);
			printf("%d\n", cnt);
			if(!fgets(b[n], 128, stdin)) break;
		}
		if(t - 1) puts("");
	}
	return 0;
}

