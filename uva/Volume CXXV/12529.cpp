#include <cstdio>

const int NN = 1024;
const int N = 1, E = 2, S = 4, W = 8;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

#define FOR(i, n) for(int i = 0; i < n; ++i)

int b[NN][NN];
int q[NN * NN];
char block[NN];
bool v[NN][NN];
int c, r;

void bfs(int x, int y){
	int head = 0, tail = 0;
	int nx, ny;
	q[tail++] = (x << 10) | y;
	while(head != tail){
		x = q[head] >> 10;
		y = q[head] & 0x3FF;
		head++;
		for(int dir = 0; dir < 4; ++dir){
			if(!(b[x][y] & (1 << dir))){
				nx = x + dx[dir];
				ny = y + dy[dir];
				if(nx >= 0 && ny >= 0 && nx < r && ny < c && !v[nx][ny]){
					v[nx][ny] = true;
					q[tail++] = (nx << 10) | ny;
				}
			}
		}
	}
}

int main(void){
	for(int n; scanf("%d", &n) == 1; ){
		int k = 2 * n - 1;
		r = n << 1, c = r + 1;
		FOR(i, r) FOR(j, c) b[i][j] = v[i][j] = 0;
		FOR(i, k){
			scanf(" %s", block);
			FOR(j, n){
				int y = ((j + 1) << 1) - !(i & 1);
				if(block[j] == 'H'){
					b[i][y - 1] |= S;
					b[i][y] |= S;
					b[i + 1][y] |= N;
					b[i + 1][y - 1] |= N;
				} else {
					b[i][y] |= W;
					b[i + 1][y] |= W;
					b[i][y - 1] |= E;
					b[i + 1][y - 1] |= E;
				}
			}
		}
		int ans = 0;
		FOR(i, r) FOR(j, c) if(!v[i][j]) ++ans, bfs(i, j);
		printf("%d\n", ans - 1);
	}
	return 0;
}

