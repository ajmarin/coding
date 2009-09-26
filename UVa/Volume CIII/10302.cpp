/////////////////////////////////
// 10302 - Summation of Polynomials
/////////////////////////////////
#include<cstdio>
unsigned long long int n;
int main(void){
	while(scanf("%llu",&n)==1) printf("%llu\n",n*n*(n+1)*(n+1)/4);
	return 0;
}
