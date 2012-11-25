#include <cstdio>
#include <cstring>

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
#define FOR(i,n) for(int i = 0; i < n; ++i)
#define FORI(i,s,n) for(int i = s; i < n; ++i)

char board[16][16], test[16][16];

void toggle(int x, int y, int &p){
	int nx, ny;
	++p;
	test[x][y] = 1 - test[x][y];
	FOR(dir, 4){
		nx = x + dx[dir];
		ny = y + dy[dir];
		if(nx >= 0 && ny >= 0 && nx < 10 && ny < 10)
			test[nx][ny] = 1 - test[nx][ny];
	}
}

void copy_board(){ FOR(i, 10) FOR(j, 10) test[i][j] = board[i][j]; }

bool check(){
	FOR(j, 10) if(test[9][j]) return false;
	return true;
}

int main(void){
	for(char name[1024]; scanf("%s", name) == 1 && strcmp(name, "end"); ){
		int ans = 101, press;
		FOR(i, 10){
			scanf("%s", board[i]);
			FOR(j, 10) board[i][j] = board[i][j] == 'O';
		}
		FOR(mask, 1 << 10){
			press = 0;
			copy_board();
			FOR(i, 10) if(mask & (1 << i)) toggle(0, i, press);
			FORI(i, 1, 10){
				FOR(j, 10) if(test[i - 1][j]) toggle(i, j, press);
				if(press >= ans) break;
			}
			if(press < ans && check()) ans = press;
		}
		printf("%s %d\n", name, ans == 101 ? -1 : ans);
	}
	return 0;
}

