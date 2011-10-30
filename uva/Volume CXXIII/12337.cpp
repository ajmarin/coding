#include <cstdio>

#define FOR(i,n) for(int i = 0; i < n; ++i)
#define FORI(i,s,n) for(int i = s; i < n; ++i)
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
char b[128];
char ball[128][128];

int min(int a, int b){ return a < b ? a : b; }

bool fill(int r, int c){
	int dir = 0, nx, ny, t = r * c, x = 0, y = -1;
	FOR(i, r) FOR(j, c) ball[i][j] = '.';
	FOR(i, t){
		FOR(test, 4){ // find direction
			nx = x + dx[dir];
			ny = y + dy[dir];
			if(nx < 0 || ny < 0 || nx >= r || ny >= c || ball[nx][ny] != '.')
				dir = (dir + 1) % 4;
			else break;
		}
		ball[x = nx][y = ny] = b[i];
	}
	FOR(j, c) FORI(i, 1, r) if(i && ball[i][j] != ball[i - 1][j]) return false;
	return true;
}

int main(void){
	int t; scanf("%d", &t);
	for(int cnum = 0; t-- && scanf("%s", b) == 1; ){
		int ans = 1000, balls;
		for(balls = 0; b[balls]; ++balls);
		FORI(i, 2, 51) FORI(j, i, 51)
			if(i * j == balls && (fill(i, j) || fill(j, i)))
				ans = min(ans, i + j);
		printf("Case %d: %d\n", ++cnum, ans == 1000 ? -1 : ans);
	}
	return 0;
}

