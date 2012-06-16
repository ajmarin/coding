#include <cstdio>

int main(void){
	for(int a, b, z; scanf("%d %d", &a, &b) == 2 && (a >= 0); ){
		z = (b - a + 100) % 100;
		printf("%d\n", z > 50 ? 100 - z : z);
	}
	return 0;
}

