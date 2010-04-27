#include <cstdio>
#include <cmath>

int main(void){
	int n;
	while(scanf("%d", &n) == 1){
		int ans = --n + (int)log2(n);
		printf("%d\n", ans);
	}
	return 0;
}

