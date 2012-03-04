#include <cstdio>
#define FOR(i,e)		for(int i = 0; i < e; ++i)
char piece[4];
int rx, ry, kx, ky;
int abs(int a){ return a < 0 ? -a : a; }
bool ok(int x, int y){
	int dx = abs(x - kx), dy = abs(y - ky);
	if(abs(dx - dy) == 1 && dx + dy == 3) return false;
	dx = abs(x - rx), dy = abs(y - ry);
	if(abs(dx - dy) == 1 && dx + dy == 3) return false;
	return x != rx && y != ry && (x != kx || y != ky);
}
int main(void){
	int ans = 0;
	scanf("%s", piece); rx = piece[0] - 'a', ry = piece[1] - '1';
	scanf("%s", piece); kx = piece[0] - 'a', ky = piece[1] - '1';
	FOR(i,8) FOR(j,8) ans += ok(i,j);
	printf("%d\n", ans);
	return 0;
}
