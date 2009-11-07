#include <cstdio>
#include <cmath>

#define EPS 1E-10
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

double sqr(double x){ return (x*x);}
int main(void){
	double L, K, T1, T2, H, Hmin, Hmax, Tf1, Tf2, TT;
	int N;
	scanf("%d",&N);
	while(N--){
		scanf("%lf %lf %lf %lf %lf",&L,&K,&T1,&T2,&H);
		TT = T1+T2;
		Hmin = Hmax = H;
		if(H >= L){
			double b = K * TT + H;
			double delta = sqr(b) - 4*T1*K*L;
			//printf("b = %.5lf, delta = %.5lf\n",b,delta);
			if(delta >= 0.){
				double root = sqrt(delta);
				double x1 = (b + root)/(2*T1);
				double x2 = (b - root)/(2*T1);
				Hmax = T1 * x1;
			}
			if(H > L) Hmin = Hmax;
		}
		printf("%.6lf %.6lf\n",Hmin,Hmax);
	}
	return 0;
}

