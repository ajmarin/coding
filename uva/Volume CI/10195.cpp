/////////////////////////////////
// 10195 - The Knights Of The Round Table
/////////////////////////////////
#include<cstdio>
#include<cmath>
long double a,b,c,r,s;
int main(void){
	while(scanf("%Lf %Lf %Lf",&a,&b,&c)!=EOF){
		if(a||b||c)
			s = (a+b+c)/2,
			r = sqrt((s-a)*(s-b)*(s-c)/s),
			printf("The radius of the round table is: %.3Lf\n",r);
		else 
			printf("The radius of the round table is: 0.000\n");
	}
	return 0;
}
