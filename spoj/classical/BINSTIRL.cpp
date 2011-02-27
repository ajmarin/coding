#include <cstdio>
int main(void){
	int m, n, t;
	for(scanf("%d", &t); t-- && scanf("%d %d", &n, &m); )
		printf("%d\n", 0 == ((n - m) & ((m - 1) >> 1)));
	return 0;
}

