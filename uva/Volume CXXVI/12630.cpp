#include <cstdio>

int main(void){
	for(int n; scanf("%d", &n) == 1 && n; printf("%d\n", (n + 2) * (n + 1) * n * (n - 1) / 24));
	return 0;
}

