#include <cstdio>

long long int ans[128];
int main(void){
	ans[0] = 1; ans[1] = 1;
	for(int i = 2; i < 81; ++i) ans[i] = ans[i - 1] + ans[i - 2];
	for(int n; scanf("%d", &n) == 1 && n; printf("%lld\n", ans[n]));
	return 0;
}

