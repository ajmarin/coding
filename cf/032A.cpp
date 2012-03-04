#include <cstdio>
int v[1000];
int abs(int a){ return a < 0 ? -a : a; }
int main(void){
	int ans = 0, d, n; scanf("%d %d", &n, &d);
	for(int i = 0; i < n; ++i){
		scanf("%d", &v[i]);
		for(int j = 0; j < i; ++j) if(abs(v[j] - v[i]) <= d) ans += 2;
	}
	printf("%d\n", ans);
	return 0;
}
