#include <cstdio>
int main(void){
	for(int c = 0, n; scanf("%d", &n) == 1 && n > 0; ){
		int ans = !!(n & (n - 1));
		while(n > 1) ++ans, n >>= 1;
		printf("Case %d: %d\n", ++c, ans);
	}
	return 0;
}

