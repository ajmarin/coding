#include <cmath>
#include <cstdio>

double p, q, r, s, t, u;
double f(double x){
	return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

int main(void){
	while(scanf("%lf %lf %lf %lf %lf %lf", &p, &q, &r, &s, &t, &u) == 6){
		double a = 0, b = 1, fa = f(0), fb = f(1), fp, p;
		if(fa * fb <= 0){
			for(;;){
				p = (a + b) / 2;
				fp = f(p);
				if((b - a) / 2 < 1e-9) break;
				if(fa * fp <= 0) fb = fp, b = p;
				else fa = fp, a = p;
			}
			printf("%.4lf\n", p);
		} else puts ("No solution");
	}
	return 0;
}

