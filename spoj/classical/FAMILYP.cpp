#include <cmath>
#include <cstdio>
int main(void){
	for(int n, t; scanf("%d", &n) == 1; ){
		t = ceil(sqrt(1 + (n<<3)) / 2 - .5);
		printf("TERM %d is %c\n", n, ('A' + (t-1) % 26));
	}
	return 0;
}

