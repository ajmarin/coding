/////////////////////////////////
// 10209 - Is This Integration ?
/////////////////////////////////
#include<cstdio>
double a,a1,a2,a3;
int main(void){
	while(scanf("%lf",&a)!=EOF){
		a*=a;
		a1 = 0.315146743627720*a;
		a2 = 0.511299166334351*a;
		a3 = 0.173554090037927*a;
		printf("%.3lf %.3lf %.3lf\n",a1,a2,a3);
	}
	return 0;
}

