#include <algorithm>
#include <cstdio>
using namespace std;

#define FOR(i,n)	for(int i = 0; i < n; ++i)
#define FORI(i,s,n)	for(int i = s; i < n; ++i)
int r[256][256];

int main(void){
	for(int ds(0), n, w; scanf("%d %d", &n, &w) == 2 && n; ){
		FOR(i, 256) FOR(j, 256) r[i][j] = 0;
		FOR(i, n){
			int color;
			int a, b, c, d;
			scanf("%d %d %d %d %d", &color, &a, &b, &c, &d);
			a += 100;
			b += 100;
			c += 100;
			d += 100;
			int xl = min(a, c), xr = max(a, c);
			int yb = min(b, d), yt = max(b, d);
			FORI(x, xl, xr) FORI(y, yb, yt)
				r[x][y] = color;
		}
		int ans = 0;
		FOR(i, 256) FOR(j, 256) ans += r[i][j] == w;
		printf("The area of color %d in dataset %d is: %d\n", w, ++ds, ans);


	}
	return 0;
}

