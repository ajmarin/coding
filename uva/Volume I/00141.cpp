#include <cstdio>
#include <cstring>

#define FOR(i,n) for(int i = 0; i < n; ++i)

int board[64][64], n, state_counter;
struct game_state {
	long long int z[64];
	bool operator==(const game_state& gs){
		FOR(i, n) if(z[i] != gs.z[i]) return false;
		return true;
	}
} gs[1 << 10];

void clear_board(){
	state_counter = 0;
	FOR(i, n) FOR(j, n) board[i][j] = 0;
}

void rotate_board(){
	int copy[64][64];
	FOR(i, n) FOR(j, n) copy[j][n - i - 1] = board[i][j];
	memcpy(board, copy, 1 << 14);
}

bool save_state(){
	int first_state = state_counter;
	long long int k;
	FOR(i, 4){
		FOR(x, n){
			k = 0;
			FOR(y, n) if(board[x][y]) k |= 1LL << y;
			gs[state_counter].z[x] = k;
		}
		FOR(j, first_state) if(gs[state_counter] == gs[j]) return false;
		rotate_board();
		++state_counter;
	}
	return true;
}


int main(void){
	while(scanf("%d", &n) == 1 && n){
		char play[4];
		int move = -1, x, y;
		clear_board();
		save_state();
		FOR(i, n<<1){
			scanf("%d %d %s", &x, &y, play);
			board[--x][--y] = *play == '+';
			if(move == -1 && !save_state()) move = i;
		}
		if(move != -1) printf("Player %d wins on move %d\n", 2 - (move & 1), move + 1);
		else puts("Draw");
	}
	return 0;
}

