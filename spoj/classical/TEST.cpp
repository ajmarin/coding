#include <cstdio>

int main(void){
	for(int n; scanf("%d", &n) == 1 && n != 42; printf("%d\n", n));
	return 0;
}
