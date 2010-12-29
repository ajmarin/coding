#include <cmath>
#include <cstdio>
#include <ctime>

int sqr(int x){ return (x * x); }
bool is_square(unsigned x){	return sqr(sqrt(x + .5)) == x; }

int main(void){
	clock_t ini = clock();
	int a, ans, b, c = 0, L;
	for(a = 1; ; ++a){
		L = a << 1;
		for(b = 2; b <= L; ++b){
			if(!((a * b) % 12) && is_square(a * a + b * b)) 
				c += b >= a ? a + 1 - ((b + 1) >> 1) : b >> 1;
		}
		if(c > 1000000){ ans = a; break; }
	}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}
