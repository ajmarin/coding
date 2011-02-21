#include <cstdio>
int main(void){
	for(int a, b; scanf("%d %d", &a, &b) == 2 && (a > -1 || b > -1); )
		printf("%d+%d%s%d\n", a, b, a == 1 || b == 1 ? "=" : "!=", a + b);
	return 0;
}

