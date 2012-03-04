#include <cstdio>
int v[128];
int main(void){
	int ans = 0, n, l; scanf("%d %d", &n, &l);
	for(int i = 0; i < n; ++i) scanf("%d", &v[i]);
	for(int i = l; i < 101; ++i){
		int c = 0;
		for(int j = 0; j < n; ++j)
			c += v[j] / i;
		if(c * i > ans) ans = c * i;
		if(!c) break;
	}
	printf("%d\n", ans);
	return 0;
}
