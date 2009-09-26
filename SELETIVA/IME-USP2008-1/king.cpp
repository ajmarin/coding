#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

#define INF 128
#define NN 64

int t;
int n, m;
int v[NN][NN][NN][NN];
int m1[NN][NN], m2[NN][NN];
int sx1, sy1, sx2, sy2;
int dx1, dy1, dx2, dy2;

enum { CHAO, PAREDE, BURACO };

int main(void) {
	char c;
	int i, j, k, l;
	scanf("%d", &t);
	while(t-- && scanf("%d %d", &n, &m)) {
		/* init */
		for(i = 0; i < n; i++)
			for(j = 0; j < m; j++)
				for(k = 0; k < n; k++)
					for(l = 0; l < m; l++)
						v[i][j][k][l] = INF;

		/* input */
		for(i = 0; i < n; i++) {
			for(j = 0; j < m; j++) {
				scanf("%c", &c);
				if(c == '.') m1[i][j] = CHAO;
				else if(c == '#') m1[i][j] = PAREDE;
				else if(c == 'R') {
					m1[i][j] = CHAO;
					sx1 = i; sy1 = j;
				} else if(c == 'B') m1[i][j] = BURACO;
				else if(c == 'F') {
					m1[i][j] = CHAO;
					dx1 = i; dy1 = j;
				} else {
					j--;
				}
			}
		}
		for(i = 0; i < n; i++) {
			for(j = 0; j < m; j++) {
				scanf("%c", &c);
				if(c == '.') m2[i][j] = CHAO;
				else if(c == '#') m2[i][j] = PAREDE;
				else if(c == 'R') {
					m2[i][j] = CHAO;
					sx2 = i; sy2 = j;
				} else if(c == 'B') m2[i][j] = BURACO;
				else if(c == 'F') {
					m2[i][j] = CHAO;
					dx2 = i; dy2 = j;
				} else {
					j--;
				}
			}
		}

		/* processa */
		queue< pair< pair<int, int>, pair<int, int> > > q;
		v[sx1][sy1][sx2][sy2] = 0;
		q.push(make_pair(make_pair(sx1, sy1), make_pair(sx2, sy2)));
		while(v[dx1][dy1][dx2][dy2] == INF && !q.empty()) {
			int x1 = q.front().first.first, y1 = q.front().first.second;
			int x2 = q.front().second.first, y2 = q.front().second.second;
			q.pop();
			int nx1, ny1, nx2, ny2;
			if(v[x1][y1][x2][y2] > 50) break;
#define move(dx, dy) \
			if(x1 + dx < n && x1 + dx >= 0 && x2 + dx < n && x2 + dx >= 0 \
					&& y1 + dy < m && y1 + dy >= 0 && y2 + dy < m && y2 + dy >= 0) { \
				if(m1[x1+dx][y1+dy] != BURACO && m2[x2+dx][y2+dy] != BURACO) { \
					if(m1[x1+dx][y1+dy] == PAREDE) nx1 = x1, ny1 = y1; \
					else nx1 = x1 + dx, ny1 = y1 + dy; \
					if(m2[x2+dx][y2+dy] == PAREDE) nx2 = x2, ny2 = y2; \
					else nx2 = x2 + dx, ny2 = y2 + dy; \
					if(v[nx1][ny1][nx2][ny2] == INF) { \
						v[nx1][ny1][nx2][ny2] = v[x1][y1][x2][y2] + 1; \
						q.push(make_pair(make_pair(nx1, ny1), make_pair(nx2, ny2))); \
					} \
				} \
			}
			move(0, +1);
			move(0, -1);
			move(+1, 0);
			move(-1, 0);
		}

		/* output */
		if(v[dx1][dy1][dx2][dy2] == INF) printf("impossivel\n");
		else printf("%d\n", v[dx1][dy1][dx2][dy2]);
	}

	return 0;
}
