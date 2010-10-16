#include <cstdio>

#define FOR(a,b)	for(int a = 0; a < b; ++a)
#define FORD(a,b,c)	for(int a = b; a > c; --a)
#define FORI(a,b,c)	for(int a = b; a < c; ++a)

int v[128][128];
int min(int x, int y){ return x < y ? x : y; }
int max(int x, int y){ return x > y ? x : y; }
int main(void){
	for(int m, n; scanf("%d %d", &m, &n) == 2 && (m || n); ){
		FOR(i, m) FOR(j, n) scanf("%d", &v[i][j]);
		FOR(i, m) {
			int cnt = 0;
			FORD(j, n - 1, -1){
				if(v[i][j]) v[i][j] = cnt = 0;
				else cnt += !v[i][j],v[i][j] = cnt;
			}
		}
		int area, maxarea = 0, minr;
		FOR(i, m) FOR(j, n)
			if(v[i][j]){
				minr = v[i][j];
				FORI(k, i, m){
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

