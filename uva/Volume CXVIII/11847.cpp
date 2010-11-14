#include <cstdio>
int main(void){
	for(int n; scanf("%d", &n) == 1 && n; ){
		int ans = 0;
		while(n > 1) ++ans, n >>= 1;
		printf("%d\n", ans);
	}
	return 0;
}

