/////////////////////////////////
// 10509 - R U Kidding Mr. Feynman!
/////////////////////////////////
#include<cstdio>
#include<cmath>
#define EPS 1e-6
double dx,n, div = 1.0/3;
int a;
int main(void){
	while(scanf("%lf",&n) && n){
		a = pow(n+EPS,div);
		dx = (n-a*a*a)/(3*a*a);
		printf("%.4lf\n",dx+a);
	}
	return 0;
}

