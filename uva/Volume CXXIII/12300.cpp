#include <cmath>
#include <cstdio>

const double pi = acos(-1);
int sqr(int x){ return x * x; }
int main(void){
	for(int n, x1, x2, y1, y2; scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &n) == 5 && n; ){
		double dist = sqrt(sqr(x2 - x1) + sqr(y2 - y1)), R;
		if(n & 1){
			double ang = (n / 2) * 2 * pi / n;
			R = dist * sin((pi - ang)/2) / sin(ang);
		} else R = 0.5 * dist;
		printf("%.6lf\n", R * R * sin(2*pi/n) * n / 2);
	}
	return 0;
}

