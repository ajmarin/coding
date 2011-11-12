#include <cstdio>

long long ans[62];
int main(void){
	ans[1] = ans[2] = ans[3] = 1;
	for(int i = 4; i < 62; ++i)
		ans[i] = ans[i - 1] + ans[i - 2] + ans[i - 3];
	for(int c = 0, n; scanf("%d", &n) == 1 && n; )
		printf("Case %d: %lld\n", ++c, ans[n]);
	return 0;
}

