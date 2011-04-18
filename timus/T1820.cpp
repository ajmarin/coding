#include <cstdio>

int main(void){
	for(int n, k; scanf("%d %d", &n, &k) == 2; ){
		if(k >= n){
			puts("2");
		} else {
			printf("%d\n", (2 * n + k - 1) / k);
		}
	}
	return 0;
}

