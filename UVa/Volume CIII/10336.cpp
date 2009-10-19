#include <algorithm>
#include <cstdio>

using namespace std;

#define FORI(a, b, c) for(int a = b; a < c; ++a)
#define FOR(a,b) FORI(a, 0, b)
#define NN 1000

int H, W;
bool v[NN][NN], oc[128];
char c[NN][NN], curr, map[128];
int d, dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};

struct lng {
	int oc; char r;
	bool operator<(const lng x) const {
		return (oc > x.oc) || (oc == x.oc && r < x.r);
	}
} lng[32];

int flood_fill(int x, int y){
	v[x][y] = 1; d++;
	FOR(d, 4){
		int nx = x + dx[d], ny = y + dy[d];
		if(nx < 0 || ny < 0 || nx >= H || ny >= W ||
			v[nx][ny] || c[nx][ny] != curr) continue;
		flood_fill(nx, ny);
	}
}
		
int main(void){
	int w = 1, T, LN;
	scanf("%d",&T);
	while(T--){
		printf("World #%d\n",w++);
		scanf("%d%d\n",&H,&W);
		LN = 0;
		FORI(i, 'a', 'z' + 1) oc[i] = 0;
		FOR(i, H){
			FOR(j, W){
				c[i][j] = getc( stdin );
				v[i][j] = 0;
			}
			getc( stdin );
		}
		FOR(i, H)
			FOR(j, W)
				if(!v[i][j]){
					d = 0;
					if(!oc[c[i][j]]){
						lng[LN].oc = 0;
						oc[c[i][j]] = 1;
						lng[LN].r = c[i][j];
						map[c[i][j]] = LN++;
					}
					curr = c[i][j];
					flood_fill(i, j);
					++lng[map[c[i][j]]].oc;
				}
		sort(lng, lng + LN);
		FOR(i, LN) printf("%c: %d\n", lng[i].r, lng[i].oc);
	}
	return 0;
}


