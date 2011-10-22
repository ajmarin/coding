#include <cstdio>

#define FOR(i,n)	for(int i = 0; i < n; ++i)
const char *md = "ensw";
char path[32];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
int nd[4][2] = { {1, 2}, {0, 3}, {0, 3}, {1, 2} };
int bx[64], by[64], px[32], py[32];
int blocked, found, steps;

int min(int a, int b){ return a < b ? a : b; }
int max(int a, int b){ return a > b ? a : b; }
bool between(int v, int a, int b){
	return v >= min(a, b) && v <= max(a, b);
}
bool free(int x, int y, int nx, int ny){
	if(x == nx) FOR(i, blocked) if(bx[i] == x && between(by[i], y, ny)) return false;
	if(y == ny) FOR(i, blocked) if(by[i] == y && between(bx[i], x, nx)) return false;
	return true;
}
bool notbeenin(int x, int y, int s){
	FOR(i, s) if(px[i] == x && py[i] == y) return false;
	return true;
}

void bt(int step_n, int x, int y, int dir){
	if(step_n == steps){
		if(x == y && !x){
			++found;
			puts(path);
		}
		return;
	}
	int mul = step_n + 1, next, nx, ny;
	FOR(i, 2){
		next = nd[dir][i];
		nx = x + mul * dx[next];
		ny = y + mul * dy[next];
		if(free(x, y, nx, ny) && notbeenin(nx, ny, step_n)){
			path[step_n] = md[next];
			px[step_n] = nx;
			py[step_n] = ny;
			bt(mul, nx, ny, next);
		}
	}
}
int main(void){
	int t; scanf("%d", &t);
	while(t-- && scanf("%d%d", &steps, &blocked) == 2){
		FOR(i, blocked) scanf("%d%d", bx + i, by + i);
		found = path[steps] = 0;
		FOR(i, 4){
			path[0] = md[i];
			px[0] = dx[i];
			py[0] = dy[i];
			bt(1, dx[i], dy[i], i);
		}
		printf("Found %d golygon(s).\n\n", found);
	}
	return 0;
}

