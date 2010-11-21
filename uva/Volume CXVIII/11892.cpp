#include <cstdio>

const char *ans[2] = {"piloop", "poopi"};
int main(void){
	int c, i, n, t, x; scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(c = i = 0; i < n; ++i) scanf("%d", &x), c += x == 1;
		puts(ans[n - c || c & 1]);
	}
	return 0;
}

