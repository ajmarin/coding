#include <algorithm>
#include <cstdio>
using namespace std;
#define FORI(a,b,c) for(int a = b; a < c; ++a)
#define FOR(a,b) FORI(a,0,b)
#define N 1048
int c[N][N], m[N][N], r[N][N], maxx, maxy;
int main(void){
	int d, ians, jans, maxsum, n, q, t, x, y;
	for(scanf("%d", &t); t-- && scanf("%d %d", &d, &n); ){
		maxsum = maxx = maxy = 0;
		FOR(i, N) FOR(j, N) c[i][j] = m[i][j] = r[i][j] = 0;
		for(int i = 0; i < n; ++i){
			scanf("%d %d %d", &x, &y, &q);
			m[++x][++y] = q;
			c[y][x] = r[x][y] = q;
			if(x > maxx) maxx = x;
			if(y > maxy) maxy = y;
		}
		++maxx; ++maxy;
		FORI(i, 1, maxx)
			FORI(j, 1, maxy){
				m[i][j] += m[i - 1][j - 1] + r[i][j - 1] + c[j][i - 1];
				r[i][j] += r[i][j - 1];
				c[j][i] += c[j][i - 1];
			}
		FORI(i, 1, maxx) FORI(j, 1, maxy){
			int x1 = max(i - d, 1), y1 = max(j - d, 1);
			int x2 = min(maxx - 1, i + d), y2 = min(maxy - 1, j + d);
			int sum = m[x2][y2] - m[x1 - 1][y2] - m[x2][y1 - 1] + m[x1 - 1][y1 - 1];
			if(sum > maxsum) maxsum = sum, ians = i, jans = j;
		}
		printf("%d %d %d\n", ians - 1, jans - 1, maxsum);
	}
	return 0;
}

