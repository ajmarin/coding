#include <cstdio>

char game[3][8];

bool test(char a, char b, char c, char t){
	return (a == t && b == a && c == b);
}
int count_wins(char c){
	int wins = 0;
	/* Columns */
	wins += test(game[0][0], game[1][0], game[2][0], c);
	wins += test(game[0][1], game[1][1], game[2][1], c);
	wins += test(game[0][2], game[1][2], game[2][2], c);
	/* Lines */
	wins += test(game[0][0], game[0][1], game[0][2], c);
	wins += test(game[1][0], game[1][1], game[1][2], c);
	wins += test(game[2][0], game[2][1], game[2][2], c);
	/* Diagonals */
	wins += test(game[0][0], game[1][1], game[2][2], c);
	wins += test(game[0][2], game[1][1], game[2][0], c);
	return wins;
}

int main(void){
	int T;
	for(scanf("%d\n", &T); T--; ){
		int o = 0, x = 0;
		for(int i = 0; i < 3; ++i)
			fgets(game[i], 8, stdin);
		scanf("\n");
		for(int i = 0; i < 3; ++i)
			for(int j = 0; j < 3; ++j){
				x += game[i][j] == 'X';
				o += game[i][j] == 'O';
			}
		if(o > x || x > o+1) puts("no");
		else {
			int x_wins = count_wins('X');
			int o_wins = count_wins('O');
			puts((x_wins && o_wins) || (x_wins && x - o != 1) || (o_wins && o != x) ? "no" : "yes");
		}
	}
	return 0;
}

