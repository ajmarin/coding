#include <cstdio>

#define FOR(i,n)	for(int i = 0; i < n; ++i)
const int NN = 64;
const char *dd = "NESW";
bool board[NN][NN], v[NN][NN][4];
enum directions { N, E, S, W };
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int main(void){
	int T; scanf("%d", &T);
	for(int n, r; T-- && scanf("%d %d", &n, &r) == 2; ){
		int dir, x, y;
		++n;
		FOR(i, n) FOR(j, n){
			board[i][j] = false;
			FOR(k, 4) v[i][j][k] = false;
		}
		FOR(i, r){
			scanf("%d %d", &x, &y);
			board[x][y] = 1;
		}
		scanf("%d %d", &x, &y);
		if(x == 0) dir = E;
		else if(x == n) dir = W;
		else if(y == 0) dir = N;
		else dir = S;
		while(true){
			v[x][y][dir] = true;
			x += dx[dir];
			y += dy[dir];
			dir = (dir + board[x][y]) % 4;
			if(x < 1 || x >= n || y < 1 || y >= n) break;
			if(v[x][y][dir]){ x = y = 0; break; }
		}
		printf("%d %d\n", x, y);

	}
	return 0;
}

