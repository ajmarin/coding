#include <cmath>
#include <cstdio>
const double hhpi = atan(1);
int sqr(int x){ return x * x; }
int main(void){
	int D, L, z; scanf("%d", &z);
	while(scanf("%d %d", &D, &L) == 2)
		printf("%.3lf\n", hhpi * L * sqrt(sqr(L) - sqr(D)));
	return 0;
}

