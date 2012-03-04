#include <cstdio>
int c[100048];
int min(int a, int b){ return a < b ? a : b; }
int max(int a, int b){ return a > b ? a : b; }
int main(void){
	int k = 0, d, n, z; 
	while(scanf("%d", &n) == 1){
		k = 0;
		for(int i = 0; i < 100048; ++i) c[i] = 0;
		for(int i = 0; i < n; ++i){
			scanf("%d", &z);
			if((d = z - min(i, n - i - 1)) > 0) k = max(k, ++c[d]);
		}
		printf("%d\n", n - k);
	}
	return 0;
}

