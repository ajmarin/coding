#include <cstdio>

int main(void){
	int v[64];
	for(int k, n; scanf("%d %d", &n, &k) == 2; ){
		int ans = 0;
		for(int i = 0; i < n; ++i) scanf("%d", v + i);
		for(int i = 0; i < n; ++i) ans += v[i] && v[i] >= v[k - 1];
		printf("%d\n",ans);
	}
	return 0;
}
