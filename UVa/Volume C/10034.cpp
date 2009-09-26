/////////////////////////////////
// 10034 - Freckles
/////////////////////////////////
#include<cstdio>
#include<cmath>
struct P {
	double x,y;
	P() {}
	P(double a, double b): x(a),y(b){}
}pts[100];
unsigned int chosen,cnum,i,pnum,visited;
double tdist,min,mindist[100],temp;
bool v[100];
double dist(P a, P b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void prim(int k){
	v[k] = 1; visited++;
	if(visited == pnum) return;
	min = 200000000.000f;
	for(i = 0; i < pnum; i++)
		if(!v[i]){
			temp = dist(pts[i], pts[k]);
			if(temp < mindist[i]) mindist[i] = temp;
			if(mindist[i] < min) min = mindist[i], chosen = i;
		}
	tdist += min;
	prim(chosen);
}
int main(void){
	scanf("%u",&cnum);
	while(cnum--){
		scanf("%u",&pnum);
		for(visited = tdist = i = 0; i < pnum; i++) 
			scanf("%lf %lf",&pts[i].x,&pts[i].y),
			v[i] = 0, mindist[i] = 200000000.000;
		prim(0);
		printf("%.2lf\n",tdist);
		if(cnum) putchar('\n');
	}
}
