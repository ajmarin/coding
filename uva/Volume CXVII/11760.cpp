#include <cstdio>

#define RMAX 10000
int p[2000][2];
bool dl[RMAX], dc[RMAX], ok;
int c, cnum = 0, n, r, x, y;
int d[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
inline bool safe(int x, int y){
	return (x < RMAX && x > -1 && y > -1 && y < RMAX) && !(dl[x] || dc[y]);
}
int main(void){
	for(int i = 0; i < 10003; ++i) dl[i] = dc[i] = 0;
	while(scanf("%d %d %d", &r, &c, &n) && r){
		for(int i = 0; i < n; ++i){
			scanf("%d %d", &x, &y);
			p[i][0] = x; p[i][1] = y;
			dl[x] = 1; dc[y] = 1;
		}
		scanf("%d %d", &x, &y);
		printf("Case %d: ", ++cnum);
		ok = safe(x, y);
		for(int dir = 0; dir < 4; ++dir) ok |= safe(x + d[dir][0], y + d[dir][1]);
		if(ok) puts("Escaped again! More 2D grid problems!");
		else puts("Party time! Let's find a restaurant!");
		for(int i = 0; i < n; ++i)
			dl[p[i][0]] = dc[p[i][1]] = 0;
	}
	return 0;
}
