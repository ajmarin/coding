#include <algorithm>
#include <cassert>
#include <cstdio>

#define FOR(i, n) for(int i = 0; i < n; ++i)
#define VALID(x, y) (x > -1 && y > -1 && x < row && y < col)
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

bool v[64][64];
char board[64][64];
int box_pos[16][2], cost[16][16], q[1 << 12][2], value[64][64];
int dp[16][1 << 15];
int col, head, row, tail;

void push(int z, int d){ q[tail][0] = z; q[tail][1] = d; ++tail; }

void bfs(int box){
	int d, nx, ny, x, y;
	head = tail = 0;
	FOR(i, row) FOR(j, col) v[i][j] = false;
	push((box_pos[box][0] << 6) | box_pos[box][1], 0);
	v[box_pos[box][0]][box_pos[box][1]] = true;
	while(head != tail){
		d = q[head][1], x = q[head][0] >> 6, y = q[head][0] & 0x3F;
		if(board[x][y] == 'X') cost[box][value[x][y]] = d;
		++head;
		FOR(dir, 4){
			nx = x + dx[dir];
			ny = y + dy[dir];
			if(VALID(nx, ny) && board[nx][ny] != '#' && !v[nx][ny]){
				push((nx << 6) | ny, d + 1);
				v[nx][ny] = true;
			}
		}
	}
}

int main(void){
	int t; scanf("%d", &t);
	while(t--){
		scanf("%d %d", &row, &col);
		FOR(i, row) scanf("%s", board[i]);
		int box_count = 0, x_count = 0;
		FOR(i, row) FOR(j, col){
			if(board[i][j] == 'B'){
				box_pos[box_count][0] = i;
				box_pos[box_count][1] = j;
				++box_count;
			} else if(board[i][j] == 'X') value[i][j] = x_count++;
		}
		assert(row <= 40 && col <= 40);
		assert(x_count == box_count && box_count <= 15);
		int limit = 1 << x_count;
		FOR(i, box_count) FOR(j, limit) dp[i][j] = 1 << 20;
		FOR(i, box_count){
			FOR(j, x_count) cost[i][j] = 1 << 20;
			bfs(i);
		}
		FOR(i, box_count) FOR(j, limit){
			if(__builtin_popcount(j) == i+1){
				FOR(k, x_count) if(j & (1 << k))
					dp[i][j] = std::min(dp[i][j], (i ? dp[i - 1][j - (1 << k)] : 0) + cost[i][k]);
			}
		}
		printf("%d\n", dp[box_count - 1][limit - 1]);
	}
	return 0;
}

