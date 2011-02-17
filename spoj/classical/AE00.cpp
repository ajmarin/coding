#include <cstdio>

int ans[10048];
int main(void){
	ans[0] = 0;
	for(int i = 1; i < 10001; ++i){
		ans[i] = ans[i - 1];
		for(int j = 1; j * j <= i; ++j) ans[i] += !(i % j);
	}
	for(int n; scanf("%d", &n) == 1; printf("%d\n", ans[n]));
	return 0;
}

