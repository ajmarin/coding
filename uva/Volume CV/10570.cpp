#include <cstdio>

#define FOR(i,n) for(int i = 0; i < n; ++i)
int n, v[512], z[512];

int min(int a, int b){ return a < b ? a : b; }
int count_swaps(){
	int cnt = 0, t;
	FOR(i, n) while(z[i] != i){
		t = z[i];
		z[i] = z[t];
		z[t] = t;
		++cnt;
	}
	return cnt;
}
int main(void){
	while(scanf("%d", &n) == 1 && n){
		int ans = 1 << 30;
		FOR(i, n) scanf("%d", v + i), --v[i];
		FOR(i, n){ // consider all positions the first position
			FOR(j, n) z[j] = v[(i + j) % n];
			ans = min(ans, count_swaps());
			FOR(j, n) z[j] = v[(i + n - j) % n];
			ans = min(ans, count_swaps());
		}
		printf("%d\n", ans);
	}
	return 0;
}

