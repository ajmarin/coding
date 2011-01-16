/////////////////////////////////
// 00579 - ClockHands
/////////////////////////////////
#include<cstdio>
int a,b;
float res;
int main(void){
	scanf("%d:%d",&a,&b);
	while(a){
		a%=12;
		res = 30*a-5.5*b;
		if(res < 0) res = -res;
		if(res > 180) res = 360-res;
		printf("%.3lf\n",res);
		scanf("%d:%d",&a,&b);
	}
}