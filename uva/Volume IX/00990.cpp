#include <algorithm>
#include <cstdio>
using namespace std;
#define FOR(a,b)  for(int a = 0; a < b; ++a)
#define FORD(a,b,c)  for(int a = b; a > c; --a)
#define FORI(a,b,c)  for(int a = b; a < c; ++a)
struct frac { int d, n; } f[64];
int tl[64], x[64];
bool cmp(int x, int y){
	int v1 = f[x].n * f[y].d, v2 = f[y].n * f[x].d;
	return v1 < v2 || (v1 == v2 && x < y);
}
int main(void){
	for(int c = 0, n, t, w; scanf("%d %d %d", &t, &w, &n) == 3; ++c){
		int m = 0, tkn = 0, ts = 0; w = w + (w << 1);
		FOR(i, n) scanf("%d %d", &f[i].n, &f[i].d), x[i] = i;
		sort(x, x + n, cmp);
		FOR(i, n){
			int k = w * f[x[i]].n;
			if(ts + k > t) continue;
			ts += k;
			tl[tkn++] = x[i];
			m += f[x[i]].d;
		}
		if(c) putc(10, stdout);
		printf("%d\n%d\n", m, tkn);
		FOR(i, tkn){
			int z = tl[i];
			printf("%d %d\n", f[z].n, f[z].d);
		}
	}
	return 0;
}

