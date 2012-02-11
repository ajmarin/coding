#include <cstdio>
#include <cstdlib>
#include <cstring>

#define VALID(x,y) (x >= 0 && x < n && y >= 0 && y < n)
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

bool seen[128];
char line[16384];
int m[128][128], v[128][128];
int cnt, n;

void dfs(int x, int y){
	int nx, ny;
	++cnt;
	v[x][y] = true;
	for(int d = 0; d < 4; ++d){
		nx = x + dx[d], ny = y + dy[d];
		if(VALID(nx,ny) && !v[nx][ny] && m[nx][ny] == m[x][y])
			dfs(nx, ny);
	}
}
int main(void){
	while(scanf("%d\n", &n) == 1 && n){
		bool wrong = false;
		for(int i = 0; i < n; ++i){
			seen[i] = false;
			for(int j = 0; j < n; ++j){
				m[i][j] = v[i][j] = false;
			}
		}
		for(int i = 1, x, y; i < n; ++i){
			fgets(line, 16384, stdin);
			for(char *num = strtok(line, " "); num != NULL; num = strtok(NULL, " ")){
				x = atoi(num) - 1;
				y = atoi(num = strtok(NULL, " ")) - 1;
				if(VALID(x, y))	m[x][y] = i;
				else wrong = true;
			}
		}
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				wrong |= !v[i][j] && seen[m[i][j]];
				if(!seen[m[i][j]]){
					seen[m[i][j]] = true;
					cnt = 0;
					dfs(i, j);
					wrong |= cnt != n;
				}
			}
		}
		puts(wrong ? "wrong" : "good");
	}
	return 0;
}

