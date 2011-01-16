/////////////////////////////////
// 10432 - Polygon Inside A Circle
/////////////////////////////////
#include<cstdio>
#include<cmath>
const double PI2 = 4*acos(0);
unsigned int n;
double R;
int main(void){
	while(scanf("%lf %u\n",&R,&n)!=EOF) printf("%.3lf\n",sin(PI2/n)*n*R*R/2);
	return 0;
}
