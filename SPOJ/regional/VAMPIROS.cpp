#include<cstdio>
#include<cmath>
double ev1,ev2,at,d,p,res;
int main(void){
	double p;
	scanf("%d",&ev1);
	while(ev1){
		scanf("%lf %lf %lf", &ev2,&at,&d);
		ev1 = ceil(ev1/d);
		ev2 = ceil(ev2/d);
		d = 1;		
		p = at/6;
		if(at == 3) res = ev1/(ev1+ev2);
		else res = (1 - pow((1-p)/p,ev1)) / (1 -  pow((1-p)/p,ev1+ev2));
		printf("%.1lf\n",res*100);
		scanf("%lf",&ev1);
	}
}
