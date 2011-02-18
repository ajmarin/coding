#include <cstdio>

int main(void){
	int n; scanf("%d", &n);
	if(n % 10) printf("%d\n%d\n", 1, n % 10);
	else puts("2");
	return 0;
}

