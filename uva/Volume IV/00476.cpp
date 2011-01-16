/////////////////////////////////
// 00476 - Points in Figures: Rectangles
/////////////////////////////////
#include<cstdio>
#include<cmath>
typedef struct {
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
		scanf("%lf %lf %lf %lf\n",&f[n]->x1,&f[n]->y1,&f[n]->x2,&f[n]->y2);
		n++;
	}
	while(scanf("%lf %lf",&px,&py)!=EOF){
		pn++;
		ct = 0;
		if(px == 9999.9 && py == 9999.9) break;
		for(i = 0; i < n; i++){
			if(px < f[i]->x1 || px > f[i]->x2 || py > f[i]->y1 || py < f[i]->y2)
			else{
				printf("Point %d is contained in figure %d\n",pn,i+1);
				ct = 1;
			}		
		}
		if(!ct) printf("Point %d is not contained in any figure\n",pn);
	}
}
