#include <cstdio>

#define VALID(x,y) (x >= 0 && y >= 0 && x < 8 && y < 8)

const int dr[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dc[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

char b[8][16];

inline void change_player(char &p){ p = p == 'B' ? 'W' : 'B'; }

int calc_moves(char p, bool show = false){
	bool first = true;
	int k, moves = 0, nc, nr;
	for(int row = 0; row < 8; ++row){
		for(int col = 0; col < 8; ++col) if(b[row][col] == '-'){
			for(int d = 0; d < 8; ++d){
				for(k = 1; k <= 8; ++k){
					nr = row + k * dr[d];
					nc = col + k * dc[d];
					if(!VALID(nr, nc) || b[nr][nc] == '-' || b[nr][nc] == p)
						break;
				}
				if(VALID(nr, nc) && b[nr][nc] == p && k > 1){
					++moves;
					if(show){
						if(!first) putc(32, stdout);
						printf("(%d,%d)", row + 1, col + 1);
						first = false;
					}
					break;
				}
			}
		}
	}
	if(show){
		if(!moves) puts("No legal move.");
		else puts("");
	}
	return moves;
}

void play(char p, int row, int col){
	int nc, nr;
	b[row][col] = p;
	for(int d = 0; d < 8; ++d){
		for(int k = 1; k <= 8; ++k){
			nr = row + dr[d] * k, nc = col + dc[d] * k;
			if(!VALID(nr, nc) || b[nr][nc] == '-' || b[nr][nc] == p)
				break;
		}
		if(VALID(nr, nc) && b[nr][nc] == p){
			int od = (d + 4) % 8;
			while(nr != row || nc != col) b[nr = nr + dr[od]][nc = nc + dc[od]] = p;
		}
	}
	int black = 0, white = 0;
	for(int i = 0; i < 8; ++i) for(int j = 0; j < 8; ++j){
		black += b[i][j] == 'B';
		white += b[i][j] == 'W';
	}
	printf("Black - %2d White - %2d\n", black, white);
}
int main(void){
	int t; scanf("%d", &t);
	for(char player[8]; t--; ){
		for(int i = 0; i < 8; ++i) scanf("%s", b[i]);
		scanf("%s", player);
		for(char cmd[8]; scanf("%s", cmd) && *cmd != 'Q'; ){
			if(*cmd == 'L') calc_moves(*player, true);
			else if(*cmd == 'M'){
				if(!calc_moves(*player)) change_player(*player);
				play(*player, cmd[1] - '0' - 1, cmd[2] - '0' - 1);
				change_player(*player);
			}

		}
		for(int i = 0; i < 8; ++i) puts(b[i]);
		if(t) puts("");
	}
	return 0;
}

