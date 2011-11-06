#include <cstdio>

int main(void){
	for(int n; scanf("%d", &n) == 1 && n; puts(n & (n + 1) ? "Alice" : "Bob"));
	return 0;
}

