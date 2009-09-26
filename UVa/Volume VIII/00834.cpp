/////////////////////////////////
// 00834 - Continued Fractions
/////////////////////////////////
#include<cstdio>
#include<cmath>
#define EPS 1e-9
unsigned int a,b,k;
int main(void){
	while(scanf("%u %u\n",&a,&b)==2){
		k = a/b;
		printf("[%u",k);
		a -= (k*b);
		if(a){
			a ^= b ^= a ^= b;
			k = a/b;
			printf(";%u",k);
			a -= k*b;
			while(a){
				a ^= b ^= a ^= b;
				k = a/b;
				printf(",%u",k);
				a -= k*b;
			}
		}
		printf("]\n");
	}
	return 0;
}
