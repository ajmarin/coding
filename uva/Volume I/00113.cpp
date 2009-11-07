/////////////////////////////////
// 00113 - Power of Cryptography
/////////////////////////////////
#include<cstdio>
#include<cmath>
double a,b;
int main(void){
	while(scanf("%lf %lf",&a,&b)!=EOF)
		printf("%.0lf\n",exp(log(b)/a));
	return 0;
}
