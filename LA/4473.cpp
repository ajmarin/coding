#include <cstdio>

#define MAX(a,b) ((a)>(b)?(a):(b))
#define FORI(a,b,c) for(int a = b; a < c; ++a)
#define FOR(a,b) FORI(a,0,b)

int m[128][128][2];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int C, K, N, R;

void attack(int x, int y){
	int current = m[x][y][0];
	int enemy = (current + 1) % N;
	for(int dir = 0; dir < 4; ++dir){
		int nx = x + dx[dir], ny = y + dy[dir];
		if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
		if(m[nx][ny][0] == enemy) m[nx][ny][1] = current;
	}
}
int main(void){
	FOR(i, 128) FOR(j, 128) m[i][j][1] = -1;
	while(scanf("%d %d %d %d",&N,&R,&C,&K)){
		if(!(N || R || C || K)) break;
		FOR(i,R) FOR(j,C) fastint("%d",&m[i][j][0]);
		FOR(k,K) {
			FOR(i,R) FOR(j,C) attack(i,j);
			FOR(i,R) FOR(j,C) {
				if(m[i][j][1] != -1) m[i][j][0] = m[i][j][1];
				m[i][j][1] = -1;
			}
		}
		FOR(i,R){
			FOR(j,C){
				if(j) putc(32, stdout);
				printf("%d",m[i][j][0]);
			}
			putc(10, stdout);
		}
	}
	return 0;
}


