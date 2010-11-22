#include <cstdio>

const int NN = 256;
char m[NN][NN];
bool v[NN][NN];
int dx[6] = {-1, -1, 0, 0, 1, 1};
int dy[6] = {-1, 0, -1, 1, 0, 1};
int n;
bool dfs(int x, int y, char c){
	if(c == 'w' && y == n - 1) return 1;
	if(c == 'b' && x == n - 1) return 1;
	v[x][y] = 1;
	for(int d = 0; d < 6; ++d){
		int nx = x + dx[d], ny = y + dy[d];
		if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if(!v[nx][ny] && m[nx][ny] == c && dfs(nx, ny, c)) return 1;
	}
	return 0;
}
int main(void){
	for(int cnum = 1; scanf("%d", &n) == 1 && n; ++cnum){
		bool bw = 0, ww = 0;
		for(int i = 0; i < n; ++i){
			scanf("%s", m[i]);
			for(int j = 0; j < n; ++j) v[i][j] = 0;
		}
		for(int i = 0; i < n; ++i){
			if(!v[i][0] && m[i][0] == 'w') ww |= dfs(i, 0, 'w');
			if(!v[0][i] && m[0][i] == 'b') bw |= dfs(0, i, 'b');
			if(ww || bw) break;
		}
		printf("%d ", cnum);
		if(ww) puts("W"); else puts("B");
	}
	return 0;
}

