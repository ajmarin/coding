#include <cctype>
#include <cstdio>

#define NN 128
#define SS 50048
char g[NN][NN], ins[SS];
char map[128], *p;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void){
	int N, M, S;
	int dir, fig, x, y;
	map['N'] = 0; map['L'] = 1; map['S'] = 2; map['O'] = 3;
	while(scanf("%d %d %d", &N, &M, &S) && N){
		fig = 0;
		for(int i = 0; i < N; ++i){
			scanf("%s", &g[i]);
			char *p = g[i];
			for(int j = 0; j < M; ++j, ++p){
				if(isupper(*p)) dir = map[*p], x = i, y = j;
			}
		}
		scanf("%s", ins);
		p = ins;
		for(int i = 0; i < S; ++i, ++p){
			if(*p == 'F'){
				int nx = x + dx[dir], ny = y + dy[dir];
				if(nx < 0 || ny < 0 || nx >= N || ny >= M || g[nx][ny] == '#')
					continue;
				if(g[x = nx][y = ny] == '*') fig++, g[x][y] = '.';
			} else if(*p == 'D') dir = (dir + 1) % 4;
			else if(*p == 'E') dir = (dir + 3) % 4;
		}
		printf("%d\n", fig);
	}
	return 0;
}

