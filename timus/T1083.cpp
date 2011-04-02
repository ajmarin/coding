#include <cstdio>
#include <cstring>
int main(void){
	char f[32];
	for(int n; scanf("%d%s", &n, f) == 2; ){
		int r = 1, k = strlen(f);
		while(n > 0) r *= n, n -= k;
		printf("%d\n", r);
	}
	return 0;
}

