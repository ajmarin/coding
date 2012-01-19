#include <cstdio>
#include <cmath>


const double PI = acos(-1);
const double EPS = 1e-5;

bool cmp(double a, double b){
	return fabs(a - b) > EPS;
}

int main(void){
	double total_mat, area;
	double R, T, thickness, x0, y0, xp, yp, x, y;
	for(int n; scanf("%d", &n) == 1 && n; ){
		total_mat = 0;
		for(int i = 0; i < n; ++i){
			scanf("%lf%lf%lf", &thickness, &x0, &y0);
			area = 0;
			xp = x0; yp = y0;
			while(scanf("%lf%lf", &x, &y) == 2){
				area += xp * y - yp * x;
				xp = x; yp = y;
				if(!(cmp(x, x0) || cmp(y, y0))) break;
			}
			total_mat += fabs(area) * thickness;
		}
		scanf("%lf%lf", &R, &T);
		printf("%.0lf\n", floor(total_mat / (2 * PI * R * R * T)));
	}
	return 0;
}

