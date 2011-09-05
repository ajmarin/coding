#include <cstdio>

#define FOR(i, n) for(int i = 0; i < n; ++i)
int r[16], c[16], d[32], u[32];
int btr[16], btc[16], btd[32], btu[32];
char m[16][16];
bool solved;
int R, C, D;

void add(int row, int col, int down, int up, int x){
	btr[row] += x;
	btc[col] += x;
	btd[down] += x;
	btu[up] += x;
}
void bt(int v){
	if(solved) return;
	if(v == R * C){
		bool valid = true;
		for(int i = 0; valid && i < R; ++i) valid &= btr[i] == r[i];
		for(int i = 0; valid && i < C; ++i) valid &= btc[i] == c[i];
		for(int i = 0; valid && i < D; ++i){
			valid &= btd[i] == d[i];
			valid &= btu[i] == u[i];
		}
		solved |= valid;
		if(solved){
			FOR(i, R){
				FOR(j, C) putc(m[i][j], stdout);
				puts("");
			}
		}
		return;
	}
	int row = v / C;
	int col = v % C;
	if(col == 0 && row && btr[row-1] != r[row-1]) return;
	if(R - row + btc[col] < c[col]) return;
	int DOWN = row - col + C - 1;
	int UP = row + col;
	if(btr[row] + 1 <= r[row] && btc[col] + 1 <= c[col]
			&& btd[DOWN] + 1 <= d[DOWN] && btu[UP] + 1 <= u[UP]){
		add(row, col, DOWN, UP, 1);
		m[row][col] = '#';
		bt(v + 1);
		if(solved) return;
		add(row, col, DOWN, UP, -1);
		m[row][col] = '-';
	}
	bt(v + 1);
}
int main(void){
	for(int pbox = 0; scanf("%d %d", &R, &C) == 2 && (R || C); ){
		D = R + C - 1;
		FOR(i, R) FOR(j, C) m[i][j] = '-';
		FOR(i, R) scanf("%d", &r[i]), btr[i] = 0;
		FOR(i, C) scanf("%d", &c[i]), btc[i] = 0;
		FOR(i, D) scanf("%d", &d[i]), btd[i] = 0;
		FOR(i, D) scanf("%d", &u[i]), btu[i] = 0;
		solved = false;
		if(pbox) puts("");
		printf("Pizza box %d\n", ++pbox);
		bt(0);
	}
	return 0;
}

