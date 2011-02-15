#include <cstdio>

int main(void){
	int n, t; scanf("%d", &t);
	while(t--){
		int ans = 0;
		scanf("%d", &n);
		while(n) ans += n /= 5;
		printf("%d\n", ans);
	}
	return 0;
}