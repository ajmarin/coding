/////////////////////////////////
// 00478 - Points in Figures: Rectangles, Circles, Triangles
/////////////////////////////////
#include<cstdio>
#include<cmath>
typedef struct {
	char type;
	double x1,x2,y1,y2,x3,y3,r;
} figure;
figure *f[10];
int ct = 0,pn =0,i,n = 0;
double px,py;
char tipo;
double dist(double a,double b, double c,double d){
	return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}
double area(double a, double b, double c){
	double s = (a+b+c)/2;
	return sqrt(s*(s-a)*(s-b)*(s-c));
}
int main(void){
	while(scanf("%c ",&tipo)){
		if(tipo == '*') break;
		f[n] = new figure;
		if(tipo == 'r')
			scanf("%lf %lf %lf %lf\n",&f[n]->x1,&f[n]->y1,&f[n]->x2,&f[n]->y2);
		else if(tipo == 't') 
			scanf("%lf %lf %lf %lf %lf %lf\n",&f[n]->x1,&f[n]->y1,&f[n]->x2,&f[n]->y2,&f[n]->x3,&f[n]->y3);
		else scanf("%lf %lf %lf\n",&f[n]->x1,&f[n]->y1,&f[n]->r);
		f[n++]->type = tipo;
	}
	while(scanf("%lf %lf",&px,&py)!=EOF){
		pn++;
		ct = 0;
		if(px == 9999.9 && py == 9999.9) break;
		for(i = 0; i < n; i++){
			if(f[i]->type == 'r'){
				if(px > f[i]->x1 && px < f[i]->x2){
					if(py < f[i]->y1 && py > f[i]->y2){
						printf("Point %d is contained in figure %d\n",pn,i+1);
						ct = 1;
					}
				}
			}
			else if(f[i]->type == 'c'){
				double a = px - f[i]->x1, b = py - f[i]->y1;
				if((a*a+b*b) < f[i]->r*f[i]->r){
					printf("Point %d is contained in figure %d\n",pn,i+1);
					ct = 1;
				}
			}
			else {
				double x1 = f[i]->x1,x2 = f[i]->x2,x3 = f[i]->x3;
				double y1 = f[i]->y1,y2 = f[i]->y2,y3 = f[i]->y3;
				double A,A1,A2,A3;				
				A = fabs((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1));
				A1 = fabs((px-x1)*(y2-y1)-(py-y1)*(x2-x1));
				A2 = fabs((px-x1)*(y3-y1)-(py-y1)*(x3-x1));
				A3 = fabs((px-x2)*(y3-y2)-(py-y2)*(x3-x2));				
				if((fabs(A-A1-A2-A3)<=0.000001)){
					printf("Point %d is contained in figure %d\n",pn,i+1);
					ct = 1;
				}				
			}
		}
		if(!ct) printf("Point %d is not contained in any figure\n",pn);
	}
}
