#include <cmath>
#include <cstdio>
#include <ctime>

int abs(int x){ return x < 0 ? -x : x; }
int primitive_triple(int a, int b, int c){
	int p = a + b  + c, r = 0;
	if(p > 99999999) return 0;
	if(abs(b - a) == 1) r += 100000000 / p;
	r += primitive_triple( a - 2*b + 2*c, 2*a - b + 2*c, 2*a + 2*b + 3*c );
	r += primitive_triple( a + 2*b + 2*c, 2*a + b + 2*c, 2*a + 2*b + 3*c );
	r += primitive_triple( -a + 2*b + 2*c, -2*a + b + 2*c, 2*a + 2*b + 3*c );
	return r;
}
int main(void){
	clock_t ini = clock();
	int ans = primitive_triple(3, 4, 5);
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}
