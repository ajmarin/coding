#include <cstdio>

#define FOR(a,b)	for(int a = 0; a < b; ++a)
#define FORI(a,b,c)	for(int a = b; a < c; ++a)
#define FORD(a,b,c) for(int a = b; a > c; --a)
int v[2048], lds[2048], lis[2048];
int min(int x, int y){ return x < y ? x : y; }
int max(int x, int y){ return x > y ? x : y; }
int main(void){
	int t; scanf("%d", &t);
	for(int ans, n; t-- && scanf("%d", &n) == 1; ){
		FOR(i, n) scanf("%d", &v[i]), lis[i] = lds[i] = 1;
		FORD(i, n - 1, -1) FORD(j, i - 1, -1)
			if(v[i] > v[j]) lis[j] = max(lis[j], lis[i] + 1);
			else if(v[j] > v[i]) lds[j] = max(lds[j], lds[i] + 1);
		ans = 0;
		FOR(i, n) ans = max(ans, lis[i] + lds[i] - 1);
		printf("%d\n", ans);
	}
	return 0;
}

