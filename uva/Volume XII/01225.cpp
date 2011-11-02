#include <cstdio>

#define FOR(i,n) for(int i = 0; i < n; ++i)
int ans[16];
int main(void){
	int t; scanf("%d", &t);
	for(int n, z; t-- && scanf("%d", &n) == 1; ){
		FOR(i, 10) ans[i] = 0;
		FOR(i, n){
			z = i + 1;
			while(z) ++ans[z % 10], z /= 10;
		}
		FOR(i, 10) printf("%d%c", ans[i], i == 9 ? 10 : 32);
	}
	return 0;
}

