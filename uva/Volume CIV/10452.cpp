#include <cstdio>

#define FOR(i,n) for(int i = 0; i < n; ++i)
#define MASK(a,b) (((a) << 3) | (b))
#define VALID(x,y) (x > -1 && y > -1 && x < m && y < n)
#define X(z) Y(z >> 3)
#define Y(z) ((z) & 0x7)
int dx[3] = {0, 0, -1}, dy[3] = {-1, 1, 0};
int p[64], q[64], steps[64], v[64];
char path[16][16];
const char *tdir[3] = {"left", "right", "forth"}, *wp = "IEHOVA#";

void trace_path(int mk){
	if(path[X(mk)][Y(mk)] == '@') return;
	trace_path(p[mk]);
	int y = Y(mk), py = Y(p[mk]);
	printf("%s%c", tdir[2*(y == py) + (y > py)], path[X(mk)][y] == '#' ? 10 : 32);
}
int main(void){
	int cn = 1, head, m, mk, n, nx, ny, s, t, tail, x, y;
	setvbuf(stdout, NULL, _IONBF, NULL);
	FOR(i, 64) v[i] = -1;
	for(scanf("%d", &t); t-- && scanf("%d %d", &m, &n) == 2; ++cn){
		while(getc(stdin) != 10);
		FOR(i, m) for(char *p = path[i]; (*p = getc(stdin)) != 10; ++p);
		head = tail = 0;
		FOR(j, n) if(path[m-1][j] == '@'){
			mk = MASK(m-1, j);
			v[q[tail++] = mk] = cn;
			steps[mk] = 0;
			p[mk] = -1;
		}
		for( ; head != tail; ++head){
			s = steps[q[head]], x = X(q[head]), y = Y(q[head]);
			FOR(dir, 3){
				nx = x + dx[dir], ny = y + dy[dir];
				mk = MASK(nx, ny);
				if(VALID(nx, ny) && path[nx][ny] == wp[s] && v[mk] != cn){
					v[q[tail++] = mk] = cn;
					steps[mk] = s + 1;
					p[mk] = q[head];
				}
			}
		}
		FOR(j, n) if(path[0][j] == '#') trace_path(j);
	}
	return 0;
}

