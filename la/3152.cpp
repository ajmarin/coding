#include <cstdio>
#include <cmath>
#include <algorithm>
#define EPS 1e-5
struct Ball {
	double x, y;
	int plr, n;
	Ball(double a, double b, int c, int nmbr): x(a),y(b),plr(c),n(nmbr){}
	Ball(){}
} b[7], col[6], start;
char n[3][32] = {"\0","\0","COUCHE\0"};
bool colinear(Ball a, Ball b, Ball c){
	if(b.x - a.x > EPS && b.x - c.x > EPS) return 0;
	if(a.x - b.x > EPS && c.x - b.x > EPS) return 0;
	if(b.y - a.y > EPS && b.y - c.y > EPS) return 0;
	if(a.y - b.y > EPS && c.y - b.y > EPS) return 0;
	return (fabs((b.x-a.x)*(c.y-b.y) - (b.y-a.y)*(c.x-b.x)) < EPS);
}
double sqdist(Ball a, Ball b){
	double x = b.x - a.x;
	double y = b.y - a.y;
	return (x*x+y*y);
}
bool closerToStart(Ball a, Ball b){
	return EPS < sqdist(b,start) - sqdist(a,start);
};
int main (void){
	int cnum, couche, cplr, i, j, col_num, x, y, ang, dist, thrown[2];
	double sin_table[361], cos_table[361], min_dist;
	double conv = acos(-1)/180;
	bool dbg = 0;
	for(i = 0; i < 361; i++) sin_table[i] = sin(i*conv), cos_table[i] = cos(i*conv);
	scanf("%d",&cnum);
	while(cnum--){
		cplr = couche = thrown[0] = thrown[1] = 0;
		scanf("%s%s",n[0],n[1]);
		for(i = 0; i < 7; i++){
			if(i && ++thrown[cplr] > 3) cplr = 1-cplr;
			scanf("%d%d%d%d",&x,&y,&ang,&dist);
			start = Ball(x,y,cplr,0);
			b[i] = Ball(x+cos_table[ang]*dist,y+sin_table[ang]*dist,cplr,i);
			for(col_num = j = 0; j < i; j++)
				if(colinear(start,b[j],b[i]))
					col[col_num++] = Ball(b[j].x,b[j].y,b[j].plr,b[j].n);
			std::sort(col,col+col_num,closerToStart);
			for(j = 0; j < col_num; j++){
				int aux = col[j].plr;
				b[col[j].n].plr = b[i].plr;
				b[i].plr = aux;
			}
			min_dist = 1<<23;
			for(j = 0; j <= i; j++)
				if(b[j].plr == 2){ couche = j; break;}
			for(j = 0; j <= i; j++){
				if(j == couche) continue;
				double temp = sqdist(b[j],b[couche]);
				if(temp < min_dist){
					min_dist = temp;
					cplr = 1 - b[j].plr;
				}
			}
			if(i == 0) b[i].plr = 2;
		}
		for(i = 0; i < 7; i++)
			if(b[i].plr == 2){
				start = Ball(b[i].x,b[i].y,2,0);
				break;
			}
		std::sort(b,b+7,closerToStart);
		if(b[1].plr == 2) std::swap(b[0],b[1]);
		for(i = 2; b[i].plr == b[1].plr; i++);
		printf("%s %d\n",n[b[1].plr],i-1);
	}
	return 0;
}

