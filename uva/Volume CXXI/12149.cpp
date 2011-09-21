#include <cstdio>
int main(void){
	for(int n; scanf("%d", &n) == 1 && n; printf("%d\n", (n*(n+1)*(2*n+1))/6));
	return 0;
}

