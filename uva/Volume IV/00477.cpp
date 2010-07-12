/////////////////////////////////
// 00477 - Points in Figures: Rectangles and Circles
/////////////////////////////////
#include<cstdio>
#include<cmath>
typedef struct {
	char type;
	double x1,x2,y1,y2,r;
} figure;
figure *f[10];
int ct = 0,pn =0,i,n = 0;
double px,py;
char tipo;
int main(void){
	while(scanf("%c ",&tipo)){
		if(tipo == '*') break;
		f[n] = new figure;
		if(tipo == 'r')scanf("%lf %lf %lf %lf\n",&f[n]->x1,&f[n]->y1,&f[n]->x2,&f[n]->y2);
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
			else {
				double a = px - f[i]->x1, b = py - f[i]->y1;
				if((a*a+b*b) < f[i]->r*f[i]->r){
					printf("Point %d is contained in figure %d\n",pn,i+1);
					ct = 1;
				}
			}
		}
		if(!ct) printf("Point %d is not contained in any figure\n",pn);
	}
}
