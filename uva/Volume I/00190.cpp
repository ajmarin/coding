/////////////////////////////////
// 00190 - Circle Through Three Points
/////////////////////////////////
#include<cstdio>
#include<cmath>
#define PI 3.141592653589793
double abscx,abscy,cx,cy,xa,xb,xc,ya,yb,yc,s1,s2,s3,r;
char sig1, sig2, sig3;
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
		r = sqrt(s1);
		if(cx < 0) sig1 = '+';
		else sig1 = '-';
		if(cy < 0) sig2 = '+';
		else sig2 = '-';
		if((cx*cx + cy*cy) < (r*r)) sig3 = '-';
		else sig3 = '+';
		abscx = fabs(cx);
		abscy = fabs(cy);
		if(abscx > 0.000001 && abscy > 0.000001){
			printf("(x %c %.3lf)^2 + (y %c %.3lf)^2 = %.3lf^2\n",sig1,fabs(cx),sig2,fabs(cy),r);
			printf("x^2 + y^2 %c %.3lfx %c %.3lfy %c %.3lf = 0\n\n",sig1,fabs(2*cx),sig2,fabs(2*cy),sig3,fabs(cx*cx+cy*cy-r*r));
		} else if(abscx > 0.000001){
			printf("(x %c %.3lf)^2 + y^2 = %.3lf^2\n",sig1,fabs(cx),r);
			printf("x^2 + y^2 %c %.3lfx %c %.3lf = 0\n\n",sig1,fabs(2*cx),sig3,fabs(cx*cx-r*r));
		} else if(abscy > 0.000001){
			printf("x^2 + (y %c %.3lf)^2 = %.3lf^2\n",sig2,fabs(cy),r);
			printf("x^2 + y^2 %c %.3lfy %c %.3lf = 0\n\n",sig2,fabs(2*cy),sig3,fabs(cy*cy-r*r));
		} else {
			printf("x^2 + y^2 = %.3lf^2\n",r);
			printf("x^2 + y^2 - %.3lf = 0\n\n",fabs(r*r));
		}
	}
}
