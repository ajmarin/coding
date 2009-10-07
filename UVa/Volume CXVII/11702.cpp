#include <cstdio>
#include <cmath>

#define FOR(a,b) for(int a = 0; a < b; ++a)
#define MIN(a,b) ((a)<(b)?(a):(b))
//#define DEBUG

struct point{ int x, y; }p[38];
struct edge { point *a, *b; }e[38];
int N, xp, yp, v, c;
double q(double x){ return (x*x); }
double melt(int a, double d){
	double x = (*e[a].a).x * (1 - d) + (*e[a].b).x * d;
	double y = (*e[a].a).y * (1 - d) + (*e[a].b).y * d;
	double ret = sqrt(q(xp - x) + q(yp - y))/c + y/v;
#ifdef DEBUG
	printf("Called %d, %d, %.5lf, r = %.5lf\n",c,b,d,ret);
#endif
	return ret;
}
void showedge(int n){
	point p1 = *e[n].a, p2 = *e[n].b;
	printf("(%d,%d)-(%d,%d)\n",p1.x,p1.y,p2.x,p2.y);
}
int main(void){
	while(scanf("%d%d%d%d%d",&N,&xp,&yp,&v,&c) && N){
		FOR(i, N) scanf("%d%d",&p[i].x,&p[i].y);
		FOR(i, N) e[i].a = p + i, e[i].b = p + ((i+1)%N);
		double meltdown = 1e17;
		FOR(i, N){
			double left = 0, right = 1;
			FOR(k, 100){
				double L = (2*left + right)/3, R = (left + 2*right)/3;
				if(melt(i, L) < melt(i, R)) right = R;
				else left = L;
			}
			left = melt(i, left);
#ifdef DEBUG
			printf("Edge: "); showedge(i);
			printf("\tleft = %.4lf\n",left);
#endif
			meltdown = MIN(meltdown, left);
		}
		printf("%.4lf\n",meltdown);
	}
	return 0;
}

