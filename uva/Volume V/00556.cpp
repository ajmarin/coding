#include <cstdio>
#define VALID(x,y) (x >= 0 && y >= 0 && x < r && y < c && m[x][y] == '0')
const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {1, 0, -1, 0};

char m[1024][1024];
int vc[1024][1024];

int main(void){
	for(int c, r; scanf("%d %d", &r, &c) == 2 && (r | c); ){
		int dir = 0, sx = r - 1, sy = 0;
		for(int i = 0; i < r; ++i){
			scanf("%s", m[i]);
			for(int j = 0; j < c; ++j) vc[i][j] = 0;
		}
		int x = sx, y = sy;
		do {
			// test if it has a wall to it's right
			int right = (dir + 3) % 4;
			int nx = x + dx[right], ny = y + dy[right];
			if(VALID(nx, ny)) dir = right;
			nx = x + dx[dir], ny = y + dy[dir];
			while(!VALID(nx, ny)){
				dir = (dir + 1) % 4;
				nx = x + dx[dir], ny = y + dy[dir];
			} 
			++vc[nx][ny];
			x = nx, y = ny;
		} while(x != sx || y != sy);
		int cnt[5] = {0, 0, 0, 0, 0};
		for(int i = 0; i < r; ++i) for(int j = 0; j < c; ++j)
			if(m[i][j] == '0') ++cnt[vc[i][j]];
		for(int i = 0; i < 5; ++i) printf("%3d", cnt[i]);
		puts("");
	}
	return 0;
}

