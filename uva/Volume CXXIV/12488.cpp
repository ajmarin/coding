#include <cstdio>

#define FOR(i,n) for(int i = 0; i < n; ++i)
int a[32], d[32];
int posa[32], posd[32];

int main(void){
	for(int n; scanf("%d", &n) == 1; ){
		FOR(i, n){
			scanf("%d", a + i);
			posa[--a[i]] = i;
		}
		FOR(i, n){
			scanf("%d", d + i);
			posd[--d[i]] = i;
		}
		int ans = 0;
		FOR(i, n) FOR(j, n) ans += posa[j] < posa[i] && posd[j] > posd[i];
		printf("%d\n", ans);
	}
	return 0;
}

