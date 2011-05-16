#include <cmath>
#include <cstdio>
const int NN = 10048;
double L[NN], s[NN];
double max(double a, double b){ return a > b ? a : b; }
double min(double a, double b){ return a < b ? a : b; }
double sqr(double x){ return x * x; }
double dist(double xm, double ym){ return sqrt(sqr(xm/1000) + sqr(ym/1000)); }
int main(void){
	int n, t; scanf("%d", &t);
	while(t--){
		double a, b, c, f, l, mid, r, tt, vmax, x, y;
		scanf("%lf %lf %lf %lf", &a, &b, &vmax, &f);
		scanf("%d", &n);
		for(int i = 0; i < n; ++i){
			scanf("%lf %lf", &x, &y);
			s[i] = b * y / x;
			L[i] = dist(x, y);
		}
		l = 0; r = vmax;
		for(int i = 0; i < 40; ++i){
			c = 0, mid = (l + r) / 2.0;
			for(int j = 0; j < n; ++j) c += max(0, a * mid + s[j]) * L[j];
			if(c > f) r = mid; else l = mid;
		}
		if(l){
			tt = 0;
			for(int i = 0; i < n; ++i){
				double v = l;
				if(a * v + s[i] < 0) v = min(vmax, - s[i] / a);
				tt += L[i] / v;
			}
			printf("%.6lf\n", tt);
		} else puts("IMPOSSIBLE");
	}
	return 0;
}

