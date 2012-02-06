#include <cstdio>
#include <cstring>

#define VALID(x,y) (x >= 0 && y >= 0 && x < 8 && y < 8)
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

char board[8][8];

void put_pieces(int king, int queen){
	board[king / 8][king % 8] = 'K';
	board[queen / 8][queen % 8] = 'Q';
}

void calculate_moves(int king, int queen){
	int kx = king / 8, ky = king % 8, qx = queen / 8, qy = queen % 8;
	for(int i = 0; i < 4; ++i){
		int nkx = kx + dx[i], nky = ky + dy[i];
		if(VALID(nkx, nky) && board[nkx][nky] != 'Q') board[nkx][nky] = 'k';
	}
	for(int i = 0; i < 4; ++i){
		for(int j = 1; ; ++j){
			int nqx = qx + dx[i] * j, nqy = qy + dy[i] * j;
			if(VALID(nqx, nqy) && board[nqx][nqy] != 'K'){
				if(board[nqx][nqy] == 'k') board[nqx][nqy] = '_';
				else board[nqx][nqy] = 'q';
			} else break;
		}
	}
	for(int i = 0; i < 8; puts(""), ++i) for(int j = 0; j < 8; ++j) putc(board[i][j] ? board[i][j] : '.', stdout);
		
}
int main(void){
	for(int k, q, qm; scanf("%d%d%d", &k, &q, &qm) == 3; ){
		if(k == q){ puts("Illegal state"); continue; }
		memset(board, 0, 64);
		put_pieces(k, q);
		calculate_moves(k, q);
		if(board[qm / 8][qm % 8] == '_') puts("Move not allowed");
		else if(board[qm / 8][qm % 8] != 'q') puts("Illegal move");
		else {
			memset(board, 0, 64);
			put_pieces(k, qm);
			calculate_moves(k, qm);
			int king_moves = 0;
			for(int i = 0; i < 8; ++i) for(int j = 0; j < 8; ++j)
				king_moves += board[i][j] == 'k';
			puts(king_moves > 0 ? "Continue" : "Stop");
		}
	}
	return 0;
}
