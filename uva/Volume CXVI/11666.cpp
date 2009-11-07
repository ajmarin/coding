#include <cstdio>
#include <cmath>

int main(void){
	int L, h, n;
	while(scanf("%d",&n) && n){
		L = 0;
		h = n>>1;
		while(pow(M_E, L) < h) L++;
		printf("%d %.8lf\n",L, 1. - (double)n/pow(M_E,L));
	}
	return 0;
}

