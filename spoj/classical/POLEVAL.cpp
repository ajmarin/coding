#include <cstdio>

int c[1024];
int main(void){
	for(int cn = 1, k, n, x; scanf("%d", &n) && n != -1; ++cn){
		for(int i = n+1; i--; ) scanf("%d", c + i);
		printf("Case %d:\n", cn);
		scanf("%d", &k);
		for(int i = 0; i < k; ++i){
			scanf("%d", &x);
			long long r = c[0], y = x;
			for(int j = 0; j++ < n; y *= x) r += y * c[j];
			printf("%lld\n", r);
		}
	}
	return 0;
}


