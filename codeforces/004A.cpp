#include <cstdio>

int main(void){
	int n; scanf("%d", &n);
	puts(n < 3 || n & 1 ? "NO" : "YES");
	return 0;
}

