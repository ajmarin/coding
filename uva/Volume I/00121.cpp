/////////////////////////////////
// 00121 - Pipe Fitters
/////////////////////////////////
#include<cstdio>
#include<cmath>
#define MAX(a,b) (a>b?a:b)
#define EPS 1e-6
float a,b,conv;
int c1,c2,d,grid, skew, skew1, skew2;
int getskew(float a, float b){
	c1 = (int)floor(a);
	d = (int)(1+floor((b-1)/(sqrt(3)/2)));
	if(a-c1 >= 0.5) c2 = c1;
	else c2 = c1-1;
	if(d%2) return (d/2)*(c1+c2)+c1;
	else return (d/2)*(c1+c2);
}
int main(void){
	conv = 2/sqrt(3);
	while(scanf("%f %f",&a,&b)!=EOF){
		grid = (int)(floor(a)*floor(b));
		skew1 = getskew(a,b);
		skew2 = getskew(b,a);
		skew = MAX(skew1,skew2);
		if(skew > grid) printf("%u skew\n",skew);
		else printf("%u grid\n",grid);
	}
	return 0;
}
	
