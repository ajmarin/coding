#include <cstdio>

int main(void){
	int d, n, t;
	for(scanf("%d", &t); t-- && scanf("%d %d", &d, &n) == 2; ){
		int x = 1; --n;
		for(int i = 1; i < d; n >>= 1, ++i) x = (x << 1) | (n & 1);
		printf("%d\n", x);
	}
	return 0;
}

