#include <cstdio>

int m[3][3];
int dx[5] = {0, -1, 0, 1, 0};
int dy[5] = {0, 0, -1, 0, 1};

void play(int x, int y){
	int nx, ny;
	for(int dir = 0; dir < 5; ++dir){
		nx = x + dx[dir];
		ny = y + dy[dir];
		if(nx >= 0 && nx < 3 && ny >= 0 && ny < 3)
			++m[nx][ny];
	}
}

int main(void){
	char moves[256];
	for(int cnum = 1; fgets(moves, 256, stdin); ++cnum){
		for(int i = 0; i < 3; ++i)
			for(int j = 0; j < 3; ++j)
				m[i][j] = 0;
		for(int i = 0; moves[i]; ++i){
			moves[i] -= 'a';
			play(moves[i] / 3, moves[i] % 3);
		} 
		printf("Case #%d:\n", cnum);
		for(int i = 0; i < 3; ++i)
			for(int j = 0; j < 3; ++j)
				printf("%d%c", m[i][j] % 10, j == 2 ? 10 : 32);
	}
	return 0;
}

