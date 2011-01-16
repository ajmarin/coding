/////////////////////////////////
// 00438 - The Circumference of the Circle
/////////////////////////////////
#include<cstdio>
#include<cmath>
#define PI 3.141592653589793
double cx,cy,xa,xb,xc,ya,yb,yc,s1,s2,s3,radius;
bool show = 0;
int main(void){
	while(scanf("%lf %lf %lf %lf %lf %lf",&xa,&ya,&xb,&yb,&xc,&yc)!=EOF){
		if(show) printf("A=(%lf,%lf)\nB=(%lf,%lf)\nC=(%lf,%lf)\n",xa,ya,xb,yb,xc,yc);
		s1 = (xb-xa)*(yb-yc);
		s2 = (xb-xc)*(ya-yb);
		s3 = (ya-yb)*(yb-yc);
		cx = (s1*(xa+xb)/2 + s2*(xb+xc)/2 + s3*(yc-ya)/2)/(s1+s2);
		if(ya-yb != 0)
			cy = ((xb-xa)*(cx - (xa+xb)/2) + (ya+yb)*(ya-yb)/2)/(ya-yb);
		else
			cy = ((xc-xb)*(cx - (xb+xc)/2) + (yb+yc)*(yb-yc)/2)/(yb-yc);
		if(show) printf("%.3lf %.3lf\n",cx,cy);
		s1 = (cx - xa)*(cx-xa) + (cy-ya)*(cy-ya);
		radius = sqrt(s1);
		printf("%.2lf\n",2*PI*radius);
	}
}
