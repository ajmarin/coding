#include <cstdio>
#include <cmath>

int main(void){
	long long B, HALFT, M, P, T, x, y;
	int base, SZ;
	double r;
	while(scanf("%d%lld",&SZ,&P) && SZ){
		long long base = (SZ+1)>>1;
		r = sqrt(P);
		B = floor(r);
		T =	ceil(r);
		if(B == T) B--;
		B *= B;
		B++;
		HALFT = T>>1;
		T *= T;
		M = (B+T)>>1;
		//printf("\t\tP(%lld) B(%lld) T(%lld) M(%lld)\n",P,B,T,M);
		if(T&1){
			if(P > M){
				x = base + HALFT;
				y = base - HALFT + (P-M);
			}
			else {
				x = base + HALFT + (P-M);
				y = base - HALFT;
			}
		} else {
			if(P > M){
				x = base - HALFT;
				y = base + HALFT + (M-P);
			}
			else {
				x = base - HALFT + (M-P);
				y = base + HALFT;
			}
		}
		printf("Line = %lld, column = %lld.\n",y,x);
	}
	return 0;
}

