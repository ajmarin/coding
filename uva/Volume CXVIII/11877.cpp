#include <cstdio>
int main(void){
	for(int n; scanf("%d", &n) == 1 && n; printf("%d\n", n >> 1));
	return 0;
}

