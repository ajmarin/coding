
#include <cstdio>

#define FOR(a,b)	for(int a = 0; a < b; ++a)
#define FORD(a,b,c)	for(int a = b; a > c; --a)
#define FORI(a,b,c)	for(int a = b; a < c; ++a)

int v[128][128];
int min(int x, int y){ return x < y ? x : y; }
int max(int x, int y){ return x > y ? x : y; }
int main(void){
	int t, x1, x2, y1, y2; scanf("%d", &t);
	for(int b, n; t-- && scanf("%d %d", &n, &b) == 2; ){
		FOR(i, n) FOR(j, n) v[i][j] = 0;
		FOR(i, b){
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			FORI(x, x1 - 1, x2) FORI(y, y1 - 1, y2)
				v[x][y] = 1;
		}
		FOR(i, n) {
			int cnt = 0;
			FORD(j, n - 1, -1){
				if(v[i][j]) v[i][j] = cnt = 0;
				else cnt += !v[i][j],v[i][j] = cnt;
			}
		}
		int area, maxarea = 0, minr;
		FOR(i, n) FOR(j, n)
			if(v[i][j]){
				minr = v[i][j];
				FORI(k, i, n){
					if(!v[k][j]) break;
					minr = min(v[k][j], minr);
					area = minr * (k - i + 1);
					maxarea = max(area, maxarea);
				}
			}
		printf("%d\n", maxarea);
	}
	return 0;
}

