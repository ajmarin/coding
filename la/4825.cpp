#include <cstdio>

int main(void){
	for(int n, s; scanf("%d %d", &n, &s) == 2; ) printf("%d\n", s / (n + 1));
	return 0;
}

