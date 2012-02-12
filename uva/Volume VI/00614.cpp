#include <cstdio>

enum { WEST, NORTH, EAST, SOUTH };
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

bool w[16][16][4];
int maze[16][16];
int d[16][16], p[16][16];

int ex, ey, sx, sy;
bool done;

void dfs(int row, int col, int pd){
	done |= (row == ex && col == ey);
	if(done) return;
	int nc, nr;
	for(int dir = 0; dir < 4; ++dir){
		if(!w[row][col][dir] && (dir + 2) % 4 != pd){
			nr = row + dx[dir];
			nc = col + dy[dir];
			if(p[nr][nc] == -1){
				p[nr][nc] = (row << 4) | col;
				d[nr][nc] = d[row][col] + 1;
				dfs(nr, nc, dir);
				if(done) return;
			}
		}
	}
}
int main(void){
	int nmaze = 0;
	for(int r, c; scanf("%d%d%d%d%d%d", &r, &c, &sx, &sy, &ex, &ey) == 6 && (r || c); ){
		--sx, --sy, --ex, --ey;
		/* Clear everything */
		done = false;
		for(int i = 0; i < r; ++i) for(int j = 0; j < c; ++j){
			maze[i][j] = 0;
			for(int k = 0; k < 4; ++k) w[i][j][k] = false;
			d[i][j] = p[i][j] = -1;
		}
		/* Initialize walls */
		for(int i = 0, walls; i < r; ++i) for(int j = 0; j < c; ++j){
			scanf("%d", &walls);
			w[i][j][WEST] = (j == 0) | w[i][j - 1][EAST];
			w[i][j][NORTH] = (i == 0) | w[i - 1][j][SOUTH];
			w[i][j][EAST] = (j == c - 1) | (walls & 1);
			w[i][j][SOUTH] = (i == r - 1) | (walls & 2); 
		}
		/* Do a dfs to find the path */
		d[sx][sy] = 1;
		p[sx][sy] = (sx << 4) | sy;
		dfs(sx, sy, -1);
		/* Assign numbers to cells on the path */
		for(int m, x = ex, y = ey; ; m = p[x][y], x = m >> 4, y = m & 0xF){
			maze[x][y] = d[x][y];
			if(x == sx && y == sy) break;
		}
		/* Output */
		printf("Maze %d\n\n", ++nmaze);
		for(int row = 0; row < r; ++row){
			for(int col = 0; col < c; ++col){
				putc('+', stdout);
				if(w[row][col][NORTH]) printf("---");
				else printf("   ");
			}
			puts("+");
			for(int col = 0; col < c; ++col){
				putc(w[row][col][WEST] ? '|' : ' ', stdout);
				if(maze[row][col] > 0) printf("%3d", maze[row][col]);
				else if(p[row][col] != -1) printf("???");
				else printf("   ");
			}
			puts("|");
		}
		for(int col = 0; col < c; ++col) printf("+---");
		puts("+\n\n");
	}
	return 0;
}

