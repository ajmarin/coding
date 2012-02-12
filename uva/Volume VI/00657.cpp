#include <cstdio>

#define VALID(x,y) (x >= 0 && y >= 0 && x < r && y < c)
#define FOR(i,n) for(int i = 0; i < n; ++i)
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

int c, r;
char b[64][64];
bool v[64][64];
int g[64][64], gs[1 << 12], p[1 << 12];

void dfs(int x, int y, int z){
	int nx, ny;
	v[x][y] = true;
	if(b[x][y] == 'X') p[g[x][y]] = z;
	else g[x][y] = z;
	FOR(d, 4){
		nx = x + dx[d], ny = y + dy[d];
		if(VALID(nx, ny) && b[nx][ny] != '.' && !v[nx][ny]) dfs(nx, ny, z);
	}
}

void dfsx(int x, int y, int z){
	int nx, ny;
	g[x][y] = z;
	for(int d = 0; d < 4; ++d){
		nx = x + dx[d], ny = y + dy[d];
		if(VALID(nx, ny) && b[nx][ny] == 'X' && g[nx][ny] == -1) dfsx(nx, ny, z);
	}
}

int main(void){
	for(int tn(0); scanf("%d %d", &c, &r) == 2 && (r | c); ){
		int anum(0), xnum(0), threw[8] = {-1, 0, 0, 0, 0, 0, 0, -1}, tt = 0;
		printf("Throw %d\n", ++tn);
		FOR(i, r){
			scanf("%s", b[i]);
			FOR(j, c){
				v[i][j] = false;
				g[i][j] = -1;
			}
		}
		FOR(i, r) FOR(j, c) if(b[i][j] == 'X' && g[i][j] == -1) dfsx(i, j, xnum), p[xnum++] = -1;
		FOR(i, r) FOR(j, c) if(b[i][j] == '*' && g[i][j] == -1) dfs(i, j, anum), gs[anum++] = 0;
		FOR(i, xnum){
			if(p[i] >= 0) ++gs[p[i]];
			else ++threw[1], ++tt;
		}
		FOR(i, anum) ++threw[gs[i]];
		anum += tt;
		for(int i = 1; i < 7; ++i) while(threw[i]--) printf("%d%c", i, --anum ? 32 : 10);
		puts("");
	}
	return 0;
}

