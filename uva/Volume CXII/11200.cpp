#include <cstdio>
#define FOR(i,n)	for(int i = 0; i < n; ++i)
enum { NORTH, EAST, SOUTH, WEST, NDIRS };
const int MAXN = 512;
const int dr[4] = {-1, 0, +1, 0};
const int dc[4] = {0, +1, 0, -1};
const int nd[2][4] = {
	{ // Slash N->W, E->S, S->E, W->N
		WEST, SOUTH,  EAST, NORTH
	},{ // Backslash N->E, E->N, S->W, W->S
		EAST, NORTH, WEST, SOUTH
	}
};
char maze[MAXN][MAXN];
int ans, col, row;
void dfs(int r, int c, int from){
	ans += r == row;
	if(r < 0 || r >= row || c < 0 || c >= col) return;
	int ndir = nd[maze[r][c] == '\\'][from];
	int rdir = (ndir + 2) % NDIRS;
	dfs(r + dr[ndir], c + dc[ndir], rdir);
}
int main(void){
	int t; scanf("%d", &t);
	for(ans = 0; t-- && scanf("%d %d", &col, &row) == 2; ans = 0){
		FOR(i, row) scanf("%s", maze[i]); 
		FOR(j, col) dfs(0, j, NORTH);
		printf("%d\n", ans);
	}
	return 0;
}

