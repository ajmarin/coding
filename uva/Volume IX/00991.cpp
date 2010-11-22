#include <cstdio>

int catalan[10] = {1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796};
int main(void){
	for(int n, p = 0; scanf("%d", &n) == 1; ){
		if(p++) putc(10, stdout);
		printf("%d\n", catalan[n - 1]);
	}
	return 0;
}

