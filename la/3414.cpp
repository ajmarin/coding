#include <cstdio>
#include <cstring>

#define FOR(i,n)	for(int i = 0; i < n; ++i)
#define INV(x,y)	(x < 0 || x >= GSZ || y < 0 || y >= GSZ)

const int GSZ = 45;
int dx[6] = {0, 1, 1, 0, -1, -1};
int dy[6] = {1, 0, -1, -1, 0, 1};
int map[128];
bool played[5][GSZ][GSZ];
int fcnt, ncnt;

struct tile {
	char c[8];
	bool e, f, ctrl;
	int x, y;
} g[GSZ][GSZ], hand[5], placed[32];

int count_neighbours(int x, int y){
	int cnt = 0;
	FOR(dir, 6){
		int nx = x + dx[dir], ny = y + dy[dir];
		if(INV(nx, ny)) continue;
		cnt += !g[nx][ny].e;
	}
	return cnt;
}
void mark_controlled(int x, int y, int dir){
	FOR(i, GSZ){
		int nx = x + i * dx[dir], ny = y + i * dy[dir];
		if(INV(nx, ny)) continue;
		g[nx][ny].ctrl = true;
	}
}
bool is_stuck(int x, int y){
	if(!g[x][y].e) return false;
	if(count_neighbours(x, y) != 3) return false;
	int ccnt[4] = {0, 0, 0, 0};
	FOR(dir, 6){
		int nx = x + dx[dir], ny = y + dy[dir];
		if(INV(nx, ny)) continue;
		if(!g[nx][ny].e && ++ccnt[map[g[nx][ny].c[(dir + 3) % 6]]] == 3) return true;
	}
	return false;
}
void mark_if_forced(int x, int y){
	if(!g[x][y].e) return;
	int cnt = count_neighbours(x, y);
	if(cnt == 3){ // forced
		g[x][y].f = true;
		FOR(dir, 6){ // mark lines as controlled
			int nx = x + dx[dir], ny = y + dy[dir];
			if(INV(nx, ny)) continue;
			int nx2 = x + dx[(dir + 2) % 6], ny2 = y + dy[(dir + 2) % 6];
			int nx4 = x + dx[(dir + 4) % 6], ny4 = y + dy[(dir + 4) % 6];
			if(!INV(nx2, ny2) && !g[nx][ny].e && !g[nx2][ny2].e)
				mark_controlled(x + dx[(dir + 3) % 6], y + dy[(dir + 3) % 6], (dir + 3) % 6);
			if(!INV(nx4, ny4) && !g[nx][ny].e && !g[nx4][ny4].e)
				mark_controlled(x + dx[(dir + 3) % 6], y + dy[(dir + 3) % 6], (dir + 3) % 6);
		}
	}
}

bool forced_impossible(int x, int y){
	int cnt = count_neighbours(x, y);
	if(cnt == 3){ // its forced
		int ccnt[4] = {0, 0, 0, 0};
		FOR(dir, 6){
			int nx = x + dx[dir], ny = y + dy[dir];
			if(!INV(nx, ny) && !g[nx][ny].e){
				if(++ccnt[map[g[nx][ny].c[(dir + 3) % 6]]] == 3) return true;
			}
		}
	}
	return false;
}

void try_connect(int hidx, int x, int y){
	if(played[hidx][x][y]) return;
	played[hidx][x][y] = true;
	tile &t = hand[hidx];
	if(!g[x][y].e || g[x][y].ctrl) return;
	int poss = 0;
	g[x][y].e = false;
	FOR(offset, 6){
		bool can = true;
		int cnt = 0;
		FOR(i, 6) g[x][y].c[i] = t.c[(i + offset) % 6];
		FOR(dir, 6){
			if(!can) break;
			int nx = x + dx[dir], ny = y + dy[dir];
			if(INV(nx, ny)) continue;
			if(!g[nx][ny].e){
				++cnt;
				can &= g[nx][ny].c[(dir + 3) % 6] == t.c[(dir + offset) % 6];
			} else can &= !forced_impossible(nx, ny);
		}
		poss += can && cnt > 0;
	}
	if(g[x][y].f) fcnt += poss;
	else ncnt += poss;
	g[x][y].e = true;
}

int main(void){
	int T; scanf("%d", &T);
	FOR(i, 128) map[i] = 0;
	map['B'] = 0; map['G'] = 1; map['R'] = 2; map['Y'] = 3;
	for(int n, x, y; T-- && scanf("%d", &n) == 1; ){
		fcnt = ncnt = 0;
		FOR(i, GSZ) FOR(j, GSZ){
			g[i][j].e = true, g[i][j].f = g[i][j].ctrl = false;
			FOR(k, 5) played[k][i][j] = false;
		}
		FOR(i, n){
			scanf("%d %d", &placed[i].x, &placed[i].y);
			x = placed[i].x += 20;
			y = placed[i].y += 20;
			scanf("%s", g[x][y].c);
			strcpy(placed[i].c, g[x][y].c);
			g[x][y].e = false;
		}
		FOR(i, GSZ) FOR(j, GSZ) mark_if_forced(i, j);
		FOR(i, 5) {
			scanf("%s", hand[i].c);
			FOR(j, n) FOR(dir, 6){
				int nx = placed[j].x + dx[dir], ny = placed[j].y + dy[dir];
				if(!INV(nx, ny))
					try_connect(i, nx, ny);
			}
		}
		printf("%d\n", fcnt ? fcnt : ncnt);
	}

	return 0;
}

