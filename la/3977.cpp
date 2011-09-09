#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
#define FOR(i,n)	for(int i = 0; i < n; ++i)
#define VAL(x,y)	((x << 10) + y)
const int NN = 512;
int h[NN][NN], v[NN][NN];
int ans, cols, d, rows;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct point {
	int h, x, y;
	bool operator<(point p) const { return h > p.h; }
} p[NN*NN];
int main(void){
	int T; scanf("%d", &T);
	while(T-- && scanf("%d %d %d", &rows, &cols, &d) == 3){
		ans = 0;
		int lim = rows * cols;
		queue< int > q;
		FOR(i, lim){
			int x = p[i].x = i / cols, y = p[i].y = i % cols;
			scanf("%d", &p[i].h);
			h[x][y] = p[i].h;
			v[x][y] = -1;
		}
		sort(p, p + lim);
		FOR(i, lim){
			int sx = p[i].x, sy = p[i].y;
			if(v[sx][sy] != -1) continue;
			q.push(VAL(sx, sy));

			bool is_summit = true;
			int cnt = 0;
			while(!q.empty()){
				int z = q.front(); q.pop();
				int x = z >> 10, y = z & 0x3FF;
				cnt += h[x][y] == h[sx][sy];
				v[x][y] = h[sx][sy];
				FOR(dir, 4){
					int nx = x + dx[dir], ny = y + dy[dir];
					if(nx < 0 || ny < 0 || nx >= rows || ny >= cols) continue;
					if(h[nx][ny] > h[sx][sy] - d){
						is_summit &= is_summit && v[nx][ny] <= h[sx][sy];
						if(v[nx][ny] == -1){
							v[nx][ny] = h[sx][sy];
							q.push(VAL(nx, ny));
						}
					}
				}
			}
			if(is_summit) ans += cnt;
		}
		printf("%d\n", ans);

	}
	return 0;
}

