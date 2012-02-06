#include <cstdio>
#include <cstring>

#define LEGAL(x,y) (x >= 0 && y >= 0 && x < 8 && y < 8)
// Pawn moves
const int pdx[2] = {1, 1};
const int Pdx[2] = {-1, -1};
const int pdy[2] = {-1, 1};
// Rook moves
const int rdx[4] = {-1, 0, 1, 0};
const int rdy[4] = {0, -1, 0, 1};
// Queen/King moves
const int qkdx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int qkdy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
// Bishop moves
const int bdx[4] = {-1, -1, 1, 1};
const int bdy[4] = {1, -1, -1, 1};
// Knight moves
const int ndx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int ndy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

char attacked[8][8], board[8][8];

void do_moves(int x, int y, const int *dx, const int *dy, int n, int ind){
	//printf("[%d, %d] %c __ %d, %d -- %d\n", x, y, board[x][y], n, ind, (ind << 3) | !ind);
	for(int i = 0; i < n; ++i){
		for(int j = 1; j <= ((ind << 3) | !ind); ++j){
			int nx = x + dx[i] * j, ny = y + dy[i] * j;
			if(LEGAL(nx,ny) && !board[nx][ny]){
				//printf("%c attacks [%d, %d]\n", board[x][y], nx, ny);
				attacked[nx][ny] = board[x][y];
			}
			else break;
		}
	}
}

void show_board(char b[8][8]){ for(int i = 0; i < 8; puts(""), ++i) for(int j = 0; j < 8; ++j) putc(b[i][j]?b[i][j]:'.', stdout); puts("------------"); }
int main(void){
	for(char state[256]; scanf("%s", state) == 1; ){
		int pos = 0;
		memset(board, 0, 64);
		memset(attacked, 0, 64);
		for(int i = 0; state[i]; ++i){
			if(state[i] > '0' && state[i] < '9') pos += state[i] - '0';
			else if(state[i] != '/') board[pos / 8][pos % 8] = state[i], ++pos;
		}
		//show_board(board);
		for(int i = 0; i < 8; ++i) for(int j = 0; j < 8; ++j){
			switch(board[i][j]){
				case 'b': case 'B': do_moves(i, j, bdx, bdy, 4, 1); break;
				case 'k': case 'K': do_moves(i, j, qkdx, qkdy, 8, 0); break;
				case 'n': case 'N': do_moves(i, j, ndx, ndy, 8, 0); break;
				case 'P': do_moves(i, j, Pdx, pdy, 2, 0); break;
				case 'p': do_moves(i, j, pdx, pdy, 2, 0); break;
				case 'q': case 'Q': do_moves(i, j, qkdx, qkdy, 8, 1); break;
				case 'r': case 'R': do_moves(i, j, rdx, rdy, 4, 1); break;
			}
		}
		//show_board(attacked);
		int ans = 0;
		for(int i = 0; i < 8; ++i) for(int j = 0; j < 8; ++j) 
			if(!board[i][j] && !attacked[i][j]) ++ans;
		printf("%d\n", ans);
	}
	
	return 0;
}
