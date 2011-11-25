#include <cstdio>

const int NN = 128;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
char b[NN][NN];
bool v[NN][NN];
int n;

void dfs(int x, int y){
	v[x][y] = true;
	for(int dir = 0; dir < 4; ++dir){
		int nx = x + dx[dir], ny = y + dy[dir];
		if(nx >= 0 && nx < n && ny >= 0 && ny < n &&
			b[nx][ny] != '.' && !v[nx][ny])
			dfs(nx, ny);
	}
}

int main(void){
	int t; scanf("%d", &t);
	for(int c = 0; c++ < t; ){
		scanf("%d\n", &n);
		for(int line = 0; line < n; ++line){
			gets(b[line]);
			for(int col = 0; col < n; ++col)
				v[line][col] = false;
		}
		int ans = 0;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				if(b[i][j] == 'x' && !v[i][j]){
					dfs(i, j);
					++ans;
				}
		printf("Case %d: %d\n", c, ans);
	}
}

