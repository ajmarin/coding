#include <cstdio>

char maze[64][64];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void){
	int t; scanf("%d", &t);
	for(int c, r, x, y; t-- && scanf(" %d %d\n", &r, &c) == 2; ){
		for(int i = 0; i < r; ++i) gets(maze[i]);
		scanf("%d %d", &x, &y);
		--x; --y;
		int dir = 0, nx, ny;
		for(char move = getc(stdin); move != 'Q'; move = getc(stdin)){
			switch(move){
				case 'F': 
					nx = x + dx[dir];
					ny = y + dy[dir];
					if(nx >= 0 && ny >= 0 && nx < r && ny < c && maze[nx][ny] != '*'){
						x = nx;
						y = ny;
					}
					break;
				case 'L': dir = (dir + 3) % 4; break;
				case 'R': dir = (dir + 1) % 4; break;
				default: break;
			}
		}
		printf("%d %d %c\n", ++x, ++y, "NESW"[dir]);
		if(t) puts("");
	}
	return 0;
}

