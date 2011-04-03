#include <cstdio>

int main(void){
	for(int m, n; scanf("%d %d", &n, &m) == 2; )
		if(n <= m) printf("%u\n", (n << 1) - 2);
		else printf("%u\n", (m << 1) - 1);
	return 0;
}

