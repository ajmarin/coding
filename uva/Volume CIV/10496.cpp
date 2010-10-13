#include <cstdio>
#include <cstdlib>

#define FOR(a,b) for(int a = 0; a < b; ++a)
#define GETS(v) (v >> 20)
#define GETX(v) ((v & 0xF8000) >> 15)
#define GETY(v) ((v & 0x07C00) >> 10)
#define GETB(v) ((v & 0x003FF))
bool beeper[32][32], v[32][32][1024];
int bidx[32][32];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int q[1000000];
int main(void){
	bool end;
	int ans, b, head, s, t, tail, x, y; scanf("%d", &t);
	for(int maxx, maxy, n, sx, sy; t--;){
		scanf("%d %d %d %d %d", &maxx, &maxy, &sx, &sy, &n);
		FOR(i, maxx + 1) FOR(j, maxy + 1){
			beeper[i][j] = 0;
			FOR(k, 1024) v[i][j][k] = 0;
		}
		FOR(i, n) scanf("%d %d", &x, &y), beeper[x][y] = 1, bidx[x][y] = i;
		end = head = tail = 0;
		q[tail++] = (sx << 15) + (sy << 10);
		v[sx][sy][0] = 1;
		while(head != tail){
			int k = q[head++];
		 	b = GETB(k); s = GETS(k);
			x = GETX(k); y = GETY(k);
#ifdef DBG
			printf("(%d, %d, %d) [%d]\n", x, y, b, s);
#endif
			b |= (beeper[x][y] << bidx[x][y]);
			if(b == (1 << n) - 1){
				end = 1;
				ans = s + abs(x - sx) + abs(y - sy);
			}
			if(end) break;
			FOR(dir, 4){
				int nx = x + dx[dir], ny = y + dy[dir];
				if(nx <= 0 || ny <= 0 || nx > maxx || ny > maxy) continue;
				if(!v[nx][ny][b]){
					v[nx][ny][b] = 1;
					q[tail++] = ((s + 1) << 20) | (nx << 15) | (ny << 10) | b;
				}
			}
		}
		printf("The shortest path has length %d\n", ans);
	}
	return 0;
}

