#include <cstdio>

int main(void){
	int W, Y; scanf("%d %d", &Y, &W);
	int n = 7 - (W > Y? W : Y), d = 6;
	if(!(n % 3)) n /= 3, d = 2; d >>= !(n & 1); n >>= !(n & 1);
	printf("%d/%d\n", n, d);
	return 0;
}
	