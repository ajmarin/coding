#include <cstdio>

int main(void){
	scanf("%*d");
	for(int x, y, z; scanf("%d%d%d", &x, &y, &z) == 3; printf("%d\n", z * (2 * x - y) / (x + y)));
	return 0;
}

