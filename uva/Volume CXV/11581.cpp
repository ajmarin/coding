#include <cstdio>

#define FOR(i,n) for(int i = 0; i < n; ++i)
#define VALID(x,y) (x >= 0 && y >= 0 && x < 3 && y < 3)
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

int g[3][3], ng[3][3], p[512];

int main(void){
	for(int t = 1; --t || scanf("%d", &t) == 1; ){
		FOR(i, 3) FOR(j, 3) scanf("%1d", &g[i][j]);
		int z = -1, ok = true;
		while(ok){
			ok = false;
			FOR(i, 3) FOR(j, 3) ok |= g[i][j];
			if(!ok) break;
			++z;
			FOR(i, 3) FOR(j, 3){
				ng[i][j] = 0;
				FOR(dir, 4){
					int ni = i + dx[dir], nj = j + dy[dir];
					if(VALID(ni, nj)) ng[i][j] ^= g[ni][nj];
				}
			}
			FOR(i, 3) FOR(j, 3){
				ok |= ng[i][j];
				g[i][j] = ng[i][j];
			}
		}
		printf("%d\n", z);
	}
	return 0;
}

